#include "header.h"
/*
int	check_int(int count, const char **arg)
{
	int	i;
	int	j;

	i = 1;
	while (i < count)
	{
		j = 0;
		if (arg[i][j] == '-' || arg[i][j] == '+')
			j++;
		while (arg[i][j])
		{
			if (arg[i][j] < '0' || arg[i][j] > '9')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
*/
t_stack	append_valid_int(int count, char **argv)
{
	t_stack	result;
	int		i;

	result.arr = (int *)malloc(sizeof(int) * (count -1));
	if (!result.arr)
		return (result);
	i = 0;
	while (i < count -1)
	{
		result.arr[i] = ft_atoi(argv[i +1]);
		++i;
	}
	result.size = count -1;
	return (result);
}
static int check_sign(const char *c, int *sign)
{
	*sign = 1;
	if (*c == '-' || *c == '+')
	{
		if (*c == '-')
			*sign = -1;
		return (1);
	}
	return (0);
}

int	is_valid_integer(const char *str)
{
	long	result;
	int		sign;

	str += check_sign(str, &sign);
	if (!*str)
		return (0);
	while (*str)
	{
		while (*str == ' ')
			str++;
		str += check_sign(str, &sign);
		if (!ft_isdigit(*str))
			return (0);
		result = result * 10 + (*str - '0');
		if ((sign == 1 && result > INT_MAX)
			|| (sign = -1 && -result < INT_MIN))
			return (0);
		str++;
	}
	return (1);
}
