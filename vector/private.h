#ifndef PRIVATE_H
#define PRIVATE_H

#include <stddef.h>

struct Vector {
    unsigned char * content;
    void * moreContext;
    void * (*allocate)(size_t size, void * moreContext);
    void (*liberate)(void * ptr, void * moreContext);
    size_t length;
    size_t maxLength;
    size_t elemSize;
};

#endif
