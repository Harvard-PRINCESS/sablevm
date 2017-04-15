/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * This source file is part of SableVM.                            *
 *                                                                 *
 * See the file "LICENSE" for the copyright information and for    *
 * the terms and conditions for copying, distribution and          *
 * modification of this source file.                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

/* We remember previously established signal handlers, so that we can
   delegate back to them when we don't handle a signal. */
static sigset_t _svmv_old_sigset;

static struct sigaction _svmv_old_sigquit;
static struct sigaction _svmv_old_siginterrupt;

#if defined(_SABLEVM_SIGNALS_FOR_EXCEPTIONS) || defined(_SABLEVM_INLINABILITY_TESTING)

static struct sigaction _svmv_old_sigsegv;
static struct sigaction _svmv_old_sigfpe;

#ifdef _SABLEVM_INLINABILITY_TESTING

static struct sigaction _svmv_old_sigill;
static struct sigaction _svmv_old_sigtrap;
static struct sigaction _svmv_old_sigsys;
static struct sigaction _svmv_old_sigbus;
static struct sigaction _svmv_old_sigxcpu;
static struct sigaction _svmv_old_sigxfsz;

#endif /* _SABLEVM_INLINABILITY_TESTING */

#endif /* _SABLEVM_SIGNALS_FOR_EXCEPTIONS || _SABLEVM_INLINABILITY_TESTING */

/*
----------------------------------------------------------------------
_svmf_initialization_unrecoverable_exception
----------------------------------------------------------------------
*/

svm_static void
_svmf_initialization_unrecoverable_exception (_svmt_JNIEnv *env)
{
  siglongjmp (env->vm->initialization->unrecoverable_exception_handler, 1);
}

/*
----------------------------------------------------------------------
_svmf_signal_throw
----------------------------------------------------------------------
*/

#if defined(_SABLEVM_SIGNALS_FOR_EXCEPTIONS) || defined(_SABLEVM_INLINABILITY_TESTING)

svm_static void
_svmf_signal_throw (_svmt_JNIEnv *env, jint signal_code)
{
  assert (env->signal_code == SVM_SIGNAL_NONE);

  if (env->signal_handler == NULL)
    {
      _svmt_JavaVM *vm = env->vm;

      if (vm->initialization == NULL)
	{
	  return;		/* delegate the signal */
	}

      _svmf_initialization_unrecoverable_exception (env);
    }

  env->signal_code = signal_code;
  siglongjmp (*(env->signal_handler), 1);
}

#endif /* _SABLEVM_SIGNALS_FOR_EXCEPTIONS || _SABLEVM_INLINABILITY_TESTING */

/*
----------------------------------------------------------------------
_svmf_internal_sigaction
----------------------------------------------------------------------
*/

#if defined(_SABLEVM_HAS_SIGINFO)

