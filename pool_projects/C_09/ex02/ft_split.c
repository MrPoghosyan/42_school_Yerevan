/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapoghos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 13:20:14 by vapoghos          #+#    #+#             */
/*   Updated: 2024/12/18 14:09:37 by vapoghos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_separator(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

int	substrings_count(char	*str, char	*charset)
{
	int	count;
	int	fl;

	count = 0;
	fl = 0;
	while (*str)
	{
		if (is_separator(*str, charset))
		{
			if (fl)
				fl = 0;
		}
		else if (!fl)
		{
			count++;
			fl = 1;
		}
		str++;
	}
	return (count);
}

char	*copy_substring(char *start, char *end)
{
	int		len;
	char	*str;
	char	*tmp;

	len = end - start;
	str = (char *)malloc(len + 1);
	if (!str)
		return (0);
	tmp = str;
	while (start < end)
	{
		*str = *start;
		start++;
		str++;
	}
	*str = 0;
	return (tmp);
}

void	ft_split2(char *start, int i, char **result, char *str)
{
	if (start)
		result[i++] = copy_substring(start, str);
	result[i] = 0;
}

char	**ft_split(char *str, char *charset)
{
	char	**result;
	int		i;
	char	*start;

	result = (char **)malloc((substrings_count(str, charset) + 1) * 8);
	if (!result)
		return (0);
	start = 0;
	i = 0;
	while (*str)
	{
		if (is_separator(*str, charset))
		{
			if (start)
			{
				result[i++] = copy_substring(start, str);
				start = 0;
			}
		}
		else if (!start)
			start = str;
		str++;
	}
	ft_split2(start, i, result, str);
	return (result);
}
/*
#include <stdio.h>
int main()
{
	char str[] = "    .Hellow Worlddd:)  ";
	char charset[] = " .,:)";
	char **res = ft_split(str, charset);
	printf("===\n");
	while (*res)
	{
		printf("%s\n",*res);
		res++;
	}
}*/
