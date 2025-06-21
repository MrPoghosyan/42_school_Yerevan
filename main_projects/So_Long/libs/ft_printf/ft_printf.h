/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapoghos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 12:00:56 by vapoghos          #+#    #+#             */
/*   Updated: 2025/04/01 14:45:47 by vapoghos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <limits.h>

int			ft_printf(const char *format, ...);
const char	*will_check(const char *format);
int			write_num(long int n);
void		print_char(const unsigned char c, int *byts_count);
void		print_str(const char *str, int *byts_count);
void		print_number(int n, int *byts_count);
void		print_unsigned(unsigned int num, int *byts_count);
void		print_hex(unsigned int num, int *byts_count, const char c);
void		print_ptr(size_t num, int *byts_count);
void		print_bonus(va_list args, int *byts_count, const char *format);
int			check_hex(const char *format);
int			check_integer(const char *format);

#endif
