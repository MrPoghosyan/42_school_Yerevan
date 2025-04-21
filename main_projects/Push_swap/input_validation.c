#include "header.h"

int is_valid_format(const char *str)
{
	while (*str)
	{
		while (*str == ' ' || *str == '\t')
			++str;
		if (!*str)
			break ;
		if (*str == '+' || *str == '-')
		{
			if (!*(str +1) || (*(str +1) < '0' || *(str +1) > '9'))
				return (0);
			++str;
		}
		if (*str >= '0' && *str <= '9')
		{
			while (*str >= '0' && *str <= '9')
				++str;
			if (!(*str == ' ' || *str == '\t' || *str == '\0'))
				return (0);
		}
		else
			return (0);
	}
	return (1);
}

static void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int	is_within_int_range(const char *str)
{
	char	**split;
	char	**tmp;

	if (ft_strchr(str, ' '))
	{
		split = ft_split(str, ' ');
		if (!split)
			return (-1);
		tmp = split;
		while (*tmp)
		{
			if (!is_valid_integer(*tmp))
				return (free_split(split), 0);
			++tmp;
		}
		if (hash_duplicates((const char **)split))
			return (free_split(split), 0);
		return (free_split(split), 1);
	}
	else
		if (is_valid_integer(str))
		{
			if (!check_and_add(ft_atoi(str)))
				return (0);
			return (1);
		}
	return (0);
}

int	hash_duplicates(const char **arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (!check_and_add(ft_atoi(arg[i])))
			return (1);
		++i;
	}
	return (0);
}

int validate_argument(const char **str, int count)
{
	int	i;

	i = 1;
	while (i < count)
	{
		if (!is_valid_format(str[i]))
		{
			printf("VA == is_valid_format:\n");

			return (0);
		}
		if (!is_within_int_range(str[i]))
		{
			printf("VA == is_within_int_range:\n");
			return (0);
		}
		++i;
	}
	return (1);
}
