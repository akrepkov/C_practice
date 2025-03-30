// Write a function int is_power_of_2(unsigned int n); that checks if a given number is a power of 2.

// Return 1 if the number is a power of 2, 0 otherwise.
// is_power_of_2(4)   // returns 1
// is_power_of_2(0)   // returns 0
// is_power_of_2(1)   // returns 1

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	    is_power_of_2(unsigned int n)
{
	if (n == 0) return 0;
	return ((n & (-n)) == n ? 1 : 0);
}

int main(){
	printf("%d\n", is_power_of_2(0));
	printf("%d\n", is_power_of_2(1));
	printf("%d\n", is_power_of_2(2));
	printf("%d\n", is_power_of_2(16));
	printf("%d\n", is_power_of_2(31));

}

/*
n binary, these numbers have only one bit set to 1, like this:
1 = 0001
2 = 0010
4 = 0100
8 = 1000

-n in bits is represented as flipped n and added 1: 
 4 = 0000 0100
-4 = 1111 1011 + 1 = 1111 1100


When you do n & (-n), the result is the lowest bit that is set to 1 in the binary representation of n. For numbers that are powers of 2, 
they have only one 1 bit, so n & (-n) will give you back the same number as n.



*/