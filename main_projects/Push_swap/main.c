/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   main.c											 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: vapoghos <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/04/29 11:33:56 by vapoghos		  #+#	#+#			 */
/*   Updated: 2025/04/29 12:31:29 by vapoghos		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "header.h"

static int	validate_sort(int *arr, int size)
{
	int	i;

	i = 0;
	if (size <= 1)
		return (1);
	while (i < (size - 1))
	{
		if (arr[i] > arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}

static void	push_swap(t_node **a_node, int size)
{
	t_node	*b_node;

	b_node = NULL;
	if (size == 2)
		sa(a_node);
	else if (size == 3)
		sort_three(a_node);
	else if (size < 31)
		insertion_sort_n(a_node, &b_node, size);
	else
		radix_sort(a_node, &b_node, size);
}

int	main(int argc, char **argv)
{
	t_node	*a_node;
	int		*arr;
	int		size;

	if (argc > 1)
	{
		if (validate_argument((const char **)argv, argc))
		{
			size = count_int((const char **)argv, argc);
			arr = add_int((const char **)&argv[1], argc, size);
			if (!arr)
				return (1);
			if (validate_sort(arr, size))
				return (0);
			a_node = add_node((const int *)arr, size);
			push_swap(&a_node, size);
			free(arr);
			free_node_chain(&a_node);
		}
		else
			write (1, "Error\n", 6);
	}
	else
		write(1, "\n", 1);
	return (0);
}
