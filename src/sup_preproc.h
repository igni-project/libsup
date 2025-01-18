/* preproc.h
 * Compiler agnostic C pre-processor macros */

#ifndef LIBSUP_P_COMPILER_H
#define LIBSUP_P_COMPILER_H 1

/**/
#ifdef __GNUC__
#define __PACK __attribute__((__packed__))
#define PACK__
#elif defined _MSC_VER
#define __PACK __pragma( pack(push, 1)
#define PACK__ __pragma( pack(pop))
#endif

#endif


