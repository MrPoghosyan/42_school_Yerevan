#include "checker.h"

static void	checker_error(char *instr)
{
	write(2, "Error\n", 6);
	free(instr);
	exit(1);
}

void	execute_instruction(char *instr, t_node **a, t_node **b)
{
	if (!ft_strncmp(instr, "sa\n", 3))
		sa_c(a);
	else if (!ft_strncmp(instr, "sb\n", 3))
		sb_c(b);
	else if (!ft_strncmp(instr, "ss\n", 3))
		ss_c(a, b);
	else if (!ft_strncmp(instr, "pa\n", 3))
		pa_c(a, b);
	else if (!ft_strncmp(instr, "pb\n", 3))
		pb_c(a, b);
	else if (!ft_strncmp(instr, "ra\n", 3))
		ra_c(a);
	else if (!ft_strncmp(instr, "rb\n", 3))
		rb_c(b);
	else if (!ft_strncmp(instr, "rr\n", 3))
		rr_c(a, b);
	else if (!ft_strncmp(instr, "rra\n", 4))
		rra_c(a);
	else if (!ft_strncmp(instr, "rrb\n", 4))
		rrb_c(b);
	else if (!ft_strncmp(instr, "rrr\n", 4))
		rrr_c(a, b);
	else
		checker_error(instr);
}

char	*get_command(void)
{
	char	*command;
	char	str[5];
	int		bytes_read;
	int		i;

	bytes_read = read(0, str, 4);
	if (bytes_read <= 0)
		return (NULL);
	command = (char *)ft_calloc(sizeof(char), 5);
	if (!command)
		return (NULL);
	i = 0;
	while (i < bytes_read && str[i] != '\n')
	{
		command[i] = str[i];
		i++;
	}
	if (i < bytes_read && str [i] == '\n')
		command[i] = '\n';
	return (command);
}

int	is_sorted(t_node *a)
{
	while (a && a->next)
	{
		if (a->value > a->next->value)
			return (0);
		a = a->next;
	}
	return (1);
}