svm_static void
_svmf_internal_sigaction (int signo, siginfo_t * info, void *ignored)
{
  _svmt_JNIEnv *env;

  /* find the current thread */
  env = _svmf_get_current_env ();

  if (env == NULL)
    {
      /* This thread is not attached to VM, so let's delegate to previous handler, if there was one */
      goto delegate;
    }

#ifdef _SABLEVM_INLINABILITY_TESTING

#ifdef COMMENT
  /* NO PRINTFs in signal handler!!! (but it's sometimes useful ;-) */
  if (!_svmf_no_inlining (env, signo, SVM_IS_INLINED_FROM_SIGHANDLER))
    {
      printf ("expected = %i, signo = %i\n",
	      env->inlinability_testing.sigsegv_expected, signo);
      fflush (NULL);
    }
#endif /* COMMENT */

  /* EG: TODO: Remove preprocessor directives within an expression. */
  if (
#if defined(_SABLEVM_SIGNALS_FOR_EXCEPTIONS)
       (!((env->inlinability_testing.sigsegv_expected)
	  && (signo == SIGSEGV))) &&
#endif
       (signo != SIGFPE)
       && (!_svmf_no_inlining (env, signo, SVM_IS_INLINED_FROM_SIGHANDLER)))
    {
      _svmf_signal_throw (env, SVM_SIGNAL_INLINING_FAILURE);
      return;
    }

#endif /* _SABLEVM_INLINABILITY_TESTING */


  switch (signo)
    {

      /* needed for Thread.interrupt(); */
    case SVM_INTERRUPT_SIGNAL:
      {
	/* do nothing */
      }
      break;

#if defined(_SABLEVM_SIGNALS_FOR_EXCEPTIONS) || defined(_SABLEVM_INLINABILITY_TESTING)

    case SIGSEGV:
      {
	jint status = env->thread_status;

#ifndef NDEBUG

	if (!(env->sigsegv_expected))
	  {
	    _svmm_fatal_error ("unexpected segmentation fault");
	  }
	else
	  {
	    /* reset flag */
	    env->sigsegv_expected = JNI_FALSE;
	  }

#endif /* not NDEBUG */

	if (status == SVM_THREAD_STATUS_NOT_RUNNING_JAVA_RESUMING_ALLOWED ||
	    status == SVM_THREAD_STATUS_NOT_RUNNING_JAVA_RESUMING_DISALLOWED)
	  {
	    volatile _svmt_word *cause_segfault = NULL;
	    _svmf_printf (env, stderr,
			  "** Segfault in native code on thread %d.  Java stack trace follows.\n",
			  env->thread.id);
	    _svmf_dump_stack_trace (env);
	    fflush (NULL);
	    /* Stack trace can be long, let the user know (again) what happened. */
	    _svmf_printf (env, stderr,
			  "** Segfault in native code on thread %d.  Java stack trace done.\n",
			  env->thread.id);
	    /* We force a "real" segfault to get core dump and ease debugging. */
	    *cause_segfault = 0xdeadbeef;
	    _svmm_fatal_error
	      ("Impossible control flow after segmentation fault catch.");
	  }
	else
	  {
	    _svmf_signal_throw (env, SVM_SIGNAL_NULL_POINTER_EXCEPTION);
	  }
	goto delegate;
      }
      break;

    case SIGFPE:
      {
	switch (info->si_code)
	  {
#ifndef __powerpc__
	    /*
	     * Note: Division by zero is undefined on powerpc.
	     *       It does not cause an exception.
	     *
	     * Moreover, the code will not compile on Darwin / OS X
	     * since some of the FPE_* including FPE_INTDIV are undefined.
	     *
	     */

#ifdef __alpha__
	    /* On alpha, for some reason (maybe a Linux kernel bug?) after division
	       by 0 we get value 128 in info->si_code. Apparently there's no
	       #define for this anywhere. */
	  case 128:
#endif

#ifdef __arm__
	    /* On ARM si_code seems to always be 0.
	     * Checked at least with Linux 2.6.8.1. */
	  case 0:
#endif

	  case FPE_INTDIV:
	    {

#ifndef NDEBUG

	      if (!(env->sigfpe_expected))
		{
		  _svmm_fatal_error ("unexpected floating point signal");
		}
	      else
		{
		  env->sigfpe_expected = JNI_FALSE;
		}

#endif /* not NDEBUG */

	      _svmf_signal_throw (env, SVM_SIGNAL_ARITHMETIC_EXCEPTION);
	      goto delegate;
	    }
	    break;

	  case FPE_INTOVF:
	  case FPE_FLTDIV:
	  case FPE_FLTOVF:
	  case FPE_FLTUND:
/* some of these might not be defined for ex. on some *BSD */
#ifdef FPE_FLTRES
	  case FPE_FLTRES:
#endif
#ifdef FPE_FLTINV
	  case FPE_FLTINV:
#endif
#ifdef FPE_FLTSUB
	  case FPE_FLTSUB:
#endif

#endif /* !__powerpc__ */
	  default:
	    {
	      _svmm_fatal_error ("unexpected floating point signal");
	    }
	    break;
	  }
      }
      break;

#endif /* _SABLEVM_SIGNALS_FOR_EXCEPTIONS || _SABLEVM_INLINABILITY_TESTING */

    case SIGQUIT:
      {
	/* Thread dump requested */
	_svmf_dump_stack_trace (env);
      }
      break;

    default:
      {
	/* this signal handler shouldn't be registered to catch these! */
	_svmm_fatal_error ("impossible control flow");
      }
    }

  return;

delegate:
  /* find out if there was another signal handler before we set our own.
     If yes call it. If not, abort (as the process would have core
     dumped, anyway).
     Of course, we don't support ignoring (SIG_IGN) these signals, as it
     would leave us in an ugly infinite loop. */
  switch (signo)
    {

#if defined(_SABLEVM_SIGNALS_FOR_EXCEPTIONS) || defined(_SABLEVM_INLINABILITY_TESTING)

    case SIGSEGV:
      {
	if ((_svmv_old_sigsegv.sa_flags & SA_SIGINFO) != 0)
	  {
	    _svmv_old_sigsegv.sa_sigaction (signo, info, ignored);
	  }
	else if ((_svmv_old_sigsegv.sa_handler != SIG_DFL) &&
		 (_svmv_old_sigsegv.sa_handler != SIG_IGN))
	  {
	    _svmv_old_sigsegv.sa_handler (signo);
	  }
	else
	  {
	    _svmm_fatal_error ("unhandled segmentation fault");
	  }
      }
      break;

    case SIGFPE:
      {
	if ((_svmv_old_sigfpe.sa_flags & SA_SIGINFO) != 0)
	  {
	    _svmv_old_sigfpe.sa_sigaction (signo, info, ignored);
	  }
	else if ((_svmv_old_sigfpe.sa_handler != SIG_DFL) &&
		 (_svmv_old_sigfpe.sa_handler != SIG_IGN))
	  {
	    _svmv_old_sigfpe.sa_handler (signo);
	  }
	else
	  {
	    _svmm_fatal_error ("unhandled floating point signal");
	  }
      }
      break;

#endif /* _SABLEVM_SIGNALS_FOR_EXCEPTIONS || _SABLEVM_INLINABILITY_TESTING */

    case SIGQUIT:
      {
	if ((_svmv_old_sigquit.sa_flags & SA_SIGINFO) != 0)
	  {
	    _svmv_old_sigquit.sa_sigaction (signo, info, ignored);
	  }
	else if ((_svmv_old_sigquit.sa_handler != SIG_DFL) &&
		 (_svmv_old_sigquit.sa_handler != SIG_IGN))
	  {
	    _svmv_old_sigquit.sa_handler (signo);
	  }
	else
	  {
	    _svmm_fatal_error ("unhandled quit signal");
	  }
      }
      break;

    default:
      {
	/* this signal handler shouldn't be registered to catch these! */
	_svmm_fatal_error ("impossible control flow");
      }
      break;
    }
}

