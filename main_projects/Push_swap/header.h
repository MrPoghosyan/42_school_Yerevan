/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapoghos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 11:36:37 by vapoghos          #+#    #+#             */
/*   Updated: 2025/04/29 19:20:29 by vapoghos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdio.h> // For printf()
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "../Libft/libft.h"

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

//Valid arguments
int		is_valid_integer(const char *str);
int		is_valid_format(const char *str); // hanel maqur funkciayi hamar.//
int		is_within_int_range(const char *str);
int		validate_argument(const char **str, int count);
int		duplicates(int *arr, int size);
int		*add_int(const char **str, int count, int size);
void	insertion_sort(int *arr, int size);
int		count_int(const char **str, int count);
void	free_split(char **split);

// add stack
int		cread_node(t_node **new_node, int value, int index);
void	free_node_chain(t_node **head);
int		get_index(const int *arr, int n, int size);
t_node	*add_node(const int *arr, int size);

// sorts func
void	sort_three(t_node **a);
void	insertion_sort_n(t_node **a, t_node **b, int size);
void	radix_sort(t_node **a, t_node **b, int size);

// operations.c
void	sa(t_node **a); //+
void	sb(t_node **b);
void	ss(t_node **a, t_node **b);

void	pa(t_node **a, t_node **b); //-
void	pb(t_node **a, t_node **b); //+

void	ra(t_node **a); //+
void	rb(t_node **b);
void	rr(t_node **a, t_node **b);

void	rra(t_node **a); //+
void	rrb(t_node **b);
void	rrr(t_node **a, t_node **b);

#endif
