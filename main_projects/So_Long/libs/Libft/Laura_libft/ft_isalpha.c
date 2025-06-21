/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 18:17:34 by labroyan          #+#    #+#             */
/*   Updated: 2025/02/02 13:05:33 by labroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_isalpha(int c)
{
	return ((c >= 65 && c <= 90) || (c >= 97 && c <= 122));
}
/*
#include <stdio.h>
int main(void)
{
	int a;

	a = 'a'; 
	if (ft_isalpha(a))
	{
		printf(" '%c' is alpha", a);
	}
	else
	{
		printf(" '%c' is not alpha", a);
	}
	return (0);
}*/
