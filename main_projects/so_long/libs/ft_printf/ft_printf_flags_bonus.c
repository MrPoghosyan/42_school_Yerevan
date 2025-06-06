/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapoghos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:38:01 by vapoghos          #+#    #+#             */
/*   Updated: 2025/04/01 14:13:28 by vapoghos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_hex0(unsigned int num, int *byts_count, char c)
{
	if (num == 0)
	{
		*byts_count += write(1, "0", 1);
		return ;
	}
	else
	{
		if (c == 'x')
		{
			*byts_count += write(1, "0x", 2);
			print_hex(num, byts_count, 'x');
		}
		else
		{
			*byts_count += write(1, "0X", 2);
			print_hex(num, byts_count, 'X');
		}
	}
}

static void	print_num_n(int num, int *byts_count)
{
	if (num >= 0)
	{
		*byts_count += write(1, "+", 1);
		print_number(num, byts_count);
		return ;
	}
	print_number(num, byts_count);
}

static void	print_num_s(int num, int *byts_count)
{
	if (num >= 0)
	{
		*byts_count += write(1, " ", 1);
		print_number(num, byts_count);
		return ;
	}
	print_number(num, byts_count);
}

void	print_bonus(va_list args, int *byts_count, const char *format)
{
	if (*format == '#')
	{
		if (check_hex(format))
			print_hex0(va_arg(args, unsigned int), byts_count, *(format + 1));
	}
	else if (*format == '+')
	{
		if (check_integer(format))
			print_num_n(va_arg(args, int), byts_count);
	}
	else if (*format == ' ')
	{
		if (check_integer(format))
			print_num_s(va_arg(args, int), byts_count);
	}
	else if ((*format == ' ' && *(format + 1) == '+') || (*format == '+'
			&& *(format + 1) == ' '))
	{
		if (*(format + 2) == 'd' || *(format + 2) == 'i')
			print_num_n(va_arg(args, int), byts_count);
	}
}
