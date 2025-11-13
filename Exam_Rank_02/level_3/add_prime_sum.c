#include <unistd.h>

int ft_atoi(char *str)
{
	int res = 0;

	while (*str >= '0' && *str <= '9')
		res = res * 10 + (*str - '0');
	return (res);
}

int is_prime(int n)
{
	if (n < 2)
		return (0);
	for (int i = 2; i * i <= n; ++i)
		if (n % i == 0)
			return (0);
	return (1);
}

void ft_putnbr(int n)
{
	char c;

	if (n > 9)
		ft_putnbr(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(1, "0\n", 2);
		return (0);
	}

	int nb = ft_atoi(argv[1]);
	if(nb <= 0)
	{
		write(1, "0\n", 2);
		return (0);
	}

	int sum = 0;
	for (int i = 2; i <= nb; ++i)
		if (is_prime(i))
			sum += i;

	ft_putnbr(sum);
	write(1, "\n", 1);
	return (0);
}
