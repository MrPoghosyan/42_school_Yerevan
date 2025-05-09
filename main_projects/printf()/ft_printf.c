/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapoghos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 12:01:41 by vapoghos          #+#    #+#             */
/*   Updated: 2025/04/01 14:12:15 by vapoghos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	conversions(const char *format, va_list args,
int *byts_count, int *index)
{
	if (*format == 'd' || *format == 'i')
		print_number(va_arg(args, int), byts_count);
	else if (*format == 'u')
		print_unsigned(va_arg(args, unsigned int), byts_count);
	else if (*format == 'c')
		print_char(va_arg(args, int), byts_count);
	else if (*format == 's')
		print_str(va_arg(args, char *), byts_count);
	else if (*format == 'x' || *format == 'X')
		print_hex(va_arg(args, unsigned int), byts_count, *format);
	else if (*format == 'p')
		print_ptr(va_arg(args, size_t), byts_count);
	else if (*format == '%')
		*byts_count += write (1, "%", 1);
	else if (*format == '#' || *format == '+' || *format == ' ')
	{
		*index = 1;
		print_bonus(args, byts_count, format);
	}
}

int	ft_printf(const char *format, ...)
{
	int		byts_count;
	va_list	args;
	int		index;

	va_start(args, format);
	byts_count = 0;
	while (*format != '\0')
	{
		index = 0;
		if (*format == '%')
		{
			conversions(++format, args, &byts_count, &index);
			++format;
			if (index)
				format = will_check(format);
		}
		else
			byts_count += write(1, format++, 1);
	}
	va_end(args);
	return (byts_count);
}
