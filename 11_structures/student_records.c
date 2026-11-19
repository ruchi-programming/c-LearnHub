#include <stdio.h>

#define COUNT 3

struct Student {
    int rollNumber;
    char name[40];
    float marks;
};

int main(void)
{
    struct Student students[COUNT];

    for (int i = 0; i < COUNT; ++i) {
        printf("Student %d roll number: ", i + 1);
        if (scanf("%d", &students[i].rollNumber) != 1) return 1;

        printf("Student %d name (one word): ", i + 1);
        if (scanf("%39s", students[i].name) != 1) return 1;

        printf("Student %d marks: ", i + 1);
        if (scanf("%f", &students[i].marks) != 1) return 1;
    }

    printf("\nStudent records:\n");
    for (int i = 0; i < COUNT; ++i) {
        printf("%d | %s | %.2f\n",
               students[i].rollNumber, students[i].name, students[i].marks);
    }

    return 0;
}
