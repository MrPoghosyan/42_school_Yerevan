#include <stdlib.h>

static int	get_len(int n)
{
	int	len;

	len = (n <= 0) ? 1 : 0;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return len;
}

char	*ft_itoa(int nbr)
{
	int len = get_len(nbr);
	char *str = (char *)malloc(sizeof(char) * (len +1));
	if (!str)
		return NULL;

	str[len] = '\0';
	if (nbr < 0)
	{
		str[0] = '-';
		nbr = -nbr;
	}
	else if (nbr == 0)
		str[0] = '0';
	while (nbr > 0)
	{
		str[--len] = '0' + (nbr % 10);
		nbr /= 10;
	}
	return str;
}

#include <stdio.h>

int main()
{
	printf("%s\n", ft_itoa(15246));
	printf("%s\n", ft_itoa(-15246));
	printf("%s\n", ft_itoa(0));
	printf("%s\n", ft_itoa(1));
}
