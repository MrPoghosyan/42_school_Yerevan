#include "header.h"

void	sort_three(t_node **a)
{
	int	x;
	int	y;
	int	z;

	x = (*a)->value;
	y = (*a)->next->value;
	z = (*a)->next->next->value;
	if (x > y && y < z && x < z)
		sa(a);
	else if (x > y && y > z)
	{
		sa(a);
		rra(a);
	}
	else if (x > y && y < z && x > z)
		ra(a);
	else if (x < y && y > z && x < z)
	{
		sa(a);
		ra(a);
	}
	else if (x < y && y > z && x > z)
		rra(a);
}

static int	find_min(t_node *stack)
{
	int	min;

	min = stack->value;
	while (stack)
	{
		if (stack->value < min)
			min = stack->value;
		stack = stack->next;
	}
	return (min);
}

static int	get_position(t_node *stack, int value)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->value == value)
			return (pos);
		pos++;
		stack = stack->next;
	}
	return (-1);
}

void	insertion_sort_n(t_node **a, t_node **b, int size)
{
	int	pushed;
	int	min;
	int	pos;

	pushed = 0;
	while (size > 3)
	{
		min = find_min(*a);
		pos = get_position(*a, min);
		if (pos <= size / 2)
			while (pos-- > 0)
				ra(a);
		else
			while (pos++ < size)
				rra(a);
		pb(a, b);
		pushed++;
		size--;
	}
	sort_three(a);
	while (pushed--)
		pa(a, b);
}
