#include "checker.h"

static void	checker(t_node **a)
{
	t_node	*b;
	char	*command;

	b = NULL;
	while (1)
	{
		command = get_command();
		if (!command)
			break ;
		if (command[0] == '\0')
		{
			free(command);
			write(2, "Error\n", 6);
			exit (1);
		}
		execute_instruction(command, a, &b);
		free(command);
	}
	if (is_sorted(*a) && b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
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
				return (free(arr), 0);
			a_node = add_node((const int *)arr, size);
			checker(&a_node);
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
