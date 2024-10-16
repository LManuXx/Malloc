#include <unistd.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "myMalloc.h"

Block *head = NULL;

void *my_malloc(size_t size) 
{

    if(size == 0)
    {
        printf("\nerror\n");
        return NULL;
    }
    
    size_t totalSize = (size + sizeof(Block) + 7) & ~7;
    void *ptr = sbrk(totalSize);
    
    if(ptr == (void *)-1)
    {
        return NULL;
    }
    
    Block *newBlock = (Block *)ptr;

    newBlock->free = 0;
    newBlock->size = size;
    newBlock->next = NULL;

    printf("\nBloque asignado en: %p, tamaño solicitado: %zu\n", newBlock, size);
    


    if(head == NULL)
    {
        head = newBlock;
    } else 
    {
        Block *aux = head;
        while(aux->next != NULL){
            aux = aux->next;
        };
        aux->next = newBlock;
    }

    return (void *)(newBlock + 1);
}
