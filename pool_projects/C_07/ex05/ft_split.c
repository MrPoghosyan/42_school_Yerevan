/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+         +:+     */
/*   By: vapoghos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:30:24 by vapoghos          #+#    #+#             */
/*   Updated: 2024/12/17 15:38:13 by vapoghos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_charset(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*str)
	{
		if (is_charset(*str, charset))
			in_word = 0;
		else if (!in_word)
		{
			in_word = 1;
			count++;
		}
		str++;
	}
	return (count);
}

char	*get_next_word(char *str, char *charset)
{
	char	*start;
	char	*word;
	int		i;

	start = str;
	while (*str && is_charset(*str, charset))
		str++;
	start = str;
	while (*str && !is_charset(*str, charset))
		str++;
	word = (char *)malloc((str - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (start < str)
		word[i++] = *start++;
	word[i] = '\0';
	return (word);
}

char	**handle_split_error(char **result, int i)
{
	while (i > 0)
		free(result[--i]);
	free(result);
	return (NULL);
}

// Combining allocation and parsing in one function
char	**ft_split(char *str, char *charset)
{
	int		words_count;
	int		i;
	char	**result;

	if (!str || !charset)
		return (NULL);
	words_count = count_words(str, charset);
	result = (char **)malloc((words_count + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	while (*str)
	{
		if (!is_charset(*str, charset))
		{
			result[i] = get_next_word(str, charset);
			if (!result[i])
				return (handle_split_error(result, i));
			i++;
			while (*str && !is_charset(*str, charset))
				str++;
		}
		else
			str++;
	}
	result[i] = NULL;
	return (result);
}
