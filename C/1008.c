#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// get 1st to length-th decimal place number.
long long getDecimalPointLength(double decimal, int length)
{
    decimal -= (long long)decimal;
    for (int i = 0; i < length; i++)
        decimal *= 10;

    return (long long)decimal;
}

// get start-th to end-th decimal place number.
int getDecimalPoint(double decimal, int start, int end)
{
    long long startInt = getDecimalPointLength(decimal, start - 1);
    long long endInt = getDecimalPointLength(decimal, end);

    long long temp = startInt;
    for (int i = 0; i < end - start + 1; i++)
        temp *= 10;
    int result = endInt - temp;

    return result;
}

// find repeating pattern in decimal number.
int findRepeating(double decimal, int start, int limit, int length, int repeating)
{
    int repeatingCount = 0;
    int current = getDecimalPoint(decimal, start, start + length - 1);
    int repeatingPart = -1;
    for (int i = start + length; i < limit; i += length)
    {
        int prev = current;
        current = getDecimalPoint(decimal, i, i + length - 1);
        if (prev == current)
        {
            repeatingCount++;
            if (repeatingCount >= repeating)
            {
                repeatingPart = current;
                break;
            }
        }
        else
            break;
    }

    return repeatingPart;
}

int findRepeatingPatern(double decimal, int limit, int *start)
{
    int repeatingPart = -1;
    int length;
    for (length = 1; length <= 4; length++)
    {
        for (*start = 1; *start <= limit; *start += length)
        {
            int temp = findRepeating(decimal, *start, limit, length, 3);
            if (temp != -1)
            {
                repeatingPart = temp;
                return repeatingPart;
            }
        }
    }

    return repeatingPart;
}

void printRepeating(double decimal, int start, int repeatingPart)
{
    double decimal_ = decimal;
    for (int i = 0; i < start - 1; i++)
        decimal_ *= 10;
    decimal_ = (int)decimal_;
    for (int i = 0; i < start - 1; i++)
        decimal_ /= 10;
    if (decimal_ == 0)
        printf("0.");
    else
        printf("%g", decimal_);
    printf("(%d)\n", repeatingPart);
}

int main(void)
{
    // logging stuffs.
    bool printDecimalPoint = false;

    // input.
    int n;
    scanf("%d", &n);
    double *decimals = (double*)malloc(n * sizeof(double));
    int *starts = (int*)malloc(n * sizeof(int));
    int *repeatingParts = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        int A, B;
        scanf("%d %d", &A, &B);

        double decimal = (double)A / B;
        decimals[i] = decimal;

        if (printDecimalPoint)
        {
            printf("\nCALCULATED DECIMAL POINT NUMBER:\n");
            printf("%.24lf\n\n", decimal);
        }

        // implementation of finding repeating part.
        int start;
        int repeatingPart = findRepeatingPatern(decimal, 24, &start);
        starts[i] = start;
        repeatingParts[i] = repeatingPart;
    }

    // printing result.
    for (int i = 0; i < n; i++)
        printRepeating(decimals[i], starts[i], repeatingParts[i]);

    free(decimals);
    free(starts);
    free(repeatingParts);

    return 0;
}