#include "bitState.h"

uint bitState = 0;

int bitPositionValid(int bitPosition)
{
    if (bitPosition > 31 || bitPosition < 0)
        return 0;

    return 1;
}

int isBitSet(int bitPosition)
{
    if (!bitPositionValid)
        return -1;

    uint bitMask = 1 << bitPosition;

    return bitState & bitMask;
}

uint setBitToOne(int bitPosition)
{
    if (!bitPositionValid(bitPosition))
        return bitState;

    uint bitMask = 1 << bitPosition;

    bitState |= bitMask;

    return bitState;
}

uint setBitToZero(int bitPosition)
{
    if (!bitPositionValid(bitPosition))
        return bitState;

    uint bitMask = 1 << bitPosition;

    bitState &= ~bitMask;

    return bitState;
}

uint toggleBit(int bitPosition)
{
    if (isBitSet(bitPosition))
        setBitToZero(bitPosition);
    else
        setBitToOne(bitPosition);
}

uint getBitState()
{
    return bitState;
}