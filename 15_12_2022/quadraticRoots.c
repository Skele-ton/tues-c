#include <math.h>
#include "quadraticRoots.h"

QuadraticRootsResult findRoots(ld a, ld b, ld c)
{
    QuadraticRootsResult result;
    result.noRealRoots = 0;

    ld D = powl(b, 2) - 4 * a * c;

    if (D < 0)
        result.noRealRoots = 1;
    else
    {
        result.x1 = (-b - sqrtl(D)) / (2 * a);
        result.x2 = (-b + sqrtl(D)) / (2 * a);
    }

    return result;
}