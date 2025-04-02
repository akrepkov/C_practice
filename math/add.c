#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

void adding(char* a, char *b){
	int adder = 0;
	int len1 = strlen(a) - 1;
	int len2 = strlen(b) - 1;
	char *res = (char*)malloc(sizeof(char) * (strlen(a) + strlen(b) + 1));
	if (!res)
		return ;
	int j = 0;
	while(len1 >= 0 || len2 >= 0 || adder){
		int dig1 = len1 < 0 ? 0 : a[len1] - '0';
		int dig2 = len2 < 0 ? 0 : b[len2] - '0';
		int sum = dig1 + dig2 + adder;
		res[j] = sum % 10 + '0';
		adder = sum / 10;
		j++;
		len1--;
		len2--;
	}
	res[j] = '\0';
	j--;
	while(j >= 0){
		write(1, res + j, 1);
		j--;
	}
	write(1, "\n", 1);
}

void subtract(char*a, char* b){
	int borrow = 0;
	int len1 = strlen(a) - 1;
	int len2 = strlen(b) - 1;
	int j = 0;
	char *res = (char*)malloc(sizeof(char) * (strlen(a) + strlen(b) + 1));
	if (!res)
		return ;	
	while(len1 >= 0 || len2 >= 0 || borrow){
		int dig1 = len1 < 0 ? 0 : a[len1] - '0';
		int dig2 = len2 < 0 ? 0 : b[len2] - '0';
		int sub = dig1 - dig2 - borrow;
		if (sub < 0){
			sub += 10;
			borrow = 1;
		}
		else
			borrow = 0;
		res[j] = sub % 10 + '0';
		j++;
		len1--;
		len2--;
	}
	res[j] = '\0';
	j--;
	while(res[j] =='0' && j > 0){
		j--;
	}
	while(j >= 0){
		write(1, res + j, 1);
		j--;
	}
	write(1, "\n", 1);
}


int first_is_bigger(char* a, char* b){
	if (strlen(a) > strlen(b))
		return 0;
	else if (strlen(a) < strlen(b))
		return 1;
	int i = 0;
	while(a[i] != '\0' && b[i] != '0'){
		if (a[i] - '0' > b[i] - '0')
			return 0;
		if (a[i] - '0' < b[i] - '0')
			return 1;	
		i++;
	}
	return 0;
}

int equal(char* a, char* b){
	int i = 0;
	if (a[0] == '-')
		a += 1;
	if (b[0] == '-')
		b += 1;
	if (strlen(a) == strlen(b)){
		while(a[i] == b[i] && a[i] && b[i]){
			i++;
		}
		if (i == strlen(a)){
			write(1, "0\n", 2);
			return 0;
		}
	}
	return 1;
}

void add(char* a, char* b){
	int neg1 = 0, neg2 = 0;
	if (a[0] == '-' && b[0] == '-'){
		write (1, "-", 1);
		adding(a + 1, b + 1);
	}
	else if (a[0] != '-' && b[0] != '-')
		adding(a, b);
	else {
		if (equal(a, b) == 0)
			return ;
		if (a[0] == '-')
			neg1 = 1;
		if (b[0] == '-')
			neg2 = 1;
		if (neg1 == 1){
			if (first_is_bigger(a + 1, b) == 0){
				write(1, "-", 1);
				subtract(a + 1, b);
			}
			else{
				subtract(b, a + 1);
			}
		}
		else if (neg2 == 1){
			if (first_is_bigger(a, b + 1) == 0){
				subtract(a, b + 1);
			}
			else{
				write(1, "-", 1);
				subtract(b + 1, a);
			}					
		}
	}
}

int main(){
	add("0","0");
	printf("Should be 0\n");
	add("0", "123");
	printf("Should be 123\n");
	add("123", "-1");
	printf("Should be 122\n");
	add("-1", "-123");
	printf("Should be -124\n");
	add("-1", "123");
	printf("Should be 122\n");
	add("1", "-1");
	printf("Should be 0\n");
	add("123", "-246");
	printf("Should be -123\n");
	add("-123", "23");
	printf("Should be -100\n");
	add("-400", "400");
	printf("Should be 0\n");

}
