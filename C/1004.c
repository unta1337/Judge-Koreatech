#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int intReverse(int input)
{
    int result = 0;
    while (input > 0)
    {
        result *= 10;
        result += input % 10;
        input /= 10;
    }

    return result;
}

bool isPelindrome(int input)
{
    int original = input;
    int reversed = intReverse(input);

    return original == reversed;
}

int main(void)
{
    int n;
    scanf("%d", &n);
    int *inputs = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
        scanf("%d", &inputs[i]);

    for (int i = 0; i < n; i++)
    {
        int temp = inputs[i] + intReverse(inputs[i]);

        if (isPelindrome(temp))
            printf("yes\n");
        else
            printf("no\n");
    }

    free(inputs);

    return 0;
}