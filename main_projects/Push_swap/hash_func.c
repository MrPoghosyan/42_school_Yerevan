/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapoghos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 11:37:09 by vapoghos          #+#    #+#             */
/*   Updated: 2025/04/29 19:24:53 by vapoghos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
/*
unsigned long	hash_int(int n)
{
	unsigned long	x;

	if (n < 0)
		x = (unsigned long)-n;
	else
		x = (unsigned long)n;
	x = ((x >> 16) ^ x) * 0x45d9f3b;
	x = ((x >> 16) ^ x) * 0x45d9f3b;
	x = (x >> 16) ^ x;
	return (x % TABLE_SIZE);
}
*/
