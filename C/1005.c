#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quickSort(int x[], int L, int R )
{
	int i = L, j = R, tmp;
	int pivot = x[(L + R) / 2];

	while (i <= j)
	{
		while (x[i] < pivot)
			i++;
		while (x[j] > pivot)
			j--;

		if (i <= j)
		{
			tmp = x[i];
			x[i] = x[j];
			x[j] = tmp;
			i++, j--;
		}
	}

	if (L < j)
		quickSort(x, L, j);
	if (i < R)
		quickSort(x, i, R);
}

int getIndex(int i, int j)
{
    return i * 2 + j;
}

int isThere(int target, int *array, int size)
{
    int l = 0;
    int r = size - 1;
    int m = (l + r) / 2;
    while (l <= r)
    {
        int temp = *(array + getIndex(m, 0));
        if (temp == target)
            return *(array + getIndex(m, 1));
        else if (temp > target)
        {
            r = m - 1;
            m = (l + r) / 2;
            continue;
        }
        else
        {
            l = m + 1;
            m = (l + r) / 2;
            continue;
        }
    }

    return 0;
}

int main(void)
{
    srand((unsigned int)time(NULL));
    // user input.
    int n = 10000;
    // scanf("%d", &n);
    int *input = (int*)malloc(n * sizeof(int));
    // for (int i = 0; i < n; i++)
    //     scanf("%d", &input[i]);

    for (int i = 0; i < n; i++)
    {
        input[i] = rand() % 1000 - 500;
    }

    time_t start = clock();
    quickSort(input, 0, n - 1);

    // set redundancy count array.
    int *redundancyCount = (int*)calloc(n * 2, sizeof(int));
    int redundancyIndex = 0;

    // redundancy count check.
    int temp = input[0];
    *(redundancyCount + getIndex(redundancyIndex, 0)) = temp;
    (*(redundancyCount + getIndex(redundancyIndex, 1)))++;
    for (int i = 1; i < n; i++)
    {
        if (temp != input[i])
        {
            temp = input[i];
            *(redundancyCount + getIndex(++redundancyIndex, 0)) = temp;
            (*(redundancyCount + getIndex(redundancyIndex, 1)))++;

            continue;
        }

        (*(redundancyCount + getIndex(redundancyIndex, 1)))++;
    }
    int redundancySize = redundancyIndex + 1;
    time_t end1 = clock();

    // int zeroCount = 0;
    // for (int i = 0; i < n; i += isThere(input[i], redundancyCount, redundancySize))
    // {
    //     if (i > 0 && input[i] == input[i - 1])
    //         continue;
 
    //     for (int j = i + 1; j < n; j += isThere(input[j], redundancyCount, redundancySize) - (input[j] == input[j - 1]))
    //     {
    //         if (j > i + 1 && input[j] == input[j - 1])
    //             continue;
 
    //         for (int k = j + 1; k < n; k += isThere(input[k], redundancyCount, redundancySize) - (input[k] == input[k - 1]))
    //         {
    //             if (k > j + 1 && input[k] == input[k - 1])
    //                 continue;
 
    //             if (input[i] + input[j] + input[k]) { }
    //             else
    //                 zeroCount++;
    //         }
    //     }
    // }

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
    free(redundancyCount);
    time_t end = clock();

    printf("%d\n", redundancySize);
    printf("%lf, %d\n", (double)(end1 - start) / CLOCKS_PER_SEC, (end1 - start));
    printf("%lf, %d", (double)(end - start) / CLOCKS_PER_SEC, (end - start));

    return 0;
}