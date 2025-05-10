#include "checker.h"

void	pb_c(t_node **a, t_node **b)
{
	t_node	*tmp;

	if (!*a)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = *b;
	*b = tmp;
}

void	sb_c(t_node **b)
{
	t_node	*tmp;

	if (*b && (*b)->next)
	{
		tmp = *b;
		*b = (*b)->next;
		tmp->next = (*b)->next;
		(*b)->next = tmp;
	}
}

void	rb_c(t_node **b)
{
	t_node	*first;
	t_node	*last;

	if (*b && (*b)->next)
	{
		first = *b;
		*b = (*b)->next;
		first->next = NULL;
		last = *b;
		while (last->next)
			last = last->next;
		last->next = first;
	}
}

void	rrb_c(t_node **b)
{
	t_node	*prev;
	t_node	*last;

	if (*b && (*b)->next)
	{
		last = *b;
		while (last->next)
		{
			prev = last;
			last = last->next;
		}
		prev->next = NULL;
		last->next = *b;
		*b = last;
	}
}
