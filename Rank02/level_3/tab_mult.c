#include <unistd.h>

// Ֆունկցիա՝ տպելու ամբողջ թիվը write-ով
void	ft_putnbr(int n)
{
	char c;

	if (n >= 10)
		ft_putnbr(n / 10);
	c = (n % 10) + '0';
	write (1, &c, 1);
}

// Ֆունկցիա՝ սիմվոլը թիվ սարգել
int	ft_atoi(char *str)
{
	int res = 0;

	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res);
}

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		int i = 1;
		int num = ft_atoi(argv[1]);

		while (i <= 9)
		{
			ft_putnbr(i);
			write(1, " x ", 3);
			ft_putnbr(num);
			write(1, " = ", 3);
			ft_putnbr(i * num);
			write(1, "\n", 1);
			++i;
		}
	}
	else
		write(1, "\n", 1);

	return (0);
}
