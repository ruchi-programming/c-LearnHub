#include <stdio.h>
#include <string.h>

#define STRING_SIZE 200

int readLine(const char *prompt, char text[], size_t capacity)
{
    printf("%s", prompt);
    if (fgets(text, (int)capacity, stdin) == NULL) {
        return 0;
    }

    size_t length = strcspn(text, "\n");
    if (text[length] == '\n') {
        text[length] = '\0';
    } else {
        /* Discard remaining characters if the input line exceeded the buffer. */
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF) {
        }
    }
    return 1;
}

void displayCharacters(const char text[])
{
    for (int i = 0; text[i] != '\0'; ++i) {
        printf("text[%d] = %c\n", i, text[i]);
    }
}

int countVowels(const char text[])
{
    int count = 0;
    for (int i = 0; text[i] != '\0'; ++i) {
        char ch = text[i];
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
            ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
            ++count;
        }
    }
    return count;
}

int main(void)
{
    char text[STRING_SIZE];

    if (!readLine("Enter a line of text: ", text, sizeof text)) {
        printf("Unable to read input.\n");
        return 1;
    }

    printf("String: %s\n", text);
    printf("Length (excluding null character): %zu\n", strlen(text));
    printf("Characters:\n");
    displayCharacters(text);
    printf("Vowel count: %d\n", countVowels(text));

    return 0;
}
