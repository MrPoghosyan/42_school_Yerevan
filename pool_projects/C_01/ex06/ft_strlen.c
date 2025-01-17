/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapoghos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:20:57 by vapoghos          #+#    #+#             */
/*   Updated: 2024/12/02 16:31:39 by vapoghos         ###   ########.fr       */
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
int main()
{
	char *text = "Hello, world!";
	int length = ft_strlen(text);
	printf("Length: %d\n", length); //Length: 13
	return 0;
}*/
