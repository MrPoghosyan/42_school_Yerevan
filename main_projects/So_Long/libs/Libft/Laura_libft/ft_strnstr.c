/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 20:50:06 by labroyan          #+#    #+#             */
/*   Updated: 2025/02/10 21:41:27 by labroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (*needle == '\0')
		return ((char *)haystack);
	i = 0;
	while ((haystack[i] != '\0') && (i < len))
	{
		if (haystack[i] == needle[0])
		{
			j = 0;
			while ((needle[j] != '\0') && ((i + j) < len))
			{
				if (haystack[i + j] != needle[j])
					break ;
				j++;
			}
			if (needle[j] == '\0')
				return ((char *)&haystack[i]);
		}
		i++;
	}
	return (NULL);
}
/*
int main(){
	char arr1[] = "Hello world!";
	char arr2[] = "worl";

	char *result = ft_strnstr(arr1, arr2, 13);
	printf("%s\n", result);

	return 0;
}*/
