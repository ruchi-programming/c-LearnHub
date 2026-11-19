#include <stdio.h>

void countdown(int n)
{
    if (n == 0) {              /* Base case */
        printf("Go!\n");
        return;
    }

    printf("%d\n", n);         /* Work before recursive call */
    countdown(n - 1);          /* Recursive case */
}

unsigned long long factorial(unsigned int n)
{
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

int main(void)
{
    unsigned int n;

    countdown(5);

    printf("Enter n for factorial (0-20): ");
    if (scanf("%u", &n) != 1 || n > 20) {
        printf("Enter a value from 0 to 20.\n");
        return 1;
    }

    printf("%u! = %llu\n", n, factorial(n));
    return 0;
}
