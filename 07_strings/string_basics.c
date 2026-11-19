#include <stdio.h>
#include <string.h>

#define SIZE 100

int main(void)
{
    char text[SIZE];

    printf("Enter a line of text: ");
    if (fgets(text, sizeof text, stdin) == NULL) {
        printf("Input error.\n");
        return 1;
    }

    text[strcspn(text, "\n")] = '\0';

    printf("Text: %s\n", text);
    printf("Length: %zu\n", strlen(text));
    printf("Characters (including spaces):\n");

    for (size_t i = 0; text[i] != '\0'; ++i) {
        printf("text[%zu] = %c\n", i, text[i]);
    }

    return 0;
}