#endif /* _SABLEVM_HAS_SIGINFO */

/*
----------------------------------------------------------------------
_svmf_error_init
----------------------------------------------------------------------
*/

svm_static jint
_svmf_error_init (void)
{
  sigset_t svmv_sigset;
  struct sigaction sa;

  /* save old sigmask before doing any modifications */

  if (sigprocmask (0, NULL, &_svmv_old_sigset) != 0)
    {
      goto error;
    }

  _svmm_zero_memory (sa);

  /* mask all signals handled by the signal handler */
  if (sigemptyset (&sa.sa_mask) != 0)
    {
      goto error;
    }

  if (sigaddset (&sa.sa_mask, SIGQUIT) != 0)
    {
      goto error;
    }

  if (sigaddset (&sa.sa_mask, SVM_INTERRUPT_SIGNAL) != 0)
    {
      goto error;
    }

#if defined(_SABLEVM_SIGNALS_FOR_EXCEPTIONS) || defined(_SABLEVM_INLINABILITY_TESTING)

  if (sigaddset (&sa.sa_mask, SIGFPE) != 0)
    {
      goto error;
    }

  if (sigaddset (&sa.sa_mask, SIGSEGV) != 0)
    {
      goto error;
    }

#endif /* _SABLEVM_SIGNALS_FOR_EXCEPTIONS || _SABLEVM_INLINABILITY_TESTING */

#ifdef _SABLEVM_INLINABILITY_TESTING

/* SIGABRT is generated by assert() - don't mess with it! */
/* SIGALRM is not catched because JVM is too messy to continue anyway */

  if (sigaddset (&sa.sa_mask, SIGILL) != 0)
    {
      goto error;
    }

  if (sigaddset (&sa.sa_mask, SIGTRAP) != 0)
    {
      goto error;
    }

  if (sigaddset (&sa.sa_mask, SIGSYS) != 0)
    {
      goto error;
    }

  if (sigaddset (&sa.sa_mask, SIGBUS) != 0)
    {
      goto error;
    }

  if (sigaddset (&sa.sa_mask, SIGXCPU) != 0)
    {
      goto error;
    }

  if (sigaddset (&sa.sa_mask, SIGXFSZ) != 0)
    {
      goto error;
    }

#endif /* _SABLEVM_INLINABILITY_TESTING */

#if defined(_SABLEVM_HAS_SIGINFO)

  /* TODO: add signal support for systems w/o SA_SIGINFO */

  /* use extended info version */
  sa.sa_flags = SA_SIGINFO;
  sa.sa_sigaction = _svmf_internal_sigaction;

  if (sigaction (SIGQUIT, &sa, &_svmv_old_sigquit) != 0)
    {
      goto error;
    }

  if (sigaction (SVM_INTERRUPT_SIGNAL, &sa, &_svmv_old_siginterrupt) != 0)
    {
      goto error;
    }

#if defined(_SABLEVM_SIGNALS_FOR_EXCEPTIONS) || defined(_SABLEVM_INLINABILITY_TESTING)

  if (sigaction (SIGSEGV, &sa, &_svmv_old_sigsegv) != 0)
    {
      goto error;
    }

  if (sigaction (SIGFPE, &sa, &_svmv_old_sigfpe) != 0)
    {
      goto error;
    }

#endif /* _SABLEVM_SIGNALS_FOR_EXCEPTIONS || _SABLEVM_INLINABILITY_TESTING */

#ifdef _SABLEVM_INLINABILITY_TESTING

  if (sigaction (SIGILL, &sa, &_svmv_old_sigill) != 0)
    {
      goto error;
    }

  if (sigaction (SIGTRAP, &sa, &_svmv_old_sigtrap) != 0)
    {
      goto error;
    }

  if (sigaction (SIGSYS, &sa, &_svmv_old_sigsys) != 0)
    {
      goto error;
    }

  if (sigaction (SIGBUS, &sa, &_svmv_old_sigbus) != 0)
    {
      goto error;
    }

  if (sigaction (SIGXCPU, &sa, &_svmv_old_sigxcpu) != 0)
    {
      goto error;
    }

  if (sigaction (SIGXFSZ, &sa, &_svmv_old_sigxfsz) != 0)
    {
      goto error;
    }

#endif /* _SABLEVM_INLINABILITY_TESTING */

#endif /* _SABLEVM_HAS_SIGINFO */

  /* ignore SIGPIPE */

  if (sigemptyset (&svmv_sigset) != 0)
    {
      goto error;
    }

  if (sigaddset (&svmv_sigset, SIGPIPE) != 0)
    {
      goto error;
    }

  if (sigprocmask (SIG_BLOCK, &svmv_sigset, NULL) != 0)
    {
      goto error;
    }

  return JNI_OK;

error:

  return JNI_ERR;
}

