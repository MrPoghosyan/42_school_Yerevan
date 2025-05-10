/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapoghos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:44:19 by vapoghos          #+#    #+#             */
/*   Updated: 2025/01/24 11:10:53 by vapoghos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_result(char **tab)
{
	if (!tab)
		return ;
	while (*tab)
	{
		free(*tab);
		tab++;
	}
	free(tab);
}

static char	*get_next_word(char const **s, char sep)
{
	char const	*tmp;
	char		*word;

	while (**s == sep)
		(*s)++;
	tmp = *s;
	while (*tmp && *tmp != sep)
		tmp++;
	if (tmp > *s)
	{
		word = ft_substr(*s, 0, tmp - *s);
		*s = tmp;
		return (word);
	}
	return (NULL);
}

static int	fill_tab(char **tab, char const *s, char sep)
{
	char	*word;
	char	**start_tab;

	start_tab = tab;
	while (*s)
	{
		word = get_next_word(&s, sep);
		if (word)
		{
			*tab = word;
			tab++;
		}
		else if (!word && *s)
		{
			free_result(start_tab);
			return (0);
		}
	}
	*tab = NULL;
	return (1);
}

static int	count_words(char const *s, char sep)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != sep && !in_word)
		{
			count++;
			in_word = 1;
		}
		else if (*s == sep)
			in_word = 0;
		s++;
	}
	return (count);
}

char	**ft_split(char const *s, char sep)
{
	char	**new;
	int		size;

	if (!s)
		return (NULL);
	size = count_words(s, sep);
	new = (char **)malloc(sizeof(char *) * (size + 1));
	if (!new)
		return (NULL);
	if (!fill_tab(new, s, sep))
	{
		free(new);
		return (NULL);
	}
	return (new);
}
