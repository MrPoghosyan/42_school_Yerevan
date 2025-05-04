#include "header.h"

int	get_index(const int *arr, int n, int size)
{
	int	index;

	index = 0;
	while (size--)
	{
		if (n > *arr)
			++index;
		++arr;
	}
	return (index);
}

void	free_node_chain(t_node **head)
{
	t_node	*tmp;

	while (*head)
	{
		tmp = (*head)->next;
		free(*head);
		*head = tmp;
	}
	*head = NULL;
}

int	cread_node(t_node **new_node, int value, int index)
{
	*new_node = (t_node *)malloc(sizeof(t_node));
	if (!(*new_node))
		return (0);
	(*new_node)->value = value;
	(*new_node)->index = index;
	(*new_node)->next = NULL;
	return (1);
}
