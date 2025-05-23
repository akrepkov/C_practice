/*
This C program includes a few small utilities to work with numbers and check if they're divisible by 3.
*/

int	ft_ilength(int n){
	int	i = 0;
	if (n == 0)
		return (1);
	if (n < 0){
		n *= -1;
		i++;
	}
	while (n > 0){
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int	len = ft_ilength(n2);
	int	n2 = n;
	char			*res;

	res = (char *)malloc(sizeof(char) * (len + 1));
	if (res == 0)
		return (0);
	res[len] = '\0';
	if (n2 == 0)
		res[0] = '0';
	if (n2 < 0 && n2 != -2147483648)
	{
		res[0] = '-';
		n2 = -n;
	}
	if (n2 == -2147483648)
		ft_strlcpy(res, "-2147483648", len + 1);
	while (len-- && n2 > 0)
	{
		res[len] = '0' + (n2 % 10);
		n2 = n2 / 10;
	}
	return (res);
}

//Bash calculator: echo "3^19 | bc" 

//to check if the number is power of 3:
int power_of_three(int n){
    if (1162261467 % n == 0) //1162261467 - biggest power of 3 as integer
        return 0;
}


int main(){
    int sum = 0;
    while(n > 0){
        sum += n % 10;
        n = n / 10;
    }
    if (sum % 3 == 0)
        return 0;
    return 1;
}
