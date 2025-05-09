/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conversions_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapoghos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 11:22:26 by vapoghos          #+#    #+#             */
/*   Updated: 2025/04/01 13:26:32 by vapoghos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_hex(const char *format)
{
	while (*format)
	{
		if (*format == 'x' || *format == 'X')
			return (1);
		format++;
	}
	return (0);
}

int	check_integer(const char *format)
{
	while (*format)
	{
		if (*format == 'd' || *format == 'i')
			return (1);
		format++;
	}
	return (0);
}
