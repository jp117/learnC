#include <stdio.h>
#include <string.h>

#define MAX_INPUT 100

int main() {
    char input[MAX_INPUT];

    printf("Welcome to your To-Do List\n");
    printf("Commands: add [task], list, delete [id], quit\n");

    while (1)
    {
        printf("> ");
        if (fgets(input, MAX_INPUT, stdin) == NULL) break;

        input[strcspn(input, "\n")] = '\0';

        if (strncmp(input, "add ", 4) == 0) {
            printf("Adding task: %s\n", input + 4);
        } else if (strcmp(input, "list") == 0) {
            printf("Listing tasks...\n");
        } else if (strncmp(input, "delete ", 7) == 0) {
            printf("Deleting task ID: %s\n", input + 7);
        } else if (strcmp(input, "quit") == 0 || strcmp(input, "exit") == 0) {
            printf("Goodbye!\n");
            break;
        } else {
            printf("Unknown command.\n");
        }

    }
    

    return 0;
}