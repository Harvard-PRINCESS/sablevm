m4_divert(-1)

 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * This source file is part of SableVM.                            *
 *                                                                 *
 * See the file "LICENSE" for the copyright information and for    *
 * the terms and conditions for copying, distribution and          *
 * modification of this source file.                               *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

----------------------------------------------------------------------
disable the m4 comment mechanism
----------------------------------------------------------------------

This mechanism can interfere with the C preprocessor, so we get rid of
it.

m4_changecom

----------------------------------------------------------------------
change the quote characters
----------------------------------------------------------------------

The m4 quotes are confusing for C syntax coloring tools (like emacs in
C mode), so we redefine them to something visually clear and that
doesn't interfere with C syntax.  This also allows us to run GNU
indent on files wich mix C and m4 code (*.m4.c and *.m4.h files).

m4_define(`m4svm_lbkt', `[[:::]')
m4_define(`m4svm_rbkt', `[:::]]')
m4_changequote(`[:', `:]')

----------------------------------------------------------------------
IMPORTANT NOTE:
----------------------------------------------------------------------

We will write comments as normal text in *.m4 files, without using any
special "begin/end" keywords.  In order to avoid interference problems
with defined macros, we will write "M4_..." and "M4svm_..."  (with a
capital "M") to refer to "m4_..." and "m4svm_..." macros.

Note that m4 MUST be called with the -P parameter so that all
predefined macros are prefixed by "m4_".

----------------------------------------------------------------------
on/off
----------------------------------------------------------------------

m4_define([:m4svm_onoff:], -1)

m4_define([:m4svm_on:],
[:m4_pushdef([:m4svm_onoff:], $1)m4_divert(m4svm_onoff):])

m4_define([:m4svm_off:],
[:m4_popdef([:m4svm_onoff:])m4_divert(m4svm_onoff):])

----------------------------------------------------------------------
file_name macro
----------------------------------------------------------------------

This macro expands to the source file name in a C comment.

m4_define([:m4svm_file_name:],
[:m4svm_on(0)m4_dnl
/* This file has been automatically generated from m4_dnl
"m4___file__" */
m4svm_off():])

----------------------------------------------------------------------
for loop macro
----------------------------------------------------------------------

Here's an example of use:

M4svm_for([:i:], 1, 3, [:-i-:])

which is somewhat equivalent to the C code:

{
  int i;
  for(i = 1; i < 3; i++)
  {
    printf("-%d-", i);
  }
}

so, it expands to:

-1--2--3-

If you really want to understand the following code, then read the m4
texinfo documentation (e.g. "info m4" on a sane GNU system), specially
the section about loops.  Then experiment with removing quotes or
changing them... You'll quickly appreciate the delicate art of quoting
in m4. :-)

m4_define([:m4svm_for:],
m4_dnl
m4_dnl iterate only if $2 <= $3
m4_dnl
[:m4_ifelse(m4_eval($2 <= $3), 1,
m4_dnl
m4_dnl initialize loop variable
m4_dnl
[:m4_pushdef([:$1:], $2):]m4_dnl
m4_dnl
m4_dnl iterate
m4_dnl
[:m4svm_for_internal([:$1:], $3, [:$4:]):]m4_dnl
m4_dnl
m4_dnl get rid of loop variable
m4_dnl
[:[::]m4_popdef([:$1:]):]):])

Now the loop kernel.  It consists of a tail recursive macro. :-)

m4_define([:m4svm_for_internal:],
m4_dnl
m4_dnl execute the loop body
m4_dnl
[:$3:]m4_dnl
m4_dnl
m4_dnl are we finished?
m4_dnl
[:[::]m4_ifelse($1, $2, ,
m4_dnl
m4_dnl increment the loop variable
m4_dnl
[:m4_define([:$1:], m4_incr($1)):]m4_dnl
m4_dnl
m4_dnl recurse
m4_dnl
[:m4svm_for_internal($@):]):])

----------------------------------------------------------------------
return the Nth argument
----------------------------------------------------------------------

The typical use of this macro is: M4svm_argn(n, $@), where n is a
number, for retrieving the "n"th argument of a parameter list ($@).
Pretty handy macro.

