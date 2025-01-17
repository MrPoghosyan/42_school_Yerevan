/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapoghos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 11:58:09 by vapoghos          #+#    #+#             */
/*   Updated: 2024/12/17 12:30:55 by vapoghos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	str_len(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	get_total_len(int size, char **strs, char *sep)
{
	int	total_len;
	int	i;

	total_len = 0;
	i = 0;
	while (i < size)
	{
		total_len += str_len(strs[i]);
		if (i < size - 1)
			total_len += str_len(sep);
		i++;
	}
	return (total_len);
}

void	copy_strs(int size, char **strs, char *sep, char *result)
{
	int	i;
	int	j;
	int	k;
	int	index;

	i = 0;
	index = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
			result[index++] = strs[i][j++];
		if (i < size - 1)
		{
			k = 0;
			while (sep[k])
				result[index++] = sep[k++];
		}
		i++;
	}
	result[index] = '\0';
}

char	*allocate_result(int total_len)
{
	char	*result;

	result = malloc(total_len + 1);
	if (!result)
		return (NULL);
	return (result);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;
	int		total_len;

	if (size == 0)
	{
		result = malloc(1);
		if (!result)
			return (NULL);
		result[0] = '\0';
		return (result);
	}
	total_len = get_total_len(size, strs, sep);
	result = allocate_result(total_len);
	if (!result)
		return (NULL);
	copy_strs(size, strs, sep, result);
	return (result);
}
/*
#include <stdio.h>
int main()
{
    // Пример 1
    char *strs1[] = {"Hello", "world", "42"};
    int size1 = 3;
    char *sep1 = " ";

    char *result1 = ft_strjoin(size1, strs1, sep1);
    if (result1)
    {
        printf("Result 1: %s\n", result1);
        free(result1);  // Освобождаем память
    }

    // Пример 2
    char *strs2[] = {"This", "is", "a", "test"};
    int size2 = 4;
    char *sep2 = "-";

    char *result2 = ft_strjoin(size2, strs2, sep2);
    if (result2)
    {
        printf("Result 2: %s\n", result2);
        free(result2);  // Освобождаем память
    }

    // Пример 3 (пустая строка)
    char *strs3[] = {};
    int size3 = 0;
    char *sep3 = ", ";

    char *result3 = ft_strjoin(size3, strs3, sep3);
    if (result3)
    {
        printf("Result 3: '%s'\n", result3);
        free(result3);  // Освобождаем память
    }

    return 0;
}*/
