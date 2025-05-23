/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapoghos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 11:35:01 by vapoghos          #+#    #+#             */
/*   Updated: 2025/04/29 11:35:19 by vapoghos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	validate_sort(int *arr, int size)
{
	int	i;

	i = 0;
	if (size <= 1)
		return (1);
	while (i < (size - 1))
	{
		if (arr[i] > arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	insertion_sort(int *arr, int size)
{
	int	key;
	int	i;
	int	j;

	i = 1;
	while (i < size)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			--j;
		}
		arr[j + 1] = key;
		++i;
	}
}

void	free_split(char **split)
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

int	count_int(const char **str, int count)
{
	char	**split;
	char	**tmp;
	int		size;

	size = 0;
	while (count-- > 1)
	{
		if (ft_strchr(str[count], ' '))
		{
			split = ft_split(str[count], ' ');
			if (!split)
				return (-1);
			tmp = split;
			while (*split)
			{
				size++;
				split++;
			}
			free_split(tmp);
		}
		else
			size++;
	}
	return (size);
}

int	*add_int(const char **str, int count, int size)
{
	char	**split;
	char	**tmp_free;
	int		*arr;
	int		*tmp;

	arr = (int *)malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	tmp = arr;
	while (--count)
	{
		if (ft_strchr(*str, ' '))
		{
			split = ft_split(*str++, ' ');
			if (!split)
				return (NULL);
			tmp_free = split;
			while (*split)
				*tmp++ = ft_atoi(*split++);
			free_split(tmp_free);
		}
		else
			*tmp++ = ft_atoi(*str++);
	}
	return (arr);
}
