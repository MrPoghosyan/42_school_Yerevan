/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapoghos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:28:42 by vapoghos          #+#    #+#             */
/*   Updated: 2024/12/05 18:38:00 by vapoghos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
char	*ft_strstr(char *str, char *to_find)
{
	char	*pah;
	char	*hasc;

	if (*to_find == '\0')
		return (str);
	while (*str != '\0')
	{
		pah = to_find;
		hasc = str;
		while (*hasc == *pah && *pah != '\0')
		{
			pah++;
			hasc++;
		}
		if (*pah == '\0')
			return (str);
		str++;
	}
	return (0);
}
/*
int main() {
    char str[] = "Hello, World!";
    char to_find1[] = "World";
    char to_find2[] = "world";
    char to_find3[] = "";

    printf("Search 'World' in 'Hello, World!': %s\n", ft_strstr(str, to_find1));
    printf("Search 'world' in 'Hello, World!': %s\n", ft_strstr(str, to_find2));
    printf("Search '' in 'Hello, World!': %s\n", ft_strstr(str, to_find3));

    return 0;
}
*/
