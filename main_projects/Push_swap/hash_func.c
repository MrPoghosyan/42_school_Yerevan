#include "header.h"

t_node *g_hash_table[TABLE_SIZE] = {0};

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

int	check_and_add(int value)
{
	unsigned long	index;
	t_node			*current;
	t_node			*new;

	index = hash_int(value);
	current = g_hash_table[index];
	while (current)
	{
		if (current->value == value)
			return (0);
		current = current->next;
	}
	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		return (-1);
	new->value = value;
	new->next = g_hash_table[index];
	g_hash_table[index] = new;
	return (1);
}

void	free_table(void)
{
	t_node	*current;
	t_node	*tmp;
	int		i;

	i = 0;
	while (i < TABLE_SIZE)
	{
		current = g_hash_table[i];
		while (current)
		{
			tmp = current;
			current = current->next;
			free(tmp);
		}
		g_hash_table[i] = NULL;
		++i;
	}
}
