#define _DEFAULT_SOURCE
#include <sys/mman.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include "myMalloc.h"


Block *head = NULL;

void *my_malloc(size_t size) 
{
    if (size == 0) 
    {
        printf("\nError: tamaño 0 no es válido\n");
        return NULL;
    }

    size_t totalSize = (size + sizeof(Block) + 7) & ~7;

    void *ptr = mmap(NULL, totalSize, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS , -1, 0);

    if (ptr == MAP_FAILED) 
    {
        printf("\nError: no se pudo asignar memoria con mmap\n");
        return NULL;
    }

    Block *newBlock = (Block *)ptr;
    newBlock->free = 0;
    newBlock->size = size;
    newBlock->next = NULL;

    printf("\nBloque asignado en: %p, tamaño solicitado: %zu\n", (void *)newBlock, size);

    if (head == NULL) 
    {
        head = newBlock;
    } 
    else 
    {
        Block *aux = head;
        while (aux->next != NULL) 
        {
            aux = aux->next;
        }
        aux->next = newBlock;
    }

    return (void *)(newBlock + 1);
}
