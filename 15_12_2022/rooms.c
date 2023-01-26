#include <stdio.h>

int main()
{
    unsigned char rooms = 0;
    int operation;

    while (1)
    {
        printf("Select an operation:\n");
        printf("1. Toggle Lights\n");
        printf("2. Check Lights\n");
        printf("3. Exit\n");

        do
        {
            printf("> ");
            scanf("%d", &operation);
            printf("\n");
        } while (operation < 1 || operation > 3);

        if (operation == 1)
        {
            int roomNumber;

            do
            {
                printf("Please select a room: ");
                scanf("%d", &roomNumber);
                printf("\n");
            } while (roomNumber < 1 || roomNumber > 8);

            rooms ^= (1 << roomNumber - 1);
        }
        else if (operation == 2)
        {
            int lightsOffFlag = 1;

            printf("Lights are on in rooms:");

            for (int i = 0; rooms >> i > 0; i++)
            {
                if ((rooms >> i) & 1)
                {
                    printf(" %d", i + 1);

                    if (lightsOffFlag)
                        lightsOffFlag = 0;
                }
            }

            if (lightsOffFlag)
                printf(" X;\nLights are off in all rooms.");

            printf("\n\n");
        }
        else if (operation == 3)
            break;
    }

    return 0;
}