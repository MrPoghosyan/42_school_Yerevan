/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapoghos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 22:10:23 by vapoghos          #+#    #+#             */
/*   Updated: 2024/12/02 22:18:08 by vapoghos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < 'A' || str[i] > 'Z')
			return (0);
		i++;
	}
	return (1);
}

/*
#include <stdio.h> 
int	main(void)
{
	printf("%d\n", ft_str_is_uppercase("HELLO"));
	printf("%d\n", ft_str_is_uppercase("Hello world!"));
	printf("%d\n", ft_str_is_uppercase(""));
} */
