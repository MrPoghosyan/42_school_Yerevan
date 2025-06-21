/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 20:52:07 by labroyan          #+#    #+#             */
/*   Updated: 2025/02/10 21:57:15 by labroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isprint(int c)
{
	if ((c >= 32) && (c <= 126))
		return (1);
	return (0);
}
/*
int main(void)
{
	int	a;

	a = 054;
	if (ft_isprint(a))
	{
		printf("%c is printable.\n", a);
	}
	else
	{
		printf("%c is not printable. \n", a);
	}
	return (0);
}*/
