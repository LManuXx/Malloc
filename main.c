#include <stdio.h>
#include <stdlib.h>
#include "myMalloc.h"

int main()
{
    int * num;
    num = my_malloc(sizeof(int));
    printf("Current sbrk: %p \n", num);

    return 0;   
}
