#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 100

int main() {
    char command[MAX_COMMAND_LENGTH];

    while (1) {
        printf("Shell> ");

        if (fgets(command, sizeof(command), stdin) == NULL) {
            // Handle end of file (Ctrl+D)
            printf("\n");
            break;
        }

        command[strcspn(command, "\n")] = '\0';

        execute_command(command);
    }

    return 0;
}
