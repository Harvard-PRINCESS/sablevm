/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * This source file is part of SableVM.                            *
 *                                                                 *
 * See the file "LICENSE" for the copyright information and for    *
 * the terms and conditions for copying, distribution and          *
 * modification of this source file.                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */


/*
----------------------------------------------------------------------
_svmf_zip_read_value
----------------------------------------------------------------------
*/

svm_static inline _svmt_u32
_svmf_zip_read_value (unsigned char *data, _svmt_u32 offset,
		      jbyte no_of_bytes)
{
  _svmt_u32 result = 0, multiplier = 1;
  jbyte i;

  for (i = 0; i < no_of_bytes; i++)
    {
      result += (_svmt_u32) data[offset + i] * multiplier;
      multiplier *= 0x100;
    };

  return result;
}

/*
----------------------------------------------------------------------
_svmf_zip_check_sig
----------------------------------------------------------------------
*/

svm_static inline jboolean
_svmf_zip_check_sig (unsigned char *data, _svmt_u32 offset, jbyte b0,
		     jbyte b1, jbyte b2, jbyte b3)
{
  return
    ((data[offset] == b0) && (data[offset + 1] == b1) &&
     (data[offset + 2] == b2) && (data[offset + 3] == b3));
}

/*
----------------------------------------------------------------------
_svmf_zip_alloc
_svmf_zip_free
----------------------------------------------------------------------
*/

/*
 * NOTE: These two functions are wrapper for SableVM's allocation
 * functions. They are used by zlib internally, therefore its
 * parameters should be exactly the same types and sizes as in zlib
 * itself.
 */

svm_static void *
_svmf_zip_alloc (void *cookie, unsigned int num, unsigned int size)
{
  _svmt_u8 *ptr;

  if (_svmm_gmalloc_ubytes
      ((_svmt_JNIEnv *) cookie, num * size, ptr) != JNI_OK)
    return NULL;

  return (void *) ptr;
}

svm_static void
_svmf_zip_free (void *cookie SVM_UNUSED, void *mem)
{
  _svmt_u8 *ptr = (_svmt_u8 *) mem;
  _svmm_gmfree_ubytes (ptr);
}

/*
----------------------------------------------------------------------
_svmf_zip_compare_entries
----------------------------------------------------------------------
*/

svm_static int
_svmf_zip_compare_entries (const void *_entry1, const void *_entry2)
{
  _svmt_zip_file_entry *entry1 = (_svmt_zip_file_entry *) _entry1;
  _svmt_zip_file_entry *entry2 = (_svmt_zip_file_entry *) _entry2;

  return strcmp (entry1->name, entry2->name);
}

/*
----------------------------------------------------------------------
_svmf_zip_file_close
----------------------------------------------------------------------
*/

svm_static void
_svmf_zip_file_close (_svmt_JNIEnv *env SVM_UNUSED, _svmt_zip_file * zip_file)
{

  if (zip_file != NULL)
    {
      if (zip_file->fd > 0)
	close (zip_file->fd);
      if (zip_file->name != NULL)
	_svmm_gmfree_cchars (zip_file->name);
      if (zip_file->entries != NULL)
	{
	  int i;
	  for (i = 0; i < zip_file->entries_no; i++)
	    if (zip_file->entries[i].name != NULL)
	      _svmm_gmfree_cchars (zip_file->entries[i].name);
	  _svmm_gzmfree_zip_file_entry (zip_file->entries);
	}
      if (zip_file->content != NULL)
	munmap (zip_file->content, zip_file->file_len);
      _svmm_gzfree_zip_file (zip_file);
    };
}

/*
----------------------------------------------------------------------
_svmf_zip_file_open
----------------------------------------------------------------------
*/

