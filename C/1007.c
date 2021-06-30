#include <stdio.h>
#include <stdlib.h>

int getMin(int arr[], int size)
{
    int min = arr[0];
    for (int i = 0; i < size; i++)
    {
        if (arr[i] < min)
            min = arr[i];
    }

    return min;
}

int getMax(int arr[], int size)
{
    int max = arr[0];
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }

    return max;
}

int getIndex(int target, int min)
{
    return target - min;
}

int main(void)
{
    // input.
    int n;                  // The number of test cases.
    scanf("%d", &n);
    int *results = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        int m;              // The number of elements of particular test case.
        scanf("%d", &m);
        int *input = (int*)malloc(m * sizeof(int));
        for (int i = 0; i < m; i++) scanf("%d", &input[i]);

        // map into redundancy check array;
        int min = getMin(input, m);
        int max = getMax(input, m);

        int size = max - min + 1;
        int *redundancyCount = (int*)malloc(size * sizeof(int));
        for (int i = 0; i < size; i++)
            redundancyCount[i] = 0;

        for (int i = 0; i < m; i++)
            redundancyCount[getIndex(input[i], min)]++;

        // check if the redandancy count for certain number is 1 or not.
        int uniqueNumber = 0;
        for (int i = 0; i < m; i++)
        {
            if (redundancyCount[getIndex(input[i], min)] == 1)
            {
                uniqueNumber = input[i];
                break;
            }
        }

        results[i] = uniqueNumber;

        free(input);
        free(redundancyCount);
    }

    for (int i = 0; i < n; i++)
        printf("%d\n", results[i]);

    free(results);

    return 0;
}