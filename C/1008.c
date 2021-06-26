#include <stdio.h>
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

int main(void)
{
    // logging stuffs.
    bool printDecimalPoint = true;

    // input.
    int A, B;
    scanf("%d %d", &A, &B);

    double decimal = (double)A / B;

    if (printDecimalPoint)
    {
        printf("\nCALCULATED DECIMAL POINT NUMBER:\n");
        printf("%.24lf\n\n", decimal);
    }

    // implementation of finding repeating part.
    int repeatingPart = findRepeating(decimal, 1, 24, 4, 3);

    // printing result.
    printf("%d\n", repeatingPart);

    return 0;
}