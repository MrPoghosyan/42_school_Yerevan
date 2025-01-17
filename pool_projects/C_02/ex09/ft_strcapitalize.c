/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapoghos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 11:21:40 by vapoghos          #+#    #+#             */
/*   Updated: 2024/12/03 11:51:58 by vapoghos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int		is_new_word;
	char	*p;

	is_new_word = 1;
	p = str;
	while (*p != '\0')
	{
		if ((*p >= 'a' && *p <= 'z') || (*p >= 'A' && *p <= 'Z')
			|| (*p >= '0' && *p <= '9'))
		{
			if (is_new_word && *p >= 'a' && *p <= 'z')
				*p -= 'a' - 'A';
			else if (!is_new_word && *p >= 'A' && *p <= 'Z')
				*p += 'a' - 'A';
			is_new_word = 0;
		}
		else
			is_new_word = 1;
		p++;
	}
	return (str);
}
/*

#include <stdio.h>

char	*ft_strcapitalize(char *str);

int	main(void)
{
	char str[] = "isalut, comment tu vas ? 
	42mots quarante--deux; cinquante+++et+un";

	printf("Before: %s\n", str);
	ft_strcapitalize(str);
	printf("After:  %s\n", str);
	return (0);
}
*/