svm_static _svmt_zip_file *
_svmf_zip_file_open (_svmt_JNIEnv *env, const char *file_name)
{
  _svmt_zip_file *zip_file;
  struct stat stats;
  _svmt_u32 entry, position, central_dir_position;

  zip_file = NULL;
  if (_svmm_gzalloc_zip_file (env, zip_file) != JNI_OK)
    goto error;

  if (_svmm_gmalloc_cchars (env, strlen (file_name) + 1, zip_file->name) !=
      JNI_OK)
    goto error;
  strcpy (zip_file->name, file_name);

  /* Open file, get its stats and mmap it. */
  zip_file->fd = open (zip_file->name, O_RDONLY);
  if (zip_file->fd == -1)
    goto error;

  if (fstat (zip_file->fd, &stats) == -1)
    goto error;
  zip_file->file_len = stats.st_size;
  if (zip_file->file_len == 0)
    goto error;

  zip_file->content = (_svmt_u8 *)
    mmap (NULL, zip_file->file_len, PROT_READ, MAP_PRIVATE, zip_file->fd, 0);
  if (zip_file->content == NULL)
    goto error;

  /* Check signature of the first file in archive.  This will help us detect
   * quickly when a file is not a zip file. */
  if (!_svmf_zip_check_sig (zip_file->content, 0, ZIP_LOCAL_FILE_MAGIC))
    goto error;

  /* Go to the directory entry at the end of file.  Unfortunatelly if there is
   * a comment the directory might be earlier so we search backward for its
   * signature. */

  position = zip_file->file_len - ZIP_END_CENTRAL_DIR_SIZE;

  while (position > 0)
    {
      if (_svmf_zip_check_sig
	  (zip_file->content, position, ZIP_END_CENTRAL_DIR_MAGIC))
	{
	  break;
	}
      position--;
    }

  if (position == 0)
    goto error;			/* End central dir sig not found - not a valid zip file. */


  /* Read the central directory. */

  central_dir_position =	/* Offset to start central directory. */
    _svmf_zip_read_value (zip_file->content,
			  position + ZIP_END_CENTRAL_DIR_CENTRAL_OFFSET, 4);

  if (central_dir_position + ZIP_CENTRAL_DIR_ENTRY_SIZE
      >= (_svmt_u32) zip_file->file_len)
    goto error;			/* This would cause segfault otherwise! */

  zip_file->entries_no =	/* Total no. of entries in central directory. */
    _svmf_zip_read_value (zip_file->content, position +
			  ZIP_END_CENTRAL_DIR_CENTRAL_ENTRIES_NO_OFFSET, 2);

  if (_svmm_gzmalloc_zip_file_entry
      (env, zip_file->entries_no, zip_file->entries) != JNI_OK)
    goto error;

  position = central_dir_position;
  for (entry = 0; entry < zip_file->entries_no; entry++)
    {
      jchar field_len;
      if (!_svmf_zip_check_sig
	  (zip_file->content, position, ZIP_CENTRAL_DIR_MAGIC))
	goto error;		/* Central directory file header mismatch. */

      zip_file->entries[entry].compression_method = _svmf_zip_read_value
	(zip_file->content, position + ZIP_CENTRAL_DIR_COMPRESSION_OFFSET, 2);

      zip_file->entries[entry].size_compressed = _svmf_zip_read_value
	(zip_file->content, position + ZIP_CENTRAL_DIR_COMP_SIZE_OFFSET, 4);

      zip_file->entries[entry].size_uncompressed = _svmf_zip_read_value
	(zip_file->content, position + ZIP_CENTRAL_DIR_UNCOMP_SIZE_OFFSET, 4);

      field_len = _svmf_zip_read_value
	(zip_file->content, position + ZIP_CENTRAL_DIR_FNAME_LEN_OFFSET, 2);

      if (field_len == 0)
	goto error;		/* No file name in central directory. */

      if (_svmm_gmalloc_cchars (env, field_len + 1,
				zip_file->entries[entry].name) != JNI_OK)
	goto error;

      if (position + ZIP_CENTRAL_DIR_ENTRY_SIZE + field_len >=
	  (_svmt_u32) zip_file->file_len)
	goto error;		/* Invalid lenght of file name in central directory. */

      strncpy (zip_file->entries[entry].name,
	       (char *) &zip_file->content[position +
					   ZIP_CENTRAL_DIR_ENTRY_SIZE],
	       field_len);
      zip_file->entries[entry].name[field_len] = 0;

      zip_file->entries[entry].local_header_offset =
	_svmf_zip_read_value
	(zip_file->content,
	 position + ZIP_CENTRAL_DIR_LOCAL_HEADER_OFFSET_OFFSET, 4);

      /* Avoid later segfaults. */
      if (zip_file->entries[entry].local_header_offset +
	  ZIP_LOCAL_FILE_HEADER_SIZE >= (_svmt_u32) zip_file->file_len)
	goto error;		/* Damaged file, wrong local header offset. */

      position += ZIP_CENTRAL_DIR_ENTRY_SIZE + field_len +
	_svmf_zip_read_value
	(zip_file->content,
	 position + ZIP_CENTRAL_DIR_EXTRA_FLD_LEN_OFFSET, 2) +
	_svmf_zip_read_value
	(zip_file->content,
	 position + ZIP_CENTRAL_DIR_FILE_COMMENT_LEN_OFFSET, 2);
    }

  /* Sort the entries to use binary search later. */
  qsort ((void *) zip_file->entries, zip_file->entries_no,
	 sizeof (_svmt_zip_file_entry), &_svmf_zip_compare_entries);

  return zip_file;

error:

  _svmf_zip_file_close (env, zip_file);

  return NULL;
}

/*
----------------------------------------------------------------------
_svmf_zip_file_exists
----------------------------------------------------------------------
*/

/* This function returns:
  ZIP_FILE_FOUND - file_name was found and successfuly uncompressed
  ZIP_FILE_NOT_FOUND - file_name was not found in this archive
  ZIP_FILE_ERROR - some runtime error that should not happen:
    - file_name was found but the archive was damaged
    - memory allocation failed
    - other runtime error or unexpected behaviour (for ex. in zlib) occured
 */
svm_static jint
  _svmf_zip_file_exists
  (_svmt_JNIEnv *env SVM_UNUSED, _svmt_zip_file * zip_file,
   const char *file_name)
{
  _svmt_zip_file_entry key_zip_file_entry;

  assert (zip_file != NULL);
  assert (zip_file->fd != 0);
  assert (zip_file->content != NULL);

  key_zip_file_entry.name = (char *) file_name;

  return bsearch (&key_zip_file_entry, zip_file->entries,
		  zip_file->entries_no, sizeof (_svmt_zip_file_entry),
		  &_svmf_zip_compare_entries) != NULL;
}

/*
----------------------------------------------------------------------
_svmf_zip_get_file_content
----------------------------------------------------------------------
*/

/* This function returns:
  ZIP_FILE_FOUND - file_name was found and successfuly uncompressed
  ZIP_FILE_NOT_FOUND - file_name was not found in this archive
  ZIP_FILE_ERROR - some runtime error that should not happen:
    - file_name was found but the archive was damaged
    - memory allocation failed
    - other runtime error or unexpected behaviour (for ex. in zlib) occured
 */
svm_static jint
  _svmf_zip_get_file_content
  (_svmt_JNIEnv *env, _svmt_u8 **file_content, jint *file_length,
   _svmt_zip_file * zip_file, const char *file_name, jboolean *free_after_use)
{
  _svmt_u32 content_position;
  _svmt_zip_file_entry *zip_file_entry, key_zip_file_entry;

  assert (zip_file != NULL);
  assert (zip_file->fd != 0);
  assert (zip_file->content != NULL);
  assert (file_content != NULL);
  assert (file_length != NULL);

  *file_content = NULL;

  /* Check if this file has entry for file_name. */

  key_zip_file_entry.name = (char *) file_name;

  zip_file_entry = (_svmt_zip_file_entry *) bsearch
    (&key_zip_file_entry, zip_file->entries, zip_file->entries_no,
     sizeof (_svmt_zip_file_entry), &_svmf_zip_compare_entries);

  if (zip_file_entry == NULL)
    return ZIP_FILE_NOT_FOUND;

  content_position = zip_file_entry->local_header_offset;

  if (!_svmf_zip_check_sig
      (zip_file->content, content_position, ZIP_LOCAL_FILE_MAGIC))
    goto error;			/* Local file header mismatch. */

  {
    _svmt_u32 data_position;
#ifdef COMMENT
/* 
 * Theorhetically we should require min_ver be <= 2.0 and bit_flags
 * to indicate that file content is not stored using some more advanced
 * methods of compression or encrpyption.  The fact however is that in
 * case our capabilities were not enough to read the file content - we'll
 * find it out very soon, while analyzing further parts of the file.
 */
    jchar min_ver = _svmf_zip_read_value
      (zip_file->content, content_position +
       ZIP_LOCAL_FILE_MIN_VER_OFFSET, 2);
    jchar bit_flag = _svmf_zip_read_value
      (zip_file->content, content_position +
       ZIP_LOCAL_FILE_BIT_FLAG_OFFSET, 2);
#endif

/* 
 * Information about compression method and file sizes might be available
 * in one of two plcaes: either in the central directory or in the local
 * file header. For files that with file size 0 in the central directory,
 * we will try to read them here from the local directory.  If both
 * locations contain invalid data, the sanity checks below will fail.
 */
    if (zip_file_entry->compression_method == 0)
      zip_file_entry->compression_method = _svmf_zip_read_value
	(zip_file->content, content_position +
	 ZIP_LOCAL_FILE_COMPRESSION_OFFSET, 2);

    if (zip_file_entry->size_compressed == 0)
      zip_file_entry->size_compressed = _svmf_zip_read_value
	(zip_file->content, content_position +
	 ZIP_LOCAL_FILE_COMP_SIZE_OFFSET, 4);

    if (zip_file_entry->size_uncompressed == 0)
      zip_file_entry->size_uncompressed = _svmf_zip_read_value
	(zip_file->content, content_position +
	 ZIP_LOCAL_FILE_UNCOMP_SIZE_OFFSET, 4);

    data_position = content_position + ZIP_LOCAL_FILE_HEADER_SIZE +
      _svmf_zip_read_value
      (zip_file->content, content_position +
       ZIP_LOCAL_FILE_NAME_LEN_OFFSET, 2) +
      _svmf_zip_read_value
      (zip_file->content, content_position +
       ZIP_LOCAL_FILE_EXTRA_FLD_LEN_OFFSET, 2);

    /* Avoid segfaults in case of corrupted data in zip file. */
    if ((data_position + zip_file_entry->size_compressed >=
	 zip_file->file_len) || (zip_file_entry->size_compressed == 0))
      goto error;		/* Damaged file, wrong compressed file size. */

    *file_content = NULL;
    *free_after_use = JNI_FALSE;
    *file_length = zip_file_entry->size_uncompressed;

    switch (zip_file_entry->compression_method)
      {
      case ZIP_COMPRESSION_STORED:	/* No compression, just give out the pointer. */
	*free_after_use = JNI_FALSE;
	*file_content = &zip_file->content[data_position];
	break;
      case ZIP_COMPRESSION_DEFLATED:
	{
	  z_stream zip_stream;
	  int res;

	  if (_svmm_gmalloc_ubytes
	      (env, zip_file_entry->size_uncompressed,
	       *file_content) != JNI_OK)
	    goto error;

	  *free_after_use = JNI_TRUE;
	  memset (&zip_stream, 0, sizeof (zip_stream));
	  zip_stream.avail_in = zip_file_entry->size_compressed;
	  zip_stream.next_in = &zip_file->content[data_position];
	  zip_stream.avail_out = zip_file_entry->size_uncompressed;
	  zip_stream.next_out = *file_content;
	  zip_stream.data_type = Z_BINARY;
	  zip_stream.zalloc = &_svmf_zip_alloc;
	  zip_stream.zfree = &_svmf_zip_free;
	  zip_stream.opaque = env;
	  if (inflateInit2 (&zip_stream, -MAX_WBITS) != Z_OK)
	    goto error;

	  /* Zip file is mmapped so we uncompress all the file at once. */
	  res = inflate (&zip_stream, Z_FINISH);

	  switch (res)
	    {
	    case Z_STREAM_END:
	      break;
	    case Z_OK:
	      /* There is a bug in zlib that even though it was given Z_FINISH and actually
	       * has successfuly finished decompression it might return Z_OK instead of
	       * Z_STREAM_END.  In such case we let it read an extra dummy byte and zlib
	       * should return Z_STREAM_END this time. */
	      {
		unsigned char dummy = 0;

		zip_stream.next_in = &dummy;
		zip_stream.avail_in = 1;
		res = inflate (&zip_stream, Z_SYNC_FLUSH);

		if (res == Z_STREAM_END)
		  {
		    inflateEnd (&zip_stream);
		    break;
		  }
	      }
	    default:		/* An error during inflation occured. */
	      inflateEnd (&zip_stream);
	      goto error;
	    }
	  inflateEnd (&zip_stream);

	  if (zip_stream.total_in != zip_file_entry->size_compressed ||
	      zip_stream.total_out != zip_file_entry->size_uncompressed)
	    goto error;		/* Mismatch of data length information. */
	}
	break;
      default:			/* Unsupported compression type. */
	goto error;
      }
  }

  return ZIP_FILE_FOUND;

error:
  if (*file_content != NULL)
    {
      _svmm_gmfree_ubytes (*file_content);
      *file_content = NULL;
    }
  return ZIP_FILE_ERROR;
}
