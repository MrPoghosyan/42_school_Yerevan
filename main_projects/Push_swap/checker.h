#ifndef CHECKER_H
# define CHECKER_H

# include "./header.h"

void	execute_instruction(char *instr, t_node **a, t_node **b);
char	*get_command(void);
int		is_sorted(t_node *a);

// operations.c
void	sa_c(t_node **a);
void	sb_c(t_node **b);
void	ss_c(t_node **a, t_node **b);

void	pa_c(t_node **a, t_node **b);
void	pb_c(t_node **a, t_node **b);

void	ra_c(t_node **a);
void	rb_c(t_node **b);
void	rr_c(t_node **a, t_node **b);

void	rra_c(t_node **a);
void	rrb_c(t_node **b);
void	rrr_c(t_node **a, t_node **b);

#endif
