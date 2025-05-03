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

t_node	*add_node(char **argv, int count)
{
	t_node	*head;
	t_node	*tail;
	int		*arr;
	int		i;
	int		size;

	size = count_int((const char **)argv, count);
	arr = add_int((const char **)argv, count, size);
	if (!arr)
		return (NULL);
	head = NULL;
	tail = NULL;
	i = 0;
	while (i < size)
	{
		if (!cread_node(&head, &tail, arr[i],
				get_index((const int *)arr, arr[i], size)))
		{
			free_node_chain(&head);
			free(arr);
			return (NULL);
		}
		i++;
	}
	return (free(arr), head);
}


static void	push_swap(t_stack a)
{	
}

int	main(int argc, char **argv)
{
	t_node	*a;

	if (argc > 1)
	{
		if (validate_argument((const char **)argv, argc))
		{
			printf("Valid argument\n");
			a = add_node(argv, argc);
			push_swap(a);
		}
		else
			write (1, "Error\n", 6);
	}
	else
		write(1, "\n", 1);
	return (0);
}
