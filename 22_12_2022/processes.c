#include <string.h>
#include <limits.h>

#include "processes.h"

int processCount = 0;

static int generateProcessId()
{
    static int nextId = 1;

    if (nextId == INT_MAX)
        return 0;

    return nextId++;
}

int createProcess(char processName[MAX_NAME_LEN])
{
    int id = generateProcessId();

    Process newProcess;
    newProcess.id = id;
    strcpy(newProcess.name, processName);

    if (processCount >= 5)
        return 0;

    processes[processCount++] = newProcess;

    return id;
}

// Util Function
static void pushEmptyProcessesToEnd()
{
    int j = 0;

    for (int i = 0; i < PROCESSES_LENGTH; i++)
    {
        if (processes[i].id != 0)
        {
            Process temp = processes[i];
            processes[i] = processes[j];
            processes[j++] = temp;
        }
    }
}

int killProcess(int processId)
{
    int found = 0;

    for (int i = 0; i < PROCESSES_LENGTH; i++)
        if (processes[i].id == processId)
        {
            processes[i].id = 0;
            processCount--;
            found = 1;
        }

    if (found)
    {
        pushEmptyProcessesToEnd();
        return 1;
    }
    else
        return 0;
}