#ifndef PROCESSES_H
#define PROCESSES_H

#define PROCESSES_LENGTH 5
#define MAX_NAME_LEN 30

typedef struct
{
    int id;
    char name[MAX_NAME_LEN];
} Process;

Process processes[PROCESSES_LENGTH];
int processesCount;

static int generateProcessId();
int createProcess(char processName[MAX_NAME_LEN]);
int killProcess(int processId);

#endif