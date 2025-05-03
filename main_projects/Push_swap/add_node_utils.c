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

int	cread_node(t_node **head, t_node **tail, int value, int index)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (0);
	new->value = value;
	new->index = index;
	new->next = NULL;
	if (!*head)
	{
		*head = new;
		*tail = new;
	}
	else
	{
		(*tail)->next = new;
		*tail = new;
	}
	return (1);
}
