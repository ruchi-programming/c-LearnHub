#include <stdio.h>

/* Returns the number of decimal digits; zero has one digit. */
int countDigits(int number)
{
    int count = 0;
    do {
        ++count;
        number /= 10;
    } while (number != 0);
    return count;
}

int sumDigits(int number)
{
    int sum = 0;
    do {
        sum += number % 10;
        number /= 10;
    } while (number != 0);
    return sum;
}

int reverseNumber(int number)
{
    int reversed = 0;
    while (number != 0) {
        reversed = reversed * 10 + number % 10;
        number /= 10;
    }
    return reversed;
}

int isPalindrome(int number)
{
    return number >= 0 && number == reverseNumber(number);
}

int isArmstrong(int number)
{
    if (number < 0) {
        return 0;
    }

    int original = number;
    int digits = countDigits(number);
    int total = 0;

    do {
        int digit = number % 10;
        int power = 1;

        for (int i = 0; i < digits; ++i) {
            power *= digit;
        }

        total += power;
        number /= 10;
    } while (number != 0);

    return total == original;
}

int isPrime(int number)
{
    if (number < 2) {
        return 0;
    }

    for (int divisor = 2; divisor <= number / divisor; ++divisor) {
        if (number % divisor == 0) {
            return 0;
        }
    }
    return 1;
}

int main(void)
{
    int number;

    printf("Enter a non-negative integer: ");
    if (scanf("%d", &number) != 1 || number < 0) {
        printf("Please enter a non-negative integer.\n");
        return 1;
    }

    printf("Digits: %d\n", countDigits(number));
    printf("Sum of digits: %d\n", sumDigits(number));
    printf("Reverse: %d\n", reverseNumber(number));
    printf("Palindrome: %s\n", isPalindrome(number) ? "Yes" : "No");
    printf("Armstrong: %s\n", isArmstrong(number) ? "Yes" : "No");
    printf("Prime: %s\n", isPrime(number) ? "Yes" : "No");

    return 0;
}
