/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * This source file is part of SableVM.                            *
 *                                                                 *
 * See the file "LICENSE" for the copyright information and for    *
 * the terms and conditions for copying, distribution and          *
 * modification of this source file.                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <config.h>

#include <popt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <jni.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>

#include "sablevm.h"

/*
----------------------------------------------------------------------
displayFileContent
----------------------------------------------------------------------
*/

static int
displayFileContent (const char *dirname, const char *filename, int newline)
{
  int fd = -1;
  struct stat sb;
  void *region = MAP_FAILED;
  int exit_status = EXIT_SUCCESS;
  char *path = malloc (strlen (dirname) + strlen (filename) + 2);

  if (path == NULL)
    {
      fprintf (stderr, "sablevm: out of memory\n");
      exit_status = EXIT_FAILURE;
      goto cleanup;
    }

  strcpy (path, dirname);
  strcat (path, "/");
  strcat (path, filename);

  if ((fd = open (path, O_RDONLY)) < 0)
    {
      fprintf (stderr, "sablevm: can't open \"%s\"\n", path);
      exit_status = EXIT_FAILURE;
      goto cleanup;
    }

  /* stat the file so we know how much of it to map into memory */
  if (fstat (fd, &sb) < 0)
    {
      fprintf (stderr, "sablevm: can't stat \"%s\"\n", path);
      exit_status = EXIT_FAILURE;
      goto cleanup;
    }

  region = mmap (NULL, sb.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
  if (region == MAP_FAILED)
    {
      fprintf (stderr, "sablevm: can't map \"%s\"\n", path);
      exit_status = EXIT_FAILURE;
      goto cleanup;
    }

  {
    const char *str0 = "---- FILE: ";
    const char *str1 = " ----\n";
    const char *str2 = "---- END OF FILE: ";
    const char *str3 = newline ? " ----\n\n" : " ----\n";

    if (write (1, str0, strlen (str0)) != (ssize_t) strlen (str0)
	|| write (1, filename,
		  strlen (filename)) != (ssize_t) strlen (filename)
	|| write (1, str1, strlen (str1)) != (ssize_t) strlen (str1)
	|| write (1, region, sb.st_size) != sb.st_size
	|| write (1, str2, strlen (str2)) != (ssize_t) strlen (str2)
	|| write (1, filename,
		  strlen (filename)) != (ssize_t) strlen (filename)
	|| write (1, str3, strlen (str3)) != (ssize_t) strlen (str3))
      {
	fprintf (stderr, "sablevm: can't display \"%s\"\n", path);
	exit_status = EXIT_FAILURE;
	goto cleanup;
      }
  }

  if (munmap (region, sb.st_size) != 0)
    {
      fprintf (stderr, "sablevm: can't unmap \"%s\"\n", path);
      exit_status = EXIT_FAILURE;
      goto cleanup;
    }

  region = MAP_FAILED;

  if (close (fd) != 0)
    {
      fprintf (stderr, "sablevm: can't close \"%s\"\n", path);
      exit_status = EXIT_FAILURE;
      goto cleanup;
    }

  fd = -1;

cleanup:

  if (path != NULL)
    {
      free (path);
      path = NULL;
    }

  if (region != MAP_FAILED)
    {
      munmap (region, sb.st_size);
      region = MAP_FAILED;
    }

  if (fd >= 0)
    {
      close (fd);
      fd = -1;
    }

  return exit_status;
}

/*
----------------------------------------------------------------------
getLine
----------------------------------------------------------------------
*/

#define BUFSIZE 1024

static char *
getLine (FILE *file)
{
  char buf[BUFSIZE];
  int len;
  char *line;

  if (fgets (buf, BUFSIZE, file) == NULL)
    {
      return NULL;
    }

  len = strlen (buf);
  line = malloc (len + 1);

  if (line == NULL)
    {
      return NULL;
    }

  strcpy (line, buf);

  while (line[len - 1] != '\n')
    {
      if (fgets (buf, BUFSIZE, file) == NULL)
	{
	  return line;
	}

      {
	int newlen = strlen (buf) + len;
	char *newline = realloc (line, newlen + 1);

	if (newline == NULL)
	  {
	    free (line);
	    return NULL;
	  }

	strcpy (&newline[len], buf);

	line = newline;
	len = newlen;
      }
    }

  line[len - 1] = 0;
  return line;
}

#undef BUFSIZE

/*
----------------------------------------------------------------------
getPropertyAndValue
----------------------------------------------------------------------
*/

static void
getPropertyAndValue (char *line, char **_property, char **_value,
		     int *_append)
{
  char *p = line;
  char *property;
  char *property_end;
  char *value;
  char *value_end;
  int append = 0;
  int stop = 0;

  /* skip white space */
  do
    {
      switch (*p)
	{
	case ' ':
	case '\t':
	  {
	    p++;
	  }
	  break;

	default:
	  {
	    stop = 1;
	  }
	  break;
	}
    }
  while (!stop);

  if (*p == 0 || *p == '#' || *p == '!')
    {
      *_property = NULL;
      *_value = NULL;
      *_append = 0;
      return;
    }

  property = p;

  /* find property end */
  stop = 0;
  property_end = p;
  do
    {
      switch (*p)
	{
	case 0:
	case ' ':
	case '\t':
	case '=':
	case ':':
	  {
	    stop = 1;
	  }
	  break;

	case '\\':
	  {
	    switch (*(p + 1))
	      {
	      case 0:
		{
		  stop = 1;
		}
		break;

	      case ' ':
		{
		  *(property_end++) = ' ';
		  p += 2;
		}
		break;

	      case 't':
		{
		  *(property_end++) = '\t';
		  p += 2;
		}
		break;

	      case '=':
		{
		  *(property_end++) = '=';
		  p += 2;
		}
		break;

	      case ':':
		{
		  *(property_end++) = ':';
		  p += 2;
		}
		break;

	      case 'n':
		{
		  *(property_end++) = '\n';
		  p += 2;
		}
		break;

	      case 'r':
		{
		  *(property_end++) = '\r';
		  p += 2;
		}
		break;

	      case '\\':
		{
		  *(property_end++) = '\\';
		  p += 2;
		}
		break;

	      default:
		{
		  *(property_end++) = *(p++);
		}
	      }
	  }
	  break;

	default:
	  {
	    *(property_end++) = *(p++);
	  }
	  break;
	}
    }
  while (!stop);

  /* skip white space */
  stop = 0;
  do
    {
      switch (*p)
	{
	case ' ':
	case '\t':
	  {
	    p++;
	  }
	  break;

	default:
	  {
	    stop = 1;
	  }
	  break;
	}
    }
  while (!stop);

  if (*p == '=' || *p == ':')
    {
      p++;

      /* skip white space */
      stop = 0;
      do
	{
	  switch (*p)
	    {
	    case ' ':
	    case '\t':
	      {
		p++;
	      }
	      break;

	    default:
	      {
		stop = 1;
	      }
	      break;
	    }
	}
      while (!stop);
    }

  value = p;

  /* find value end */
  stop = 0;
  value_end = p;
  do
    {
      switch (*p)
	{
	case 0:
	  {
	    stop = 1;
	  }
	  break;

	case '\\':
	  {
	    switch (*(p + 1))
	      {
	      case 0:
		{
		  append = 1;
		  stop = 1;
		}
		break;

	      case ' ':
		{
		  *(value_end++) = ' ';
		  p += 2;
		}
		break;

	      case 't':
		{
		  *(value_end++) = '\t';
		  p += 2;
		}
		break;

	      case 'n':
		{
		  *(value_end++) = '\n';
		  p += 2;
		}
		break;

	      case 'r':
		{
		  *(value_end++) = '\r';
		  p += 2;
		}
		break;

	      case '\\':
		{
		  *(value_end++) = '\\';
		  p += 2;
		}
		break;

	      default:
		{
		  *(value_end++) = *(p++);
		}
	      }
	  }
	  break;

	default:
	  {
	    *(value_end++) = *(p++);
	  }
	  break;
	}
    }
  while (!stop);

  *property_end = 0;
  *value_end = 0;

  *_property = property;
  *_value = value;
  *_append = append;
  return;
}

/*
----------------------------------------------------------------------
getValue
----------------------------------------------------------------------
*/

static void
getValue (char *line, char **_value, int *_append)
{
  char *p = line;
  char *value;
  char *value_end;
  int append = 0;
  int stop = 0;

  /* skip white space */
  do
    {
      switch (*p)
	{
	case ' ':
	case '\t':
	  {
	    p++;
	  }
	  break;

	default:
	  {
	    stop = 1;
	  }
	  break;
	}
    }
  while (!stop);

  if (*p == 0 || *p == '#' || *p == '!')
    {
      *_value = NULL;
      *_append = 0;
      return;
    }

  value = p;

  /* find value end */
  stop = 0;
  value_end = p;
  do
    {
      switch (*p)
	{
	case 0:
	  {
	    stop = 1;
	  }
	  break;

	case '\\':
	  {
	    switch (*(p + 1))
	      {
	      case 0:
		{
		  append = 1;
		  stop = 1;
		}
		break;

	      case ' ':
		{
		  *(value_end++) = ' ';
		  p += 2;
		}
		break;

	      case 't':
		{
		  *(value_end++) = '\t';
		  p += 2;
		}
		break;

	      case 'n':
		{
		  *(value_end++) = '\n';
		  p += 2;
		}
		break;

	      case 'r':
		{
		  *(value_end++) = '\r';
		  p += 2;
		}
		break;

	      case '\\':
		{
		  *(value_end++) = '\\';
		  p += 2;
		}
		break;

	      default:
		{
		  *(value_end++) = *(p++);
		}
	      }
	  }
	  break;

	default:
	  {
	    *(value_end++) = *(p++);
	  }
	  break;
	}
    }
  while (!stop);

  *value_end = 0;

  *_value = value;
  *_append = append;
  return;
}

/*
----------------------------------------------------------------------
getProperties
----------------------------------------------------------------------
*/

static int
getProperties (property_info_t *info, const char *path, const char *name)
{
  FILE *file = NULL;
  int exit_status = EXIT_SUCCESS;
  char *line = NULL;
  int append = 0;

  if (path == NULL || name == NULL)
    {
      goto cleanup;
    }

  {
    char *path_name = malloc (strlen (path) + 1 + strlen (name) + 1);

    if (path_name == NULL)
      {
	fprintf (stderr, "sablevm: out of memory\n");
	exit_status = EXIT_FAILURE;
	goto cleanup;
      }

    strcpy (path_name, path);
    strcat (path_name, "/");
    strcat (path_name, name);

    file = fopen (path_name, "r");

    free (path_name);
  }

  if (file == NULL)
    {
      /* It's OK if the file doesn't exist */
      goto cleanup;
    }

  while ((line = getLine (file)) != NULL)
    {
      char *property;
      char *value;

      if (!append)
	{
	  getPropertyAndValue (line, &property, &value, &append);

	  if (property != NULL)
	    {
	      property_t *tail = malloc (sizeof (property_t));
	      char *option =
		malloc (2 + strlen (property) + 1 + strlen (value) + 1);

	      if (tail == NULL || option == NULL)
		{
		  if (tail != NULL)
		    {
		      free (tail);
		    }

		  if (option != NULL)
		    {
		      free (option);
		    }

		  fprintf (stderr, "sablevm: out of memory\n");
		  exit_status = EXIT_FAILURE;
		  goto cleanup;
		}

	      strcpy (option, "--");
	      strcat (option, property);
	      strcat (option, "=");
	      strcat (option, value);

	      tail->value = option;
	      tail->next = NULL;

	      info->tail->next = tail;
	      info->tail = tail;
	      info->count++;
	      info->size += strlen (option) + 1;
	    }
	}
      else
	{
	  getValue (line, &value, &append);

	  if (value != NULL)
	    {
	      char *option = info->tail->value;

	      option = realloc (option, strlen (option) + strlen (value) + 1);

	      if (option == NULL)
		{
		  fprintf (stderr, "sablevm: out of memory\n");
		  exit_status = EXIT_FAILURE;
		  goto cleanup;
		}

	      strcat (option, value);
	      info->tail->value = option;
	      info->size += strlen (value);
	    }
	}

      free (line);
      line = NULL;
    }

  fclose (file);
  file = NULL;

cleanup:

  if (line != NULL)
    {
      free (line);
      line = NULL;
    }

  if (file != NULL)
    {
      fclose (file);
      file = NULL;
    }

  return exit_status;
}

/*
----------------------------------------------------------------------
parseConfig
----------------------------------------------------------------------
*/

static int
parseConfig (int *argc, const char ***argv)
{
  static property_t head = { NULL, NULL };
  static property_info_t info = { &head, 0, 0 };
  const char **buffer;
  int exit_status = EXIT_SUCCESS;

  if ((exit_status = getProperties (&info, SYSCONFDIR, "sablevm")) !=
      EXIT_SUCCESS)
    {
      goto error;
    }

  if ((exit_status = getProperties (&info, getenv ("HOME"), ".sablevm")) !=
      EXIT_SUCCESS)
    {
      goto error;
    }

  buffer = malloc ((*argc + info.count) * sizeof (char *) + info.size);

  if (buffer == NULL)
    {
      fprintf (stderr, "sablevm: out of memory\n");
      exit_status = EXIT_FAILURE;
      goto error;
    }

  {
    int i;
    property_t *current;
    char *tail = (char *) &buffer[*argc + info.count];

    buffer[0] = (*argv)[0];

    for (i = 1; i < *argc; i++)
      {
	buffer[i + info.count] = (*argv)[i];
      }

    current = head.next;
    head.next = NULL;
    i = 1;
    while (current != NULL)
      {
	property_t *temp = current;

	strcpy (tail, current->value);
	buffer[i++] = tail;
	tail += strlen (tail) + 1;

	current = current->next;

	free (temp->value);
	free (temp);
      }
  }

  *argc += info.count;
  *argv = buffer;

  return exit_status;

error:

  {
    property_t *current = head.next;

    head.next = NULL;

    while (current != NULL)
      {
	property_t *temp = current;

	current = current->next;

	free (temp->value);
	free (temp);
      }
  }

  return exit_status;
}

/*
----------------------------------------------------------------------
printVersionAndCopyright
----------------------------------------------------------------------
*/

static void
printVersionAndCopyright (void)
{
  printf ("\nSableVM version %s\n", _SABLEVM_PACKAGE_VERSION);


  printf
    ("Copyright (C) 2000-2004 Etienne M. Gagnon <etienne.gagnon@uqam.ca> and\n"
     "others.  All rights reserved.\n\n"
     "This software comes with ABSOLUTELY NO WARRANTY.  This is free\n"
     "software, and you are welcome to redistribute it under certain\n"
     "conditions.\n\n"
     "To get the name of all copyright holders and detailed license\n"
     "information, type \"sablevm --license\" or look in the directory\n"
     "\"%s\".\n\n"
     "The SableVM web site is located at http://www.sablevm.org/ .\n\n",
     PKGDATADIR);
}

/*
----------------------------------------------------------------------
printFullVersion
----------------------------------------------------------------------
*/

static void
printFullVersion (void)
{
  printf ("SableVM version %s\n", _SABLEVM_PACKAGE_VERSION);

  printf ("- compile date and time: %s\n", SVMCOMPILETIME);
  printf ("- gcc version: %s\n", __VERSION__);

#ifdef MAGIC
  printf ("- magic value added to every object instance header\n");
#endif

#ifdef STATISTICS
  printf ("- print statistics on VM exit\n");
#endif

#ifdef _SABLEVM_REAL_LIFE_BROKENNESS
  printf ("- 'real life brokenness' features enabled\n");
#endif

#ifdef _SABLEVM_INLINABILITY_TESTING
  printf ("- inlinability testing enabled\n");
#endif

#ifndef NDEBUG
  printf ("- debugging checks enabled\n");
#endif

#ifdef _SABLEVM_SIGNALS_FOR_EXCEPTIONS
  printf ("- signal based exception detection\n");
#endif

#ifdef _SABLEVM_NO_GC
  printf ("- no garbage collection\n");
#elif defined (_SABLEVM_COPY_GC)
  printf ("- copying garbage collection\n");
#elif defined (_SABLEVM_GENCOPY_GC)
  printf ("- generational copying garbage collection\n");
#endif

#ifdef _SABLEVM_TRADITIONAL_OBJECT_LAYOUT
  printf ("- traditional (unidirectional) object layout\n");
#elif defined (_SABLEVM_BIDIRECTIONAL_OBJECT_LAYOUT)
  printf ("- bidirectional object layout\n");
#endif

#ifdef _SABLEVM_SWITCH_THREADED_INTERPRETER
  printf ("- switch threaded interpreter\n");
#elif defined (_SABLEVM_DIRECT_THREADED_INTERPRETER)
  printf ("- direct-threaded interpreter\n");
#elif defined (_SABLEVM_INLINED_THREADED_INTERPRETER)
  printf ("- inline-threaded interpreter\n");
#endif
}

/*
----------------------------------------------------------------------
main
----------------------------------------------------------------------
*/

int
main (const int argc, const char *argv[])
{
  static char *argument = NULL;	/* string argument */
  static int verbose_class = 0;	/* enable verbose class loading */
  static int verbose_gc = 0;	/* enable verbose garbage collection */
  static int verbose_jni = 0;	/* enable verbose JNI */
  static int copyright = 1;	/* display copyright */
  static int license = 0;	/* display license information and exit */
  static int version = 0;	/* display version information and exit */

  int exit_status = EXIT_SUCCESS;	/* exit status */
  int all_argc = 0;		/* total number of command line and configuration file arguments */
  const char **all_args = NULL;	/* array of all command line and configuration file arguments */

  poptContext context = NULL;	/* context for parsing command-line options */

  jsize arguments_count = 0;	/* count of java arguments */
  const char **arguments = NULL;	/* array of java arguments */

  char *class_path = NULL;	/* class path */

  char *verbose = NULL;		/* verbose option(s) for vm creation */

  property_t *property_list = NULL;	/* list of system properties */

  jint vm_option_count = 3;	/* number of vm options */
  JavaVMOption *vm_options = NULL;	/* vm options array */

  JavaVM *vm = NULL;		/* vm instance */
  JNIEnv *env = NULL;		/* environment */

  jclass cls = NULL;		/* startup class */
  jclass str_cls = NULL;	/* java.lang.String class */
  jmethodID mid = NULL;		/* method ID for "void main(String[])" */
  jarray args = NULL;		/* arguments for main */

  /* *INDENT-OFF* */

#define ARG_CLASS_PATH 1
#define ARG_PROPERTY 2
#define ARG_VERBOSE 3
#define ARG_QUIET 4
#define ARG_VERBOSE_CLASS 5
#define ARG_NO_VERBOSE_CLASS 6
#define ARG_VERBOSE_GC 7
#define ARG_NO_VERBOSE_GC 8
#define ARG_VERBOSE_JNI 9
#define ARG_NO_VERBOSE_JNI 10
#define ARG_COPYRIGHT 11
#define ARG_NO_COPYRIGHT 12

  static const struct poptOption options[] =	/* description of command line options */
  {
    {"classpath", 'c', POPT_ARG_STRING, &argument, ARG_CLASS_PATH, "set class path", "\"PATH\""},
    {"property", 'p', POPT_ARG_STRING, &argument, ARG_PROPERTY, "set system property", "\"NAME=VALUE\""},
    {"verbose", 'v', POPT_ARG_NONE, NULL, ARG_VERBOSE, "enable all verbose options", NULL},
    {"quiet", 'q', POPT_ARG_NONE, NULL, ARG_QUIET, "disable all verbose options", NULL},
    {"verbose-class", 's', POPT_ARG_NONE, NULL, ARG_VERBOSE_CLASS, "enable verbose class loading", NULL},
    {"no-verbose-class", 'S', POPT_ARG_NONE, NULL, ARG_NO_VERBOSE_CLASS, "disable verbose class loading", NULL},
    {"verbose-gc", 'g', POPT_ARG_NONE, NULL, ARG_VERBOSE_GC, "enable verbose garbage collection", NULL},
    {"no-verbose-gc", 'G', POPT_ARG_NONE, NULL, ARG_NO_VERBOSE_GC, "disable verbose garbage collection", NULL},
    {"verbose-jni", 'j', POPT_ARG_NONE, NULL, ARG_VERBOSE_JNI, "enable verbose JNI", NULL},
    {"no-verbose-jni", 'J', POPT_ARG_NONE, NULL, ARG_NO_VERBOSE_JNI, "disable verbose JNI", NULL},
    {"copyright", 'y', POPT_ARG_NONE, NULL, ARG_COPYRIGHT, "display copyright", NULL},
    {"no-copyright", 'Y', POPT_ARG_NONE, NULL, ARG_NO_COPYRIGHT, "do not display copyright", NULL},
    {"license", 'L', POPT_ARG_NONE, &license, 0, "display license information and exit", NULL},
    {"version", 'V', POPT_ARG_NONE, &version, 0, "display version information and exit", NULL},
    POPT_AUTOHELP
    {NULL, 0, 0, NULL, 0, NULL, NULL}
  };
  /* *INDENT-ON* */

  /* parse configuration files */
  all_argc = argc;
  all_args = argv;

  if ((exit_status = parseConfig (&all_argc, &all_args)) != EXIT_SUCCESS)
    {
      goto cleanup;
    }

  /* create parsing context */
  context =
    poptGetContext (NULL, all_argc, all_args, options,
		    POPT_CONTEXT_POSIXMEHARDER);
  poptSetOtherOptionHelp (context, "[OPTION]... CLASSNAME [ARGUMENT]...");

  /* parse options */
  {
    int c;

    /* Unfortunately, poptGetNextOpt has a couple of known memory leaks.
       (see comments in source code of popt) */
    while ((c = poptGetNextOpt (context)) >= 0)
      {
	switch (c)
	  {
	  case ARG_CLASS_PATH:
	    {
	      const char *str = "-Djava.class.path=";
	      size_t len = strlen (str);
	      char *opt = malloc (len + strlen (argument) + 1);

	      if (opt == NULL)
		{
		  fprintf (stderr, "sablevm: out of memory\n");
		  exit_status = EXIT_FAILURE;
		  goto cleanup;
		}

	      strcpy (opt, str);
	      strcpy (&opt[len], argument);

	      if (class_path != NULL)
		{
		  free (class_path);
		  class_path = opt;
		}
	      else
		{
		  class_path = opt;
		  vm_option_count++;
		}
	    }
	    break;

	  case ARG_PROPERTY:
	    {
	      const char *str = "-D";
	      size_t len = strlen (str);
	      char *opt = malloc (len + strlen (argument) + 1);
	      property_t *temp = malloc (sizeof (property_t));

	      if (temp == NULL || opt == NULL)
		{
		  if (temp != NULL)
		    {
		      free (temp);
		      temp = NULL;
		    }

		  if (opt != NULL)
		    {
		      free (opt);
		      opt = NULL;
		    }

		  fprintf (stderr, "sablevm: out of memory\n");
		  exit_status = EXIT_FAILURE;
		  goto cleanup;
		}

	      strcpy (opt, str);
	      strcpy (&opt[len], argument);

	      temp->value = opt;
	      temp->next = property_list;
	      property_list = temp;
	      vm_option_count++;
	    }
	    break;

	  case ARG_VERBOSE:
	    {
	      verbose_class = 1;
	      verbose_gc = 1;
	      verbose_jni = 1;
	    }
	    break;

	  case ARG_QUIET:
	    {
	      verbose_class = 0;
	      verbose_gc = 0;
	      verbose_jni = 0;
	    }
	    break;

	  case ARG_VERBOSE_CLASS:
	    {
	      verbose_class = 1;
	    }
	    break;

	  case ARG_NO_VERBOSE_CLASS:
	    {
	      verbose_class = 0;
	    }
	    break;

	  case ARG_VERBOSE_GC:
	    {
	      verbose_gc = 1;
	    }
	    break;

	  case ARG_NO_VERBOSE_GC:
	    {
	      verbose_gc = 0;
	    }
	    break;

	  case ARG_VERBOSE_JNI:
	    {
	      verbose_jni = 1;
	    }
	    break;

	  case ARG_NO_VERBOSE_JNI:
	    {
	      verbose_jni = 0;
	    }
	    break;


	  case ARG_COPYRIGHT:
	    {
	      copyright = 1;
	    }
	    break;

	  case ARG_NO_COPYRIGHT:
	    {
	      copyright = 0;
	    }
	    break;

	  default:
	    {
	      fprintf (stderr, "sablevm: internal error");
	      exit_status = EXIT_FAILURE;
	      goto cleanup;
	    }
	  }
      }

    if (c < -1)
      {
	/* an error occurred during option processing */

	fprintf (stderr, "sablevm: \"%s\" %s\n",
		 poptBadOption (context, 0), poptStrerror (c));
	fprintf (stderr, "Try \"sablevm --help\" for more information\n");

	exit_status = EXIT_FAILURE;
	goto cleanup;
      }
  }

  /* license */
  if (license)
    {
      exit_status = displayFileContent (PKGDATADIR, "AUTHORS", 1);

      if (exit_status != EXIT_SUCCESS)
	{
	  goto cleanup;
	}

      exit_status = displayFileContent (PKGDATADIR, "LICENSE", 1);

      if (exit_status != EXIT_SUCCESS)
	{
	  goto cleanup;
	}

      exit_status = displayFileContent (PKGDATADIR, "LGPL-2.1", 0);

      goto cleanup;
    }

  /* version */
  if (version)
    {
      printFullVersion ();
      goto cleanup;
    }

  /* get arguments */
  arguments = poptGetArgs (context);

  /* if no argument was given, print usage information and exit */
  if (arguments == NULL)
    {
      poptPrintUsage (context, stderr, 0);
      fprintf (stderr, "Try \"sablevm --help\" for more information.\n");
      exit_status = EXIT_FAILURE;
      goto cleanup;
    }

  /* count arguments */
  while (arguments[arguments_count] != NULL)
    {
      arguments_count++;
    }

  /* copyright */
  if (copyright)
    {
      printVersionAndCopyright ();
    }

  /* verbose */
  {
    const char *gc_str = "gc";
    const char *class_str = "class";
    const char *jni_str = "jni";
    const char *verbose_str = "-verbose:";
    size_t verbose_length = 0;

    if (verbose_gc)
      {
	verbose_length = strlen (gc_str);
      }

    if (verbose_class)
      {
	verbose_length +=
	  strlen (class_str) + ((verbose_length == 0) ? 0 : 1);
      }

    if (verbose_jni)
      {
	verbose_length += strlen (jni_str) + ((verbose_length == 0) ? 0 : 1);
      }

    if (verbose_length != 0)
      {
	int need_comma = 0;

	verbose = malloc (strlen (verbose_str) + verbose_length + 1);

	if (verbose == NULL)
	  {
	    fprintf (stderr, "sablevm: out of memory\n");
	    exit_status = EXIT_FAILURE;
	    goto cleanup;
	  }

	strcpy (verbose, verbose_str);

	if (verbose_gc)
	  {
	    strcat (verbose, gc_str);
	    need_comma = 1;
	  }

	if (verbose_class)
	  {
	    if (need_comma)
	      {
		strcat (verbose, ",");
	      }

	    strcat (verbose, class_str);
	    need_comma = 1;
	  }

	if (verbose_jni)
	  {
	    if (need_comma)
	      {
		strcat (verbose, ",");
	      }

	    strcat (verbose, jni_str);
	    need_comma = 1;
	  }

	vm_option_count++;
      }
  }

  /* allocate vm_options array */
  vm_options = malloc (vm_option_count * sizeof (JavaVMOption));

  if (vm_options == NULL)
    {
      fprintf (stderr, "sablevm: out of memory\n");
      exit_status = EXIT_FAILURE;
      goto cleanup;
    }

  /* initialize vm_options array */
  {
    jint option = 0;

    vm_options[option].optionString = (char *) "vfprintf";
    vm_options[option++].extraInfo = SVM_CAST_EXTENSION (void *) vfprintf;

    vm_options[option].optionString = (char *) "exit";
    vm_options[option++].extraInfo = SVM_CAST_EXTENSION (void *) exit;

    vm_options[option].optionString = (char *) "abort";
    vm_options[option++].extraInfo = SVM_CAST_EXTENSION (void *) abort;

    if (class_path != NULL)
      {
	vm_options[option++].optionString = (char *) class_path;
      }

    if (verbose != NULL)
      {
	vm_options[option++].optionString = verbose;
      }

    {
      property_t *current = property_list;

      while (current != NULL)
	{
	  vm_options[option++].optionString = current->value;

	  current = current->next;
	}
    }
  }

  {
    JavaVMInitArgs vm_args;	/* vm initialization arguments */

    vm_args.version = JNI_VERSION_1_2;
    vm_args.nOptions = vm_option_count;
    vm_args.options = vm_options;
    vm_args.ignoreUnrecognized = JNI_FALSE;

    /* create vm */
    if (JNI_CreateJavaVM (&vm, (void **) &env, &vm_args) < 0)
      {
	fprintf (stderr, "sablevm: cannot create vm\n");
	exit_status = EXIT_FAILURE;
	vm = NULL;
	goto cleanup;
      }
  }

  /* free stuff */
  while (property_list != NULL)
    {
      property_t *temp = property_list;

      property_list = property_list->next;
      free (temp->value);
      free (temp);
    }

  if (class_path != NULL)
    {
      free (class_path);
      class_path = NULL;
    }

  if (verbose != NULL)
    {
      free (verbose);
      verbose = NULL;
    }

  free (vm_options);
  vm_options = NULL;

  free (all_args);
  all_args = NULL;


  /* find VirtualMachine class */
  if ((cls = (*env)->FindClass (env, "java/lang/VirtualMachine")) == NULL)
    {
      (*env)->ExceptionDescribe (env);
      exit_status = EXIT_FAILURE;
      goto cleanup;
    }

  /* find main in VirtualMachine class */
  if ((mid = (*env)->GetStaticMethodID
       (env, cls, "main", "([Ljava/lang/String;)V")) == NULL)
    {
      (*env)->ExceptionDescribe (env);
      exit_status = EXIT_FAILURE;
      goto cleanup;
    }

  /* find java.lang.String */
  if ((str_cls = (*env)->FindClass (env, "java/lang/String")) == NULL)
    {
      (*env)->ExceptionDescribe (env);
      exit_status = EXIT_FAILURE;
      goto cleanup;
    }

  /* create an array of java.lang.String */
  if ((args = (*env)->NewObjectArray
       (env, arguments_count, str_cls, NULL)) == NULL)
    {
      (*env)->ExceptionDescribe (env);
      exit_status = EXIT_FAILURE;
      goto cleanup;
    }

  {
    jsize i;
    for (i = 0; i < arguments_count; i++)
      {
	/* allocate string */
	jstring s;

	if ((s = (*env)->NewStringUTF (env, arguments[i])) == NULL)
	  {
	    (*env)->ExceptionDescribe (env);
	    exit_status = EXIT_FAILURE;
	    goto cleanup;
	  }

	/* put string in array */
	(*env)->SetObjectArrayElement (env, args, i, s);

	if ((*env)->ExceptionCheck (env))
	  {
	    (*env)->ExceptionDescribe (env);
	    exit_status = EXIT_FAILURE;
	    goto cleanup;
	  }

	/* free up local native reference */
	(*env)->DeleteLocalRef (env, s);
      }
  }

  /* call main */
  (*env)->CallStaticVoidMethod (env, cls, mid, args);

  /* check for exception */
  if ((*env)->ExceptionCheck (env))
    {
      (*env)->ExceptionDescribe (env);
      exit_status = EXIT_FAILURE;
      goto cleanup;
    }

  /* delete the vm */
  if ((*vm)->DestroyJavaVM (vm) != 0)
    {
      fprintf (stderr, "sablevm: cannot delete vm\n");

      exit_status = EXIT_FAILURE;
      goto cleanup;
    }
  vm = NULL;

cleanup:

  if (vm != NULL)
    {
      (*vm)->DestroyJavaVM (vm);
    }

  if (vm_options != NULL)
    {
      free (vm_options);
      vm_options = NULL;
    }

  if (class_path != NULL)
    {
      free (class_path);
      class_path = NULL;
    }

  if (verbose != NULL)
    {
      free (verbose);
      verbose = NULL;
    }

  while (property_list != NULL)
    {
      property_t *temp = property_list;

      property_list = property_list->next;
      free (temp->value);
      free (temp);
    }

  if (context != NULL)
    {
      poptFreeContext (context);
      context = NULL;
    }

  if (all_args != NULL)
    {
      free (all_args);
      all_args = NULL;
    }

  exit (exit_status);
}
