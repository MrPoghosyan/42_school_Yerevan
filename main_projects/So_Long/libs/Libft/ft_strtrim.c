/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapoghos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:40:51 by vapoghos          #+#    #+#             */
/*   Updated: 2025/01/22 11:42:33 by vapoghos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	const char	*ptr;
	char		*trimmed_str;
	size_t		length;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	ptr = s1;
	while (*ptr != '\0')
		ptr++;
	length = (ptr - s1);
	while (length > 0 && ft_strchr(set, *(s1 + length -1)))
		length--;
	trimmed_str = (char *)malloc(length + 1);
	if (!trimmed_str)
		return (NULL);
	ft_strlcpy(trimmed_str, s1, length + 1);
	return (trimmed_str);
}
