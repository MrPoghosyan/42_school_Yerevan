/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 18:47:35 by labroyan          #+#    #+#             */
/*   Updated: 2025/02/06 14:31:17 by labroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}
/*
#include <stdio.h>

int	main (void)
{
	int a;

	a = '1';
	if (ft_isdigit(a))
	{
		printf(" %c is a digit", a);
	}
	else
	{
		printf("%c is not a digit", a );
	}
	return (0);
}*/