m4_define([:m4svm_argn:],
[:m4_ifelse($1, 1, [:[:$2:]:],
[:m4svm_argn(m4_decr($1), m4_shift(m4_shift($@))):]):])

----------------------------------------------------------------------
multicall macro
----------------------------------------------------------------------

This macro is my preferred one!  It required a lot of thought. It
allows you to write:

M4svm_multicall(mymacro)

then later

--- Begin ---
mymacro_begin[:

arg1a, ...
arg1b

arg1c

:]mymacro_end
--- End ---

which expands to

--- Begin ---
mymacro(arg1a, ...)mymacro(arg1b)mymacro(arg1c)
--- End ---

IMPORTANT: Do not forget the "[:" and ":]" after "..._begin" and
before "..._end" respectively.  Unpredictable things will happen if
you forget them.

m4_define([:m4svm_multicall:],
m4_dnl
m4_dnl define M4svm_multicall_$1 which expands to nothing when invoked
m4_dnl with a parameter list of the form "()", or to $1($@) otherwise.
m4_dnl
[:m4_define([:m4svm_multicall_$1:],
[:m4_ifelse($:][:#$:][:1,
1, , [:$1:]($:][:@)):])m4_dnl
m4_dnl
m4_dnl define M4svm_$1_begin
m4_dnl
m4_define([:$1_begin:],
[:m4svm_on(0)m4_dnl
m4svm_multicall_$1(m4_patsubst(:])m4_dnl
m4_dnl
m4_dnl define M4svm_$1_end
m4_dnl
m4_define([:$1_end:],
[:, [:$:], [:)m4svm_multicall_$1(:]))m4_dnl
m4svm_off():]):])

Neat, isn't it? :-)

----------------------------------------------------------------------
define macro
----------------------------------------------------------------------

This macro is useful for "hiding" m4 definition macros into C source
code so that not to break the action of "GNU indent" on these files.

So, to define a macro "foo" you can write:

M4svm_define_begin v = ":], [:foo:])";
...
body
...
M4svm_define_end v = ":])";

Notice how the lines starting with M4svm_define_* look like simple C
variable declarations (with string initializers).

m4_define([:m4svm_define_begin:],
[:m4svm_define_1([[::]::])

m4_define([:m4svm_define_1:],
[:m4svm_define_2([:$2:],
m4svm_define_begin_1:])

m4_define([:m4svm_define_2:],
[:m4svm_define_3([:$1:],
m4_patsubst([:[:$2:]:],
[:m4svm_define_begin_1";
:], [::])):])

m4_define([:m4svm_define_3:],
[:m4svm_define_4([:$1:],
m4_patsubst([:[:$2:]:],
[:.*m4svm_define_end.*$:], m4svm_rbkt)):])

m4_define([:m4svm_define_4:],
[:m4svm_define_5([:$1:],
m4_ifelse(m4_regexp([:$2:], [:
:]), -1,
[[::$2:],
[:[:$2:]:])):])

m4_define([:m4svm_define_5:],
[:m4svm_define_6([:$1:],
m4_patsubst([:[:$2:]:],
[:
.*/\* *\*/.*$:], [::])):])

m4_define([:m4svm_define_6:],
[:m4_define([:$1:],
[:m4svm_on(0)$2[::]m4svm_off():]):])

----------------------------------------------------------------------
comment define macro
----------------------------------------------------------------------

This macro allows you to define an M4 macro within a C comment, like:

 /*
  * M4svm_comment_define([:foo:],
  * [:...
  * ...
  * ...:])
  */

m4_define([:m4svm_comment_define:],
[:m4svm_comment_define_1([:$1:],
m4_patsubst([:[:$2:]:], [:^[[::]:\* :], m4svm_lbkt)):])

m4_define([:m4svm_comment_define_1:],
[:m4svm_comment_define_2([:$1:],
m4_patsubst([:[:$2:]:], [:^	* *\*$:], [::])):])

m4_define([:m4svm_comment_define_2:],
[:m4svm_comment_define_3([:$1:],
m4_patsubst([:[:$2:]:], [:^	* *\* :], [::])):])

m4_define([:m4svm_comment_define_3:],
[:m4_define([:$1:], [:$2:]):])
