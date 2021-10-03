#ifndef __SMALLOC_H
#define __SMALLOC_H

#include <stdio.h>

#ifdef THINK_C
    typedef int bool;
#else
#  ifdef TRUE
#    ifndef bool
#      define bool int
#    endif
#  else
#    ifdef bool
#      define FALSE 0
#      define TRUE 1
#    else
        typedef enum {FALSE, TRUE} bool;
#    endif
#  endif
#endif

typedef char *string;

extern char undefined_object[];
#define UNDEFINED ((void *) undefined_object)

void *MemAlloc(size_t nbytes, const char *file, int line);
void *MemCalloc(long count, size_t nbytes, const char *file, int line);
void *MemResize(void *ptr, long nbytes, const char *file, int line);
void MemFree(void *ptr, const char *file, int line);

#define smalloc(nbytes)         ((void *) MemAlloc(nbytes, __FILE__, __LINE__))
#define scalloc(count, nbytes)  ((void *) MemCalloc(count, nbytes, __FILE__, __LINE__))
#define free(type)              ((void) MemFree(type, __FILE__, __LINE__))

#define New(type)           ((type) MemAlloc(sizeof *((type) NULL, __FILE__, __LINE__)))
#define New0(type)          ((type) MemCalloc(1, sizeof *(type), __FILE__, __LINE__))
#define NewArray(n, type)   ((type *) MemAlloc((n) * sizeof (type), __FILE__, __LINE__))
#define Free(type)          ((void) MemFree(type, __FILE__, __LINE__))

void Error(string msg, ...);

#endif