#include "header.h"

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

int	is_valid_integer(const char *str)
{
	long	result;
	int		sign;

	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (!*str)
		return (0);
	result = 0;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		result = result * 10 + (*str - '0');
		if ((sign == 1 && result > INT_MAX)
			|| (sign == -1 && -result < INT_MIN))
			return (0);
		str++;
	}
	return (1);
}

