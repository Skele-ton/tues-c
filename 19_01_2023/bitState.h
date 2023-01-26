#ifndef BIT_STATE_H
#define BIT_STATE_H

#define uint unsigned int

int bitPositionValid(int bitPosition);
int isBitSet(int bitPosition);

uint setBitToOne(int bitPosition);
uint setBitToZero(int bitPosition);
uint toggleBit(int bitPosition);

uint getBitState();

#endif