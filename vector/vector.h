#ifndef VECTOR_H
#define VECTOR_H

#ifdef _WIN32
    typedef ssize_t long;
#else
    #include <sys/types.h>
#endif

#include <stdbool.h>
#include <stddef.h>


typedef struct Vector Vector;

// Create and destruct functions

Vector * VectorInit(size_t maxLength, size_t elemSize, const void * moreContext, void * (*allocate)(size_t size, const void * moreContext), void (*liberate)(void * ptr, const void * moreContext));
Vector * VectorCopy(const Vector * vec);

void VectorDestroy(Vector ** vec_ptr);

// Resizing functions
void VectorPush(Vector * vec, const void * value);
void VectorInsert(Vector * vec, size_t index, const void * value);
void VectorPop(Vector * vec);
void VectorRemove(Vector * vec, size_t index);

// Properties
size_t VectorLength(const Vector * vec);
void * VectorMoreContext(const Vector * vec);
size_t VectorElemSize(const Vector * vec);

// Access functions
unsigned char * VectorGet(const Vector * vec, size_t key);
Vector * VectorSet(Vector * vec, size_t key, void * value);
ssize_t VectorIndexOf(const Vector * vec, const void * value);
bool VectorContains(const Vector * vec, const void * value);
void VectorForEach(Vector * vec, void (*func)(void * value, const void * moreContext));

#endif
