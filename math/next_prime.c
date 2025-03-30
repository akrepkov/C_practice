// Write a program that finds the next prime number after a given integer n. The program should take an integer n as input and output the smallest prime number that is greater than n.

// The function should efficiently check if numbers are prime and keep searching until it finds the next prime.

// If n is a prime number itself, the program should still find the next prime that is strictly greater than n.

// Example:
// For input 16, the output should be 17.

// For input 17, the output should be 19.


#include <stdio.h>
#include <math.h>


int is_prime(int n){
    if (n <= 1) return 0;
    if (n == 2 || n == 3) return 1;
    if (n % 2 == 0 || n % 3 == 0) return 0;
    for (int i = 5; i < n; i+=6){
        if (n % i == 0)
            return 0;
        if (n % (i+2) == 0)
            return 0;
    }
    return 1;
}
//formula for prime numbers: 6k +- 1:
//we start from 5 and check 6 * 1 +-1 =>5 and 7
int next_prime(int n){
    n++;
    while(!is_prime(n))
        n++;
    return n;
}

int main() {
    int n = 16;
    printf("Next prime after %d is %d\n", n, next_prime(n));
    return 0;
}