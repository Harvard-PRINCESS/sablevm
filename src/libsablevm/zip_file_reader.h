/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * This source file is part of SableVM.                            *
 *                                                                 *
 * See the file "LICENSE" for the copyright information and for    *
 * the terms and conditions for copying, distribution and          *
 * modification of this source file.                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef SVM_ZIP_FILE_READER_H
#define SVM_ZIP_FILE_READER_H

/* Zip file reader return values. */

#define ZIP_FILE_FOUND 1
#define ZIP_FILE_NOT_FOUND 0
#define ZIP_FILE_ERROR (-1)

/*
 * All these magic values are derived directly from specification
 * of ZIP file format available at
 * http://www.pkware.com/company/standards/appnote/
 */

#define ZIP_COMPRESSION_STORED 0
#define ZIP_COMPRESSION_DEFLATED 8

#define ZIP_LOCAL_FILE_HEADER_SIZE 30
#define ZIP_LOCAL_FILE_MAGIC 0x50, 0x4b, 0x03, 0x04
#define ZIP_LOCAL_FILE_MIN_VER_OFFSET 4
#define ZIP_LOCAL_FILE_BIT_FLAG_OFFSET 6
#define ZIP_LOCAL_FILE_COMPRESSION_OFFSET 8
#define ZIP_LOCAL_FILE_MODIFICATION_TIME_OFFSET 10
#define ZIP_LOCAL_FILE_MODIFICATION_DATE_OFFSET 12
#define ZIP_LOCAL_FILE_CRC32_OFFSET 14
#define ZIP_LOCAL_FILE_COMP_SIZE_OFFSET 18
#define ZIP_LOCAL_FILE_UNCOMP_SIZE_OFFSET 22
#define ZIP_LOCAL_FILE_NAME_LEN_OFFSET 26
#define ZIP_LOCAL_FILE_EXTRA_FLD_LEN_OFFSET 28

#define ZIP_CENTRAL_DIR_ENTRY_SIZE 46
#define ZIP_CENTRAL_DIR_MAGIC 0x50, 0x4b, 0x01, 0x02
#define ZIP_CENTRAL_DIR_VERSION_MADE_BY_OFFSET 4
#define ZIP_CENTRAL_DIR_VERSION_NEEDED_OFFSET 6
#define ZIP_CENTRAL_DIR_FLAGS_OFFSET 8
#define ZIP_CENTRAL_DIR_COMPRESSION_OFFSET 10
#define ZIP_CENTRAL_DIR_MODIFICATION_TIME_OFFSET 12
#define ZIP_CENTRAL_DIR_MODIFICATION_DATE_OFFSET 14
#define ZIP_CENTRAL_DIR_CRC32_OFFSET 16
#define ZIP_CENTRAL_DIR_COMP_SIZE_OFFSET 20
#define ZIP_CENTRAL_DIR_UNCOMP_SIZE_OFFSET 24
#define ZIP_CENTRAL_DIR_FNAME_LEN_OFFSET 28
#define ZIP_CENTRAL_DIR_EXTRA_FLD_LEN_OFFSET 30
#define ZIP_CENTRAL_DIR_FILE_COMMENT_LEN_OFFSET 32
#define ZIP_CENTRAL_DIR_DISK_NUMBER_START_OFFSET 34
#define ZIP_CENTRAL_DIR_INTERNAL_FILE_ATTRIBUTES_OFFSET 36
#define ZIP_CENTRAL_DIR_EXTERNAL_FILE_ATTRIBUTES_OFFSET 38
#define ZIP_CENTRAL_DIR_LOCAL_HEADER_OFFSET_OFFSET 42

#define ZIP_END_CENTRAL_DIR_SIZE 22
#define ZIP_END_CENTRAL_DIR_MAGIC 0x50, 0x4b, 0x05, 0x06
#define ZIP_END_CENTRAL_DIR_DISK_NUMBER_OFFSET 4
#define ZIP_END_CENTRAL_DIR_DISK_NUMBER_START_OFFSET 6
#define ZIP_END_CENTRAL_DIR_NUMBER_OF_ENTRIES_ON_THIS_DISK_OFFSET 8
#define ZIP_END_CENTRAL_DIR_CENTRAL_ENTRIES_NO_OFFSET 10
#define ZIP_END_CENTRAL_DIR_SIZE_CENTRAL_DIR_OFFSET 12
#define ZIP_END_CENTRAL_DIR_CENTRAL_OFFSET 16
#define ZIP_END_CENTRAL_DIR_COMMENT_LENGTH_OFFSET 20

#endif /* #define SVM_ZIP_FILE_READER_H */
