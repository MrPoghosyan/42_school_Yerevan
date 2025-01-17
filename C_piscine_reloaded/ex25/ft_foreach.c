/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapoghos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 17:20:02 by vapoghos          #+#    #+#             */
/*   Updated: 2025/01/09 17:30:25 by vapoghos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_foreach(int *tab, int length, void (*f)(int))
{
	while (length > 0)
	{
		f(*tab);
		tab++;
		length--;
	}
}
/*
#include <unistd.h>

void ft_putnbr(int n)
{
    char c;

    if (n >= 10)
        ft_putnbr(n / 10);
    c = n % 10 + '0';
    write(1, &c, 1);
}

int main()
{
    int tab[] = {1, 2, 3, 4, 5};
    ft_foreach(tab, 5, &ft_putnbr);
    return 0;
}*/
