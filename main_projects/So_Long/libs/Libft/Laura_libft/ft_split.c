/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 12:57:04 by labroyan          #+#    #+#             */
/*   Updated: 2025/02/10 18:26:00 by labroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static	int	count(char const *str, char c)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str == c)
			str++;
		if (*str)
			count++;
		while (*str && *str != c)
			str++;
	}
	return (count);
}
/*
int main()
{
	char str[] = "Hello world it is a nice day";
	char c = ' ';
	int ok;

	ok = count(str, c);
	printf("%d", ok);
}
*/

static char	*next(char const **s, char c)
{
	const char	*start;
	char		*word;
	int			len;
	int			i;

	i = 0;
	while (**s == c)
		(*s)++;
	start = *s;
	while (**s && **s != c)
		(*s)++;
	len = *s - start;
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	while (i < len)
	{
		word[i] = start[i];
		i++;
	}
	word[len] = '\0';
	return (word);
}

static void	res_free(char **res, int i)
{
	while (i--)
		free(res[i]);
	free(res);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		words;
	int		i;

	i = 0;
	words = count(s, c);
	result = (char **)malloc((words + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	while (i < words)
	{
		result[i] = next(&s, c);
		if (!result[i])
		{
			res_free(result, i);
			return (NULL);
		}
		i++;
	}
	result[words] = NULL;
	return (result);
}
/*
int	main()
{
	char *str = "jasgdasjhg aksgdkab kjgasgbjas hgsaf";
	char c = ' ';
	char **res; 
	
	res = ft_split(str, c);
	if (res){
	for (int i = 0; res[i] != NULL; i++)
	{
		printf("%s\n", res[i]);
		free(res[i]);
	}
	free(res);
	}
	return (0);
}*/
