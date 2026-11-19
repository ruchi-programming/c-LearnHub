#include <stdio.h>

int main(void)
{
    int age;
    float height;

    printf("Enter your age and height in metres: ");
    if (scanf("%d %f", &age, &height) != 2) {
        printf("Invalid input.\n");
        return 1;
    }

    printf("Age: %d\nHeight: %.2f m\n", age, height);
    return 0;
}
