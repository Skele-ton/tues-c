#ifndef QUADRATIC_ROOTS_H
#define QUADRATIC_ROOTS_H

#define ld long double

typedef struct
{
    ld x1;
    ld x2;
    char noRealRoots;
} QuadraticRootsResult;

QuadraticRootsResult findRoots(ld a, ld b, ld c);

#endif