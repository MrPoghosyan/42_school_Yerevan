/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 19:05:21 by labroyan          #+#    #+#             */
/*   Updated: 2025/02/06 14:30:37 by labroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isalnum(int c)
{
	return ((ft_isalpha(c)) || (ft_isdigit(c)));
}
/*
int main(void)
{
	int a;

	a = ' ';
	if(ft_isalnum(a))
	{
		printf("%c is alnum", a);
	}
	else
	{
		printf("%c is not alnum", a);
	}
	return (0);
}*/
