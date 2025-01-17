/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapoghos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 12:01:08 by vapoghos          #+#    #+#             */
/*   Updated: 2024/12/05 12:12:13 by vapoghos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
		count++;
	return (count);
}
/*
#include <stdio.h>

int	ft_strlen(char *str);

int	main(void)
{
	char str1[] = "Hello, World!";
	char str2[] = ""; 
	char str3[] = "C programming is fun!";

	printf("Length of '%s': %d\n", str1, ft_strlen(str1));
	printf("Length of '%s': %d\n", str2, ft_strlen(str2));
	printf("Length of '%s': %d\n", str3, ft_strlen(str3));

	return (0);
}
*/
