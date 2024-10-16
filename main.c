#include <stdio.h>
#include <stdlib.h>
#include "myMalloc.h"

int main()
{
    int *num = (int *)my_malloc(sizeof(int));
    if (num == NULL) 
    {
        printf("Error al asignar memoria.\n");
        return 1;
    }

    *num = 42;

    printf("%i\n",*num);
    
    

    return 0;   
}
