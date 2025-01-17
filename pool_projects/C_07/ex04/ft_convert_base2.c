/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapoghos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:49:41 by vapoghos          #+#    #+#             */
/*   Updated: 2024/12/17 13:02:37 by vapoghos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	is_valid_base(char *base)
{
	int	i;
	int	j;

	if (ft_strlen(base) < 2)
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == ' '
			|| (base[i] >= '\t' && base[i] <= '\r'))
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	get_index(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

void	skip_whitespace_and_sign(char **str, int *sign)
{
	*sign = 1;
	while (**str == ' ' || (**str >= '\t' && **str <= '\r'))
		(*str)++;
	while (**str == '-' || **str == '+')
	{
		if (**str == '-')
			*sign *= -1;
		(*str)++;
	}
}

int	ft_atoi_base(char *str, char *base)
{
	int	sign;
	int	result;
	int	base_len;
	int	index;

	sign = 1;
	result = 0;
	base_len = ft_strlen(base);
	skip_whitespace_and_sign(&str, &sign);
	index = get_index(*str, base);
	while (index != -1)
	{
		result = result * base_len + index;
		str++;
		index = get_index(*str, base);
	}
	return (result * sign);
}
