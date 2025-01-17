/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapoghos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 22:08:37 by vapoghos          #+#    #+#             */
/*   Updated: 2024/12/03 13:11:28 by vapoghos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	if (*str == '\0')
		return (1);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}
/*
#include <stdio.h>
 int	main(void)
{
	printf("%d\n", ft_str_is_numeric("12345"));
	printf("%d\n", ft_str_is_numeric("12345 hi"));
	printf("%d\n", ft_str_is_numeric(""));
}*/
