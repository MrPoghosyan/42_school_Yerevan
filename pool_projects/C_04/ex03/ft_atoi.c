/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapoghos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 12:46:00 by vapoghos          #+#    #+#             */
/*   Updated: 2024/12/05 13:27:30 by vapoghos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	index;
	int	pah;

	index = 1;
	pah = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n'
		|| *str == '\r' || *str == '\f' || *str == '\v')
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			index *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		pah = pah * 10 + (*str - '0');
		str++;
	}
	return (pah * index);
}
/*
#include <stdio.h>

int main(int argc, char *argv[])
{
	if (argc == 2)
		printf("%d\n", ft_atoi(argv[1]));
	else
		printf("%s\n", "invalid arguments");
	return (0);
}
*/