/*
----------------------------------------------------------------------
_svmf_error_restore
----------------------------------------------------------------------
*/

/* TODO: call this function from the right place. It's unused currently. */

#ifdef COMMENT

svm_static jint
_svmf_error_restore (void)
{
#if defined(_SABLEVM_HAS_SIGINFO)

  if (sigaction (SIGQUIT, &_svmv_old_sigquit, NULL) != 0)
    {
      goto error;
    }

  if (sigaction (SVM_INTERRUPT_SIGNAL, &_svmv_old_siginterrupt, NULL) != 0)
    {
      goto error;
    }

#if defined(_SABLEVM_SIGNALS_FOR_EXCEPTIONS) || defined(_SABLEVM_INLINABILITY_TESTING)

  if (sigaction (SIGSEGV, &_svmv_old_sigsegv, NULL) != 0)
    {
      goto error;
    }

  if (sigaction (SIGFPE, &_svmv_old_sigfpe, NULL) != 0)
    {
      goto error;
    }

#endif /* _SABLEVM_SIGNALS_FOR_EXCEPTIONS || _SABLEVM_INLINABILITY_TESTING */

#endif /* _SABLEVM_HAS_SIGINFO */

  if (sigprocmask (SIG_SETMASK, &_svmv_old_sigset, NULL) != 0)
    {
      goto error;
    }

  return JNI_OK;

error:

  return JNI_ERR;
}

#endif /* COMMENT */
