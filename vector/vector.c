#include "private.h"
#include "vector.h"

#define DEFAULT_MAX_LENGTH 8


Vector * VectorInit(size_t maxLength, size_t elemSize, void * moreContext, void * (*allocate)(size_t size, void * moreContext), void (*liberator)(void * ptr, void * moreContext)) {
    if (maxLength == 0) maxLength = DEFAULT_MAX_LENGTH;

    Vector * vec = (Vector *) allocate(sizeof(Vector), moreContext);

    if (vec == NULL) return NULL;

    vec->length = 0;
    vec->maxLength = maxLength;
    vec->elemSize = elemSize;
    vec->moreContext = moreContext;
    vec->allocate = allocate;
    vec->liberator = liberator;
    
    vec->content = (unsigned char *) allocate(elemSize * maxLength, moreContext);

    if (vec->content != NULL) return vec;

    liberator(vec, moreContext);

    return NULL;
}


Vector * VectorCopy(Vector * vec) {}
