#include "header.h"

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
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

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
