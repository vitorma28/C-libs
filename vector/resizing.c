#include "private.h"
#include "vector.h"

#include <string.h>


static Vector * VectorGrow(Vector * vec) {
    void * newSpace = vec->allocate(vec->maxLength * 2, vec->moreContext);

    if (newSpace == NULL) return NULL;

    memcpy(newSpace, vec->content, vec->maxLength);

    vec->liberate(vec->content, vec->moreContext);

    vec->content = newSpace;
    vec->maxLength *= 2;

    return vec;
}


static void VectorShift1Right(Vector * vec, size_t index) {
    if (index >= vec->length - 1) {
        return;
    }

    for (size_t i = vec->length - 2; i >= index; i--) {
        size_t offset = i * vec->elemSize;
        size_t offsetNext = offset + vec->elemSize;
        memcpy(vec->content + offsetNext, vec->content + offset, vec->elemSize);
    }
}


static void VectorShift1Left(Vector * vec, size_t index) {
    if (index >= vec->length - 1) {
        return;
    }

    for (size_t i = index; i < vec->length - 1; i++) {
        size_t offset = i * vec->elemSize;
        size_t offsetNext = offset + vec->elemSize;
        memcpy(vec->content + offset, vec->content + offsetNext, vec->elemSize);
    }
}


void VectorPush(Vector * vec, void * value) {
    if (vec->length == vec->maxLength) {
        void * tmp = VectorGrow(vec);

        if (tmp == NULL) return;
    }

    memcpy(vec->content + vec->length * vec->elemSize, value, vec->elemSize);

    vec->length++;
}


void VectorPop(Vector * vec) {
    if (vec->length != 0) vec->length--;
}


void VectorInsert(Vector * vec, size_t index, void * value) {}


void VectorRemove(Vector * vec, size_t index) {}
