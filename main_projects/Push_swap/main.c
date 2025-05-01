/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapoghos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 11:33:56 by vapoghos          #+#    #+#             */
/*   Updated: 2025/04/29 12:31:29 by vapoghos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/*
static void	push_swap(t_stack arr)
{
	///
}
*/
int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		if (validate_argument((const char **)argv, argc))
			printf("Valid argument\n");
		else
			printf("Is not valid argumen\n");
	}
	else
		write(1, "\n", 1);
	return (0);
}
