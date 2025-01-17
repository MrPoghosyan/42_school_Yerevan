/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapoghos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:24:23 by vapoghos          #+#    #+#             */
/*   Updated: 2024/12/09 16:07:03 by vapoghos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	if (index == 0)
		return (0);
	if (index == 1)
		return (1);
	return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
}
/*
#include <stdio.h>

int main(void)
{
	printf("Fibonacci(0) = %d\n", ft_fibonacci(0));  // 0
	printf("Fibonacci(1) = %d\n", ft_fibonacci(1));  // 1
	printf("Fibonacci(2) = %d\n", ft_fibonacci(2));  // 1
	printf("Fibonacci(3) = %d\n", ft_fibonacci(3));  // 2
	printf("Fibonacci(4) = %d\n", ft_fibonacci(4));  // 3
	printf("Fibonacci(5) = %d\n", ft_fibonacci(5));  // 5
	printf("Fibonacci(6) = %d\n", ft_fibonacci(6));  // 8
	printf("Fibonacci(-3) = %d\n", ft_fibonacci(-3));// -1
	return 0;
}*/
