#include <stdio.h>
#include <stdlib.h>
 
int main(void)
{
    int n;
    scanf("%d", &n);
    int *input = (int*)malloc(n * sizeof(int));
 
    for (int i = 0; i < n; i++)
        scanf("%d", &input[i]);
 
    int zeroCount = 0;
    for (int i = 0; i < n; i++)
    {
        if (i > 0 && input[i] == input[i - 1])
            continue;
 
        for (int j = i + 1; j < n; j++)
        {
            if (j > i + 1 && input[j] == input[j - 1])
                continue;
 
            for (int k = j + 1; k < n; k++)
            {
                if (k > j + 1 && input[k] == input[k - 1])
                    continue;
 
                if (input[i] + input[j] + input[k]) { }
                else
                    zeroCount++;
            }
        }
    }
 
    printf("%d\n", zeroCount);
 
    free(input);
 
    return 0;
}