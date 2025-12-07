#include <stdbool.h>
#include <string.h>

#ifdef _WIN32
    typedef ssize_t long;
#else
    #include <sys/types.h>
#endif

#include "private.h"
#include "../vector.h"


size_t VectorLength(const Vector * vec) {
    return vec->length;
}

void * VectorMoreContext(const Vector * vec) {
    return vec->moreContext;
}

size_t VectorElemSize(const Vector * vec) {
    return vec->elemSize;
}


unsigned char * VectorGet(const Vector * vec, size_t key) {
    if (key >= vec->length) return NULL;

    key *= vec->elemSize;

    return vec->content + key;
}


Vector * VectorSet(Vector * vec, size_t key, void * value) {
    if (key >= vec->length) return NULL;

    memcpy(
        vec->content + key * vec->elemSize,
        value,
        vec->elemSize
    );

    return vec;
}


ssize_t VectorIndexOf(const Vector * vec, const void * value) {
    for (size_t i = 0; i < vec->length; i++) {
        size_t index = i * vec->elemSize;

        if (!memcmp(value, vec->content + index, vec->elemSize)) {
            return i;
        }
    }

    return -1;
}


bool VectorContains(const Vector * vec, const void * value) {
    return VectorIndexOf(vec, value) != -1;
}


void VectorForEach(Vector * vec, void (*func)(void * value, const void * moreContext)) {
    for (size_t i = 0; i < vec->length; i++) {
        void * element = vec->content + i * vec->elemSize;

        func(element, vec->moreContext);
    }
}
