#include <stdio.h>

#include "bitState.h"

// Operation Handling Functions
static void handleTurnDiodeOn()
{
    int bitPosition;

    printf("Select Bit To Turn On: ");
    scanf("%d", &bitPosition);

    bitPosition--;

    if (!bitPositionValid(bitPosition))
    {
        printf("This bit position is not valid; Please try again;\n");
        handleTurnDiodeOn();
        return;
    }

    setBitToOne(bitPosition);
    printf("Turned Diode On;\n");
}

static void handleTurnDiodeOff()
{
    int bitPosition;

    printf("Select Bit To Turn Off: ");
    scanf("%d", &bitPosition);

    bitPosition--;

    if (!bitPositionValid(bitPosition))
    {
        printf("This bit position is not valid; Please try again;\n");
        handleTurnDiodeOff();
        return;
    }

    setBitToZero(bitPosition);
    printf("Turned Diode Off;\n");
}

static void handleToggleDiode()
{
    int bitPosition;

    printf("Select Bit To Toggle: ");
    scanf("%d", &bitPosition);

    bitPosition--;

    if (!bitPositionValid(bitPosition))
    {
        printf("This bit position is not valid; Please try again;\n");
        handleTurnDiodeOff();
        return;
    }

    toggleBit(bitPosition);
    printf("Toggled Diode;\n");
}

static void handleCheckDiodeState()
{
    int bitPosition;

    printf("Select Bit To Check: ");
    scanf("%d", &bitPosition);

    bitPosition--;

    if (!bitPositionValid(bitPosition))
    {
        printf("This bit position is not valid; Please try again;\n");
        handleTurnDiodeOff();
        return;
    }

    if (isBitSet(bitPosition))
        printf("Diode Is Currently On;\n");
    else
        printf("Diode Is Currently Off;\n");
}

static void handleCheckAllDiodesState()
{
    char allOff = 1;

    printf("Diodes turned on:");

    for (int i = 0; i < 32; i++)
    {
        int bitMask = 1 << i;

        if (getBitState() & bitMask)
        {
            if (allOff)
                allOff = 0;
            printf(" %d", i + 1);
        }
    }

    if (allOff)
        printf("\nNo diodes on;\n\n");
}

// Utility Functions
static void getOperationInput(int *operation)
{
    printf("\n\n");

    printf("Please select an operation:\n");
    printf("1. Turn Diode On\n");
    printf("2. Turn Diode Off\n");
    printf("3. Toggle Diode\n");
    printf("4. Check Diode State\n");
    printf("5. Check All Diodes State\n");
    printf("6. Quit Program\n");

    printf("> ");

    scanf("%d", operation);

    printf("\n");
}

static int handleOperation(int *operation)
{
    switch (*operation)
    {
    case 1:
        handleTurnDiodeOn();
        break;

    case 2:
        handleTurnDiodeOff();
        break;

    case 3:
        handleToggleDiode();
        break;

    case 4:
        handleCheckDiodeState();
        break;

    case 5:
        handleCheckAllDiodesState();
        break;

    case 6:
        return 1;
        break;

    default:
        printf("Invalid input. Please try again.\n");
        getOperationInput(operation);
    }

    return 0;
}

int main()
{
    int operation;

    while (1)
    {
        getOperationInput(&operation);

        int shouldBreak = handleOperation(&operation);

        if (shouldBreak)
            break;
    }

    return 0;
}