/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapoghos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 12:00:27 by vapoghos          #+#    #+#             */
/*   Updated: 2025/03/13 11:56:01 by vapoghos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_str(const char *str, int *byts_count)
{
	if (str == NULL)
	{
		*byts_count += write(1, "(null)", 6);
		return ;
	}
	if (*str == '\0')
	{
		*byts_count += write(1, "", 0);
		return ;
	}
	while (*str)
		*byts_count += write (1, str++, 1);
}

int	write_num(long int n)
{
	char	str[11];
	int		i;
	int		bc;

	i = 0;
	bc = 0;
	while (n > 0)
	{
		str[i++] = (n % 10) + '0';
		n /= 10;
	}
	while (--i >= 0)
		bc += write(1, &str[i], 1);
	return (bc);
}

const char	*will_check(const char *format)
{
	while (*format == '#' || *format == '+' || *format == ' ')
		format++;
	if (*format == 'd' || *format == 'i' || *format == 'x' || *format == 'X')
		format++;
	return (format);
}
