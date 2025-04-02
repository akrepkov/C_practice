#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void mult(char* a, char* b){
	int len_max = strlen(a) + strlen(b);
	char *result = (char *)malloc(sizeof(char) * len_max + 1);
	int len1 = strlen(a);
	int len2 = strlen(b);
	int i = 0,j = 0, carry = 0, pos = 0;
	while(i <= len_max){
		result[i] = '0';
		i++;
	}
	result[i] = '\0';
	for (int i = len1 - 1; i >= 0; i--) {
			int carry = 0;
			int dig1 = a[i] - '0';
			for (int j = len2 - 1; j >= 0; j--) {
				int dig2 = b[j] - '0';
				pos = i + j + 1;
				int sum = (result[pos] - '0') + (dig1 * dig2) + carry;
				result[pos] = (sum % 10) + '0';
				carry = sum / 10;
			}
			result[i+j+1] = (result[i+j+1] - '0') + carry + '0';
		}
    size_t start_pos = 0;
    while (start_pos <= len_max - 1 && result[start_pos] == '0')
        start_pos++;
	while (start_pos <= len_max - 1){
    	write(1, &result[start_pos],1);
		start_pos++;
	}
    write(1, "\n", 1);
}

int main(){
	mult("10", "123");
	printf("Should be 1230\n");
	mult("1", "1");
	printf("Should be 1\n");
}
