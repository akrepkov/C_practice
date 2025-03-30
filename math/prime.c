// Write a program that takes a positive integer as input and prints its prime factors in ascending order, separated by '*', such that the output forms a correct factorization expression.

// If the number of parameters is not exactly 1, the program should simply print a newline.

// If there is valid input, the factors are printed in the correct order.

// If the input number is 1, the output should be just 1.

// $> ./fprime 60
// 2*2*3*5
// $> ./fprime 36
// 2*2*3*3
// $> ./fprime 17
// 17
// $> ./fprime 64
// 2*2*2*2*2*2
// $> ./fprime 1001
// 7*11*13
// $> ./fprime 1234567
// 127*9721
// $> ./fprime 1
// 1


#include <stdio.h>
#include <stdlib.h>

void fprime(int n) {
    int first = 1;

    if (n == 1) {
        printf("1");
    } else {
        for (int i = 2; i * i <= n; i++) {
            while (n % i == 0 ) {
                if (!first) {
                    printf("*");
                }
                printf("%d", i);
                n /= i;
                first = 0;
            }
        }
        if (n > 1) {
            if (!first) {
                printf("*");
            }
            printf("%d", n);
        }
    }
    printf("\n");
}

int main(int argc, char **argv) {
    if (argc == 2) {
        int n = atoi(argv[1]);
        if (n > 0) {
            fprime(n);
        }
    } else {
        printf("\n");
    }
    return 0;
}