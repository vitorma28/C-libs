#include "private.h"
#include "vector.h"


static void VectorShift(Vector * vec) {}


static void VectorUnshift(Vector * vec) {}


void VectorPush(Vector * vec, void * value) {}


void VectorPop(Vector * vec) {
    if (vec->length != 0) vec->length--;
}


void VectorInsert(Vector * vec, size_t index, void * value) {}


void VectorRemove(Vector * vec, size_t index) {}
