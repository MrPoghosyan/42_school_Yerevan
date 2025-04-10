#include "header.h"

unsigned long hash_djb2(const char *str)
{
	unsigned long	hash;
	int				c;

	hash = 5381;
	while ((c = *str++))
		hash = ((hash << 5) + hash) + c;
	return (hash);
}

int	check_and_add(char *str)
{
	unsigned long	index;
	t_node			*current;
	t_node			*new;

	index = hash_djb2(str) % TABLE_SIZE;
	printf("index: %u", index);
	current = g_hash_table[index];
	while (current)
	{
		if (ft_strcmp(current->str, str) == 0)
			return (1);
		current = current->next;
	}
	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		return (-1);
	new->str = ft_strdup(str);
	new->next = g_hash_table[index];
	g_hash_table[index] = new;
	return (0);
}

void	free_table()
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
			free(tmp->str);
			free(tmp);
		}
		g_hash_table[i] = NULL;
		++i;
	}
}

int	hash_duplicates(char **arr, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (check_and_add(arr[i]) == 1)
		{
			free_table();
			exit (1);
		}
		++i;
	}
	free_table();
	return (0);
}
