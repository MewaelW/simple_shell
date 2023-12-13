#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

void execute_command(char* command) {
    pid_t pid = fork();
    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    } else if (pid == 0) {
        // Child process
        execlp(command, command, NULL);
        // If execlp returns, it means the command execution failed
        // Print an error message and exit
        printf("Command not found: %s\n", command);
        exit(1);
    } else {
        // Parent process
        waitpid(pid, NULL, 0);
    }
}
