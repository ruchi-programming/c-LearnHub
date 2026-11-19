#include <stdio.h>
#include <string.h>
#include <ctype.h>

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
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF) {
        }
    }
    return 1;
}

void copyString(char destination[], const char source[], size_t capacity)
{
    if (capacity == 0) {
        return;
    }

    strncpy(destination, source, capacity - 1);
    destination[capacity - 1] = '\0';
}

void reverseString(char text[])
{
    size_t left = 0;
    size_t right = strlen(text);

    if (right == 0) {
        return;
    }
    --right;

    while (left < right) {
        char temporary = text[left];
        text[left] = text[right];
        text[right] = temporary;
        ++left;
        --right;
    }
}

int isPalindromeString(const char text[])
{
    size_t left = 0;
    size_t right = strlen(text);

    if (right == 0) {
        return 1;
    }
    --right;

    while (left < right) {
        if (tolower((unsigned char)text[left]) !=
            tolower((unsigned char)text[right])) {
            return 0;
        }
        ++left;
        --right;
    }
    return 1;
}

int main(void)
{
    char first[STRING_SIZE];
    char second[STRING_SIZE];
    char copy[STRING_SIZE];
    char reversed[STRING_SIZE];

    if (!readLine("Enter first string: ", first, sizeof first) ||
        !readLine("Enter second string: ", second, sizeof second)) {
        printf("Unable to read input.\n");
        return 1;
    }

    copyString(copy, first, sizeof copy);
    copyString(reversed, first, sizeof reversed);
    reverseString(reversed);

    printf("Length of first string: %zu\n", strlen(first));
    printf("Copied string: %s\n", copy);
    printf("Comparison (strcmp): %d\n", strcmp(first, second));
    printf("Reversed first string: %s\n", reversed);
    printf("First string palindrome (case-insensitive): %s\n",
           isPalindromeString(first) ? "Yes" : "No");

    if (strlen(first) + strlen(second) < sizeof first) {
        strcat(first, second);
        printf("Concatenated string: %s\n", first);
    } else {
        printf("Strings cannot be concatenated within the available buffer.\n");
    }

    return 0;
}
