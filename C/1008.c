#include <stdio.h>
#include <stdbool.h>

int pow(int i, int n)
{
    int result = 1;
    for (int j = 0; j < n; j++)
        result *= i;

    return result;
}

// get 1st to length-th decimal place number.
int getDecimalPointLength(double decimal, int length)
{
    decimal -= (int)decimal;
    decimal *= pow(10, length);

    return (int)decimal;
}

// get start-th to end-th decimal place number.
int getDecimalPoint(double decimal, int start, int end)
{
    int startInt = getDecimalPointLength(decimal, start - 1);
    int endInt = getDecimalPointLength(decimal, end);

    int result = endInt - startInt * pow(10, end - start + 1);

    return result;
}

bool decimalPointMatch(double decimal, int length)
{
}

int main(void)
{
    // logging stuffs.
    bool printDecimalPoint = false;

    // input.
    int A, B;
    scanf("%d %d", &A, &B);

    double decimal = (double)A / B;

    if (printDecimalPoint)
    {
        printf("\nCALCULATED DECIMAL POINT NUMBER:\n");
        printf("%.24lf\n\n", decimal);
    }

    printf("%d\n", getDecimalPoint(decimal, 4, 6));

    return 0;
}