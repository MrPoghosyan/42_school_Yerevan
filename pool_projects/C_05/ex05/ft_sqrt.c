/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapoghos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:19:26 by vapoghos          #+#    #+#             */
/*   Updated: 2024/12/09 16:58:33 by vapoghos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	i;

	i = 0;
	if (nb < 0)
		return (0);
	while (i * i < nb)
		i++;
	if (i * i == nb)
		return (i);
	else
		return (0);
}
/*
#include <stdio.h>

int main()
{
    printf("%d\n", ft_sqrt(16)); // 4 
    printf("%d\n", ft_sqrt(25)); // 5
    printf("%d\n", ft_sqrt(27)); // 0
    printf("%d\n", ft_sqrt(-4)); // 0
    return 0;
}*/
