#include <unistd.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "myMalloc.h"

Block *head = NULL;

void *my_malloc(size_t size) {

    if(size < 0){
        return NULL;
    }

    size_t totalSize = size + sizeof(Block);

    void *ptr = sbrk(totalSize);

    if(ptr == (void *)-1){
        return NULL;
    }

    Block *newBlock = (Block *)ptr;
    newBlock->size = size;
    newBlock->free = 1;
    newBlock->next = NULL;
    
    if(head == NULL){
        head = newBlock;
    }else{
        Block *aux = head;
        while(aux->next != NULL){
            aux = aux->next;
        };
        aux->next = newBlock;
    }

    return (void *)(newBlock+1);
    
}
