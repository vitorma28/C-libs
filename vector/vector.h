#ifndef VECTOR_H
#define VECTOR_H

#include <stddef.h>


typedef struct Vector Vector;

Vector * VectorInit(size_t maxLength, size_t elemSize, void * moreContext, void * (*allocate)(size_t size, void * moreContext), void (*liberate)(void * ptr, void * moreContext));
Vector * VectorCopy(Vector * vec);
void VectorDestroy(Vector ** vec_ptr);

#endif
