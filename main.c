#include <stdio.h>
#include <stdlib.h>
#include "myMalloc.h"

int main()
{
    int *num = (int *)my_malloc(sizeof(int));
    int *num2 = (int *)my_malloc(sizeof(int));
    char *ch = (char *)my_malloc(sizeof(int));
    float *fl = (float *)my_malloc(sizeof(int));
    if (num == NULL) 
    {
        printf("Error al asignar memoria.\n");
        return 1;
    }

    my_free(num);    

    return 0;   
}
