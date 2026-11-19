#include <stdio.h>

int gcd(int a, int b)
{
    while (b != 0) {
        int remainder = a % b;
        a = b;
        b = remainder;
    }
    return a;
}

int main(void)
{
    int a, b;

    printf("Enter two non-negative integers: ");
    if (scanf("%d %d", &a, &b) != 2 || a < 0 || b < 0 || (a == 0 && b == 0)) {
        printf("Invalid input. At least one value must be positive.\n");
        return 1;
    }

    int common = gcd(a, b);
    printf("GCD: %d\n", common);
    printf("LCM: %d\n", (a / common) * b);
    return 0;
}
