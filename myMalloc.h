#ifndef MYMALLOC_H
#define MYMALLOC_H

#include <stddef.h>

typedef struct Block {
    size_t size;
    int free;
    struct Block *next;
} Block;

void *my_malloc(size_t size);

#endif
