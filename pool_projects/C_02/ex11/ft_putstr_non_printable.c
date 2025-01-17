/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapoghos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 12:30:28 by vapoghos          #+#    #+#             */
/*   Updated: 2024/12/03 12:54:18 by vapoghos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_non_printable(char *str)
{
	char			*hex;
	unsigned char	c;

	hex = "0123456789abcdef";
	while (*str)
	{
		c = *str;
		if (c >= 32 && c <= 126)
			write (1, &c, 1);
		else
		{
			write (1, "\\", 1);
			write (1, &hex[c / 16], 1);
			write (1, &hex[c % 16], 1);
		}
		str++;
	}
}
/*
int main() {
    char str[] = "Coucou\ntu vas bien ?";
    ft_putstr_non_printable(str);
    return 0;
}
*/
