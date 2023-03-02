#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

int main()
{
    FILE* fp = fopen("jbcrdb.tsv", "r");
    if (fp == NULL) {
        printf("Error: Cannot open file.\n");
        return -1;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, fp)) {
        // Extract fields from the TSV line
        char* num_str = strtok(line, "\t");
        char* question_str = strtok(NULL, "\t");
        char* choice1_str = strtok(NULL, "\t");
        char* choice2_str = strtok(NULL, "\t");
        char* choice3_str = strtok(NULL, "\t");
        char* choice4_str = strtok(NULL, "\t");
        char* num2_str = strtok(NULL, "\t");

        // Print the question and choices
        printf("%s. %s. %s\n", num_str, question_str,num2_str);
        printf("    A. %s\n", choice1_str);
        printf("    B. %s\n", choice2_str);
        printf("    C. %s\n", choice3_str);
        printf("    D. %s\n", choice4_str);
    }

    fclose(fp);
    return 0;
}