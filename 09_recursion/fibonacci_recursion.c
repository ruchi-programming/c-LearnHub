#include <stdio.h>

/* Educational recursive version; exponential-time for larger n. */
unsigned long long fibonacci(unsigned int n)
{
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main(void)
{
    unsigned int n;

    printf("Enter an index (0-40): ");
    if (scanf("%u", &n) != 1 || n > 40) {
        printf("Enter a value from 0 to 40.\n");
        return 1;
    }

    printf("Fibonacci(%u) = %llu\n", n, fibonacci(n));
    return 0;
}
