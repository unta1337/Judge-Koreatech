#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *p = (int*)malloc(2 * 3 * sizeof(int));

    *(p + (3 * 0 + 0)) = 0;


    free(p);

    return 0;
}