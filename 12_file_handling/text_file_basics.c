#include <stdio.h>

int main(void)
{
    FILE *file = fopen("notes.txt", "w");
    if (file == NULL) {
        perror("Could not open notes.txt");
        return 1;
    }

    fprintf(file, "C file handling demonstration.\n");
    fprintf(file, "This line is stored in a text file.\n");

    if (fclose(file) != 0) {
        perror("Could not close file");
        return 1;
    }

    file = fopen("notes.txt", "r");
    if (file == NULL) {
        perror("Could not reopen notes.txt");
        return 1;
    }

    char line[120];
    while (fgets(line, sizeof line, file) != NULL) {
        printf("%s", line);
    }

    fclose(file);
    return 0;
}
