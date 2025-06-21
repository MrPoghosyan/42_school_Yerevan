/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 20:17:29 by labroyan          #+#    #+#             */
/*   Updated: 2025/02/10 21:53:51 by labroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
/*
int main(void)
{
	int a;

	a = 0177;
	if (ft_isascii(a))
	{
		printf("%c is ascii", a);
	}
	else
	{
		printf("%c is not ascii", a);
	}
	return (0);
}*/
