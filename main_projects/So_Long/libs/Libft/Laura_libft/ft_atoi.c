/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labroyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:20:53 by labroyan          #+#    #+#             */
/*   Updated: 2025/02/10 22:36:41 by labroyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
		if (str[i] == '-' || str[i] == '+')
			return (0);
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - 48;
		i++;
	}
	return (sign * result);
}
/*
int main()

{
	char arr[] = "-12345";
	char arr_max[] = "2147483647";
	char arr_nul[] = "0";
	char arr_min[] = "-2147483648";

	printf("%d",ft_atoi(arr));
	printf("\n");
	printf("%d",ft_atoi(arr_max));
	printf("\n");
	printf("%d",ft_atoi(arr_nul));
	printf("\n");
	printf("%d",ft_atoi(arr_min));
	printf("\n");
	return (0);
}*/
