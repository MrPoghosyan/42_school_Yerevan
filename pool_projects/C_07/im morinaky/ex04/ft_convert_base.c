/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapoghos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:42:54 by vapoghos          #+#    #+#             */
/*   Updated: 2024/12/17 13:29:39 by vapoghos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_convert_base2.h"

static int	handle_sign_and_abs(int *num)
{
	int	is_negative;

	is_negative = *num < 0;
	if (is_negative)
		*num = -(*num);
	return (is_negative);
}

static char	*convert_positive_number(int num, char *base_to, int base_len)
{
	int		len;
	char	*result;

	len = get_number_length(num, base_len);
	result = malloc(len + 1);
	if (!result)
		return (NULL);
	result[len] = '\0';
	while (len--)
	{
		result[len] = base_to[num % base_len];
		num /= base_len;
	}
	return (result);
}

char	*convert_int_to_base(int num, char *base_to)
{
	int		base_len;
	int		is_negative;
	char	*result;
	char	*new_result;

	base_len = ft_strlen(base_to);
	if (num == 0)
		return (handle_zero_case(base_to));
	is_negative = handle_sign_and_abs(&num);
	result = convert_positive_number(num, base_to, base_len);
	if (is_negative)
	{
		new_result = malloc(ft_strlen(result) + 2);
		if (!new_result)
			return (NULL);
		new_result[0] = '-';
		ft_strcpy(new_result + 1, result);
		free(result);
		return (new_result);
	}
	return (result);
}
