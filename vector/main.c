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
    int v = *(int*)value;
}


int main(void) {
    int vs[5] = {500, 20, 30, 40, 50};

    Vector * vec = VectorInit(0, sizeof(int), NULL, allocate, liberate);
    
    peekContent(vec);

    VectorPush(vec, vs);
    
    peekContent(vec);

    VectorPush(vec, vs + 1);
    
    peekContent(vec);

    VectorPush(vec, vs + 2);
    
    peekContent(vec);

    VectorPush(vec, vs + 3);
    
    peekContent(vec);



    VectorPush(vec, vs + 2);
    
    peekContent(vec);

    VectorPush(vec, vs + 2);
    
    peekContent(vec);

    VectorPush(vec, vs + 2);
    
    peekContent(vec);

    VectorPush(vec, vs + 2);
    
    peekContent(vec);

    VectorPush(vec, vs + 2);
    
    peekContent(vec);

    VectorPush(vec, vs + 2);
    
    peekContent(vec);

    VectorPush(vec, vs + 2);
    
    peekContent(vec);

    VectorPush(vec, vs + 2);
    
    peekContent(vec);

    VectorPush(vec, vs + 2);
    
    peekContent(vec);

    VectorPush(vec, vs + 2);
    
    peekContent(vec);

    VectorPush(vec, vs + 2);
    
    peekContent(vec);

    VectorPush(vec, vs + 2);
    
    peekContent(vec);

    VectorPush(vec, vs + 2);
    
    peekContent(vec);

    VectorPush(vec, vs + 2);
    
    peekContent(vec);

    VectorPush(vec, vs + 2);
    
    peekContent(vec);

    VectorPush(vec, vs + 2);
    
    peekContent(vec);

    return 0;
}
