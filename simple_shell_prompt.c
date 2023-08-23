#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
int main() {
    char *command;
    while (1) {
        command = readline("$ ");
        if (!command) {
            printf("\n");
            break;
        }
        if (command[0] != '\0') {
            add_history(command);
        }
        printf("You entered: %s\n", command);
        free(command);
    }
    return (0);
}
