#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>

#define MAX_INPUT 100

typedef struct task {
    char *task;
    struct task *next;
} task_t;

task_t *global_head = NULL;

void add_task(task_t **head, const char *task_str) {
   task_t *new_node = malloc(sizeof(task_t));
    if (!new_node) {
        fprintf(stderr, "Memory allocation failed!\n");
        return;
    }

    new_node->task = malloc(strlen(task_str) + 1); 
    if (!new_node->task) {
        free(new_node);
        fprintf(stderr, "String allocation failed!\n");
        return;
    }
    strcpy(new_node->task, task_str);
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
    } else {
        task_t *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

void list_tasks(task_t *head){
    int i = 1;
    task_t *current = head;

    if (!current) {
        printf("No tasks in the list\n");
        return;
    }

    while (current != NULL) {
        printf("%d. %s\n", i, current->task);
        current = current->next;
        i++;
    }
}

void delete_task(task_t **head, int index){
    if (*head == NULL || index < 1) return;

    task_t *current = *head;

    if (index == 1) {
        *head = current->next;
        free(current->task);
        free(current);
        return;
    }

    for (int i = 1; current != NULL && i < index - 1; i++) {
        current = current->next;
    }

    if (current == NULL || current->next == NULL) return;

    task_t *to_delete = current->next;
    current->next = to_delete->next;

    free(to_delete->task);
    free(to_delete);

}

void save_task(task_t *head){
    FILE *file = fopen("tasks.txt", "w");
    if (!file){
        perror("Failed to open file");
        return;
    }

    task_t *current = head;
    while (current != NULL){
        fprintf(file, "%s\n", current -> task);
        current = current -> next;
    }

    fclose(file);
}

void load_tasks(task_t **head){
    FILE *file = fopen("tasks.txt", "r");
    if (!file){
        return;
    }

    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, file)) != -1){
        if (line[read - 1] == '\n') line[read - 1] = '\0';
        add_task(head, line);
    }

    free(line);
    fclose(file);
}

void free_tasks(task_t *head){
    task_t *current = head;
    while (current != NULL){
        task_t *next = current->next;
        free(current->task);
        free(current);
        current = next;
    }
}

void handle_sigint(int sig) {
    printf("\nCaught Ctrl+C! Cleaning up...\n");
    free_tasks(global_head);
    exit(0);
}

int main() {
    signal(SIGINT, handle_sigint);
    
    char input[MAX_INPUT];
    task_t *head = NULL;

    printf("Welcome to your To-Do List\n");
    printf("Commands: add [task], list, delete [id], quit\n");
    load_tasks(&head);

    while (1)
    {
        printf("> ");
        if (fgets(input, MAX_INPUT, stdin) == NULL) break;

        input[strcspn(input, "\n")] = '\0';

        if (strncmp(input, "add ", 4) == 0) {
            printf("Adding task: %s\n", input + 4);
            char *task_text = input + 4;
            add_task(&head, task_text);
            save_task(head);
        } else if (strcmp(input, "list") == 0) {
            printf("Listing tasks...\n");
            list_tasks(head);
        } else if (strncmp(input, "delete ", 7) == 0) {
            printf("Deleting task ID: %s\n", input + 7);
            int delete_task_index = atoi(input + 7);
            delete_task(&head, delete_task_index);
            save_task(head);
        } else if (strcmp(input, "quit") == 0 || strcmp(input, "exit") == 0) {
            printf("Goodbye!\n");
            free_tasks(head);
            break;
        } else {
            printf("Unknown command.\n");
        }

    }   

    return 0;
}