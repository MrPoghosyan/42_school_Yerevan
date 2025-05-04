/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapoghos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 11:35:52 by vapoghos          #+#    #+#             */
/*   Updated: 2025/04/29 11:36:09 by vapoghos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	is_valid_format(const char *str)
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
			|| (sign == -1 && - result < INT_MIN))
			return (0);
		str++;
	}
	return (1);
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
		return (free_split(split), 1);
	}
	else
	{
		if (is_valid_integer(str))
		{
			return (1);
		}
	}
	return (0);
}

int	duplicates(int *arr, int size)
{
	int	i;

	insertion_sort(arr, size);
	i = 1;
	while (i < size)
	{
		if (arr[i] == arr[i - 1])
			return (1);
		++i;
	}
	return (0);
}

int	validate_argument(const char **str, int count)
{
	int	*arr;
	int	size;
	int	i;

	i = 1;
	while (i < count)
	{
		if (!is_valid_format(str[i]))
			return (0);
		if (!is_within_int_range(str[i]))
			return (0);
		++i;
	}
	size = count_int(str, count);
	arr = add_int(&str[1], count, size);
	if (!arr)
		return (-1);
	if (duplicates(arr, size))
		return (free(arr), 0);
	return (free(arr), 1);
}
