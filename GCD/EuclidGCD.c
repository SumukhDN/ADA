//Finding GCD using Euclid's Algorithm

#include <stdio.h>

int findGCD(int num1, int num2) {
    while (num2 != 0) {
        int temp = num2;
        num2 = num1 % num2;
        num1 = temp;
    }
    return num1;
}

int main() {
    int number1 = 48, number2 = 18;
    int gcd = findGCD(number1, number2);
    printf("GCD of %d and %d is: %d\n", number1, number2, gcd);
    return 0;
}
