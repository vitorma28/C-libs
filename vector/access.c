#include <stdbool.h>
#include <string.h>
#include <sys/types.h>


#include "private.h"
#include "vector.h"


unsigned char * VectorGet(Vector * vec, size_t key) {
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


ssize_t VectorIndexOf(Vector * vec, void * value) {
    for (size_t i = 0; i < vec->length; i++) {
        size_t index = i * vec->elemSize;

        if (!memcmp(value, vec->content + index, vec->elemSize)) {
            return i;
        }
    }

    return -1;
}


bool VectorContains(Vector * vec, void * value) {
    return VectorIndexOf(vec, value) != -1;
}


void VectorForEach(Vector * vec, void (*func)(void * value)) {}


void VectorMap(Vector * vec, void * (*func)(void * value)) {}
