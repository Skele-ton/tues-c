#include <stdio.h>
#include "quadraticRoots.h"

int main()
{
    // int example
    // x1 = 2 x2 = 3
    // x^2 - 5x + 6 = 0
    int a = 1;
    int b = -5;
    int c = 6;

    // float example
    // x1 = 2.5 x2 = 3.5
    // x^2 - 6x + 8.75 = 0
    // float a = 1;
    // float b = -6;
    // float c = 8.75;

    // double example
    // x1 = 2.5 x2 = 3.5
    // x^2 - 6x + 8.75 = 0
    // double a = 1;
    // double b = -6;
    // double c = 8.75;

    QuadraticRootsResult result = findRoots(a, b, c);

    if (result.noRealRoots)
        printf("The quadratic equation has no real roots;\n");
    else
        printf("x1 = %Lf; x2 = %Lf;\n", result.x1, result.x2);

    return 0;
}