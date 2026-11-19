#include <stdio.h>

/* Prints a message n times; demonstrates the base and recursive cases. */
void printMessageNTimes(unsigned int n)
{
    if (n == 0) {
        return; /* Base case */
    }

    printf("Hello\n");
    printMessageNTimes(n - 1); /* Recursive case */
}

unsigned long long factorial(unsigned int n)
{
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

unsigned long long sumNaturalNumbers(unsigned int n)
{
    if (n == 0) {
        return 0;
    }
    return n + sumNaturalNumbers(n - 1);
}

/*
 * Simple recursive Fibonacci for demonstration.
 * It is intentionally limited because this implementation repeats work.
 */
unsigned long long fibonacci(unsigned int n)
{
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main(void)
{
    unsigned int n;

    printMessageNTimes(3);

    printf("Enter n for factorial (0-20): ");
    if (scanf("%u", &n) != 1 || n > 20) {
        printf("Enter a value from 0 to 20.\n");
        return 1;
    }
    printf("%u! = %llu\n", n, factorial(n));

    printf("Enter n for sum of natural numbers (0-1000): ");
    if (scanf("%u", &n) != 1 || n > 1000) {
        printf("Enter a value from 0 to 1000.\n");
        return 1;
    }
    printf("Sum = %llu\n", sumNaturalNumbers(n));

    printf("Enter Fibonacci index (0-40): ");
    if (scanf("%u", &n) != 1 || n > 40) {
        printf("Enter a value from 0 to 40.\n");
        return 1;
    }
    printf("Fibonacci(%u) = %llu\n", n, fibonacci(n));

    printf("Fibonacci series: ");
    for (unsigned int i = 0; i < 10; ++i) {
        printf("%llu ", fibonacci(i));
    }
    printf("\n");

    return 0;
}
