#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdarg.h>
#include "assert.h"
#include "except.h"
#include "smalloc.h"

/*
 * Constants:
 * ----------
 * ErrorExitStatus -- Status value used in exit call
  */

#define ErrorExitStatus 1
/*
 * Constant: UNDEFINED
 * -------------------
 * This entry defines the target of the UNDEFINED constant.
 */

char undefined_object[] = "UNDEFINED";
const Except_T Mem_Failed = { "Allocation Failed" };

void *MemAlloc(size_t nbytes, const char *file, int line) {
	void *ptr;
	assert(nbytes > 0);
	ptr = malloc(nbytes);
	if (ptr == NULL) {
		if (file == NULL)
			RAISE(Mem_Failed);
		else
			Except_raise(&Mem_Failed, file, line);
	}
	return ptr;
}

void *MemCalloc(long count, size_t nbytes, const char *file, int line) {
	void *ptr;
	assert(count > 0);
	assert(nbytes > 0);
	ptr = calloc(count, nbytes);
	if (ptr == NULL) {
        if (file == NULL)
            RAISE(Mem_Failed);
        else
            Except_raise(&Mem_Failed, file, line);
    }
	return ptr;
}

void MemFree(void *ptr, const char *file, int line) {
	if (ptr)
		free(ptr);
}

void *MemResize(void *ptr, long nbytes, const char *file, int line) {
	assert(ptr);
	assert(nbytes > 0);
	ptr = realloc(ptr, nbytes);
	if (ptr == NULL) {
        if (file == NULL)
            RAISE(Mem_Failed);
        else
            Except_raise(&Mem_Failed, file, line);
    }
	return ptr;
}


void Error(string msg, ...) {
    va_list args;

    va_start(args, msg);
    fprintf(stderr, "Error: ");
    vfprintf(stderr, msg, args);
    fprintf (stderr, "\n");
    va_end(args);
    exit(ErrorExitStatus);
}