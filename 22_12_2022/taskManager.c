#include <stdio.h>
#include <string.h>

#include "processes.h"

extern Process processes[PROCESSES_LENGTH];

// Operation Handling Functions
static void handleCreateProcess()
{
    char processName[MAX_NAME_LEN];

    printf("Enter the name of the process:\n");
    printf("> ");
    scanf("%s", &processName);

    int processId = createProcess(processName);

    if (processId == 0)
    {
        printf("An error occurred while creating this process.\n");
        printf("This may be the result of having more processes than the allowed (%d processes).\n", PROCESSES_LENGTH);
        printf("Another reason may be running out of ids to use.\n");
        return;
    }

    printf("\nProcess created:\n");
    printf("ID: %d\n", processId);
    printf("Name: %s\n", processName);
}

// Utility Function For "listProcesses" Function
static void printProcess(Process process)
{
    if (process.id == 0)
        return;

    printf("ID: %d\n", process.id);
    printf("Name: %s\n\n", process.name);
}

static void handleListProcesses()
{
    for (int i = 0; i < PROCESSES_LENGTH; i++)
        printProcess(processes[i]);
}

static void handleKillProcess()
{
    int id;

    printf("Input process ID: ");
    scanf("%d", &id);

    int processKilled = killProcess(id);

    if (processKilled)
        printf("\nProcess killed successfully.\n");
    else
        printf("\nCouldn't kill this process.\nThis is likely due to this ID not existing.\n");
}

// Utility Functions
static void getOperationInput(int *operation)
{
    printf("\n\n");

    printf("Please select an operation:\n");
    printf("1. Create Process\n");
    printf("2. List All Processes\n");
    printf("3. Kill Process\n");
    printf("4. Quit Program\n");

    printf("> ");

    scanf("%d", operation);

    printf("\n");
}

static int handleOperation(int *operation)
{
    switch (*operation)
    {
    case 1:
        handleCreateProcess();
        break;

    case 2:
        handleListProcesses();
        break;

    case 3:
        handleKillProcess();
        break;

    case 4:
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