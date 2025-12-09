#include "vector.h"
#include <stdlib.h>
#include <stdio.h>


void * allocate(size_t size, const void * _) {
    return malloc(size);
}


void liberate(void * ptr, const void * _) {
    free(ptr);
}


void show(void * value, const void * _) {
    printf("%d\n", *(int *)value);
}


int main(void) {
    int vs[5] = {10, 20, 30, 40, 50};

    Vector * vec = VectorInit(0, sizeof(int), NULL, allocate, liberate);
    VectorPush(vec, vs);
    VectorPush(vec, vs + 1);
    VectorPush(vec, vs + 2);
    VectorPush(vec, vs + 3);
    VectorPush(vec, vs + 4);

    VectorForEach(vec, show);

    VectorPop(vec);

    puts("");

    VectorForEach(vec, show);

    return 0;
}
