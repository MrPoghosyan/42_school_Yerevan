/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 20:35:21 by labroyan          #+#    #+#             */
/*   Updated: 2025/02/10 19:44:32 by labroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	ft_numlen(int n)
{
	size_t	length;

	length = 0;
	if (n <= 0)
		length++;
	while (n)
	{
		n /= 10;
		length++;
	}
	return (length);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	num;
	size_t	len;

	num = n;
	len = ft_numlen(n);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}
	while (len-- > (n < 0))
	{
		str[len] = (num % 10) + '0';
		num /= 10;
	}
	return (str);
}
/*
int main()
{
	long x = 12003345;
	char *res = ft_itoa(x);

	printf("%s", res);
}*/
