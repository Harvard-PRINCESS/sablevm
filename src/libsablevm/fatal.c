/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * This source file is part of SableVM.                            *
 *                                                                 *
 * See the file "LICENSE" for the copyright information and for    *
 * the terms and conditions for copying, distribution and          *
 * modification of this source file.                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

static const volatile int _svmv_true = 1;

/*
----------------------------------------------------------------------
_svmh_fatal_error
----------------------------------------------------------------------
*/

inline static void
_svmh_fatal_error (const char *filename, const char *funcname,
		   int linenumber, const char *msg)
{
  /* We put a dummy conditional on a volatile variable so that GCC
     don't get too smart and detect that this function never returns.
     (This avoids some portential problems with inline threading,
     specially in presence of incomplete implementation). */

  if (_svmv_true)
    {
      fprintf (stderr, "sablevm: INTERNAL ERROR (source file \"%s\", "
	       "function \"%s\", line %d): %s\n",
	       filename, funcname, linenumber, msg);
      abort ();
    }
}

/*
----------------------------------------------------------------------
_svmf_jni_fatal_error
----------------------------------------------------------------------
*/

static void
_svmf_jni_fatal_error (const char *msg)
{
  fprintf (stderr, "[jni: fatal error (%s)]\n", msg);
  abort ();
}
