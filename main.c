#include <stdio.h>
#include <stdlib.h>
#include "myMalloc.h"

int main()
{
    printf("Se ejecuta myMalloc:\n");
    my_malloc(sizeof(int));  

    return 0;   
}
