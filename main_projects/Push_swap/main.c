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

static t_node	*add_node(const int *arr, int size)
{
	t_node	*head;
	t_node	*tail;
	t_node	*new;
	int		i;

	head = NULL;
	i = 0;
	while (i < size)
	{
		if (!cread_node(&new, arr[i], get_index(arr, arr[i], size)))
			return (free_node_chain(&head), NULL);
		if (!head)
		{
			head = new;
			tail = head;
		}
		else
		{
			tail->next = new;
			tail = new;
		}
		i++;
	}
	return (head);
}
/*
static void	push_swap(t_node *node_a, int size)
{
	if (size < 4)
		heand_sort(node_a, size);
	else if (size < 21)
		insertion_selection(node_a, size);
	else
		radix_sort(node_a, size);

}
*/
int	main(int argc, char **argv)
{
	t_node	*node_a;
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
			node_a = add_node((const int *)arr, size);
//			push_swap(node_a, size);
			t_node *tmp = node_a;
			for (int i = 0; i < size; ++i){
				printf("%d ", tmp->value);
				tmp = tmp->next;
			}
			free(arr);
			free_node_chain(&node_a);
			write(1, "\n", 1);
		}
		else
			write (1, "Error\n", 6);
	}
	else
		write(1, "\n", 1);
	return (0);
}
