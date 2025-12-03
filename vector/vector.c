#include "private.h"
#include "vector.h"

#define DEFAULT_MAX_LENGTH 8


Vector * VectorInit(size_t maxLength, size_t elemSize, void * moreContext, void * (*allocate)(size_t size, void * moreContext), void (*liberate)(void * ptr, void * moreContext)) {
    if (maxLength == 0) maxLength = DEFAULT_MAX_LENGTH;

    Vector * vec = (Vector *) allocate(sizeof(Vector), moreContext);

    if (vec == NULL) return NULL;

    vec->length = 0;
    vec->maxLength = maxLength;
    vec->elemSize = elemSize;
    vec->moreContext = moreContext;
    vec->allocate = allocate;
    vec->liberate = liberate;
    
    vec->content = (unsigned char *) allocate(elemSize * maxLength, moreContext);

    if (vec->content != NULL) return vec;

    liberate(vec, moreContext);

    return NULL;
}


Vector * VectorCopy(Vector * vec) {
    Vector * nvec = (Vector *) vec->allocate(sizeof(Vector), vec->moreContext);

    if (nvec == NULL) return NULL;

    nvec->content = (unsigned char *) vec->allocate(vec->maxLength, vec->moreContext);

    if (nvec->content == NULL) {
        vec->liberate(nvec, vec->moreContext);

        return NULL;
    }

    memcpy(nvec->content, vec->content, vec->length);

    nvec->elemSize = vec->elemSize;
    nvec->length = vec->length;
    nvec->maxLength = vec->maxLength;
    nvec->moreContext = vec->moreContext;
    nvec->liberate = vec->liberate;
    nvec->allocate = vec->allocate;

    return nvec;
}

