#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>

void read_csv(const char *filename);
void parse_line(char *line);

void read_csv(const char *filename){
    FILE *file = fopen(filename, "r");
    if (!file){
        perror("Error opening the file");
        return;
    }

    char line[1024];
    while (fgets(line, sizeof(line), file)){
        parse_line(line);
    }

    fclose(file);
}

void parse_line(char *line) {
    line[strcspn(line, "\n")] = '\0';

    char *token = strtok(line, ",");
    while (token) {
        printf("Column: %s\n", token);
        token = strtok(NULL, ",");
    }
}

int main (){

    read_csv("data.csv");
    return 0;
}