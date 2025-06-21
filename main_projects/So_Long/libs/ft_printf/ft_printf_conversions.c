/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conversions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapoghos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 12:01:22 by vapoghos          #+#    #+#             */
/*   Updated: 2025/03/12 12:24:19 by vapoghos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_char(const unsigned char c, int *byts_count)
{
	*byts_count += write(1, &c, 1);
}

void	print_number(int n, int *byts_count)
{
	if (n == 0)
	{
		*byts_count += write(1, "0", 1);
		return ;
	}
	if (n == INT_MIN)
	{
		*byts_count += write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		*byts_count += write(1, "-", 1);
		n = -n;
	}
	*byts_count += write_num(n);
}

void	print_unsigned(unsigned int num, int *byts_count)
{
	if (num == 0)
	{
		*byts_count += write(1, "0", 1);
		return ;
	}
	*byts_count += write_num(num);
}

void	print_hex(unsigned int num, int *byts_count, const char c)
{
	char	buffer[19];
	int		i;

	i = 0;
	if (num == 0)
		buffer[i++] = '0';
	if (c == 'x')
	{
		while (num > 0)
		{
			buffer[i++] = "0123456789abcdef"[num % 16];
			num /= 16;
		}
	}
	else
	{
		while (num > 0)
		{
			buffer[i++] = "0123456789ABCDEF"[num % 16];
			num /= 16;
		}
	}
	while (i-- > 0)
		*byts_count += write(1, &buffer[i], 1);
}

void	print_ptr(size_t num, int *byts_count)
{
	char	buffer[20];
	int		i;

	if (num == 0)
	{
		*byts_count += write(1, "(nil)", 5);
		return ;
	}
	i = 0;
	while (num > 0)
	{
		buffer[i++] = "0123456789abcdef"[num % 16];
		num /= 16;
	}
	*byts_count += write(1, "0x", 2);
	while (i-- > 0)
		*byts_count += write(1, &buffer[i], 1);
}
