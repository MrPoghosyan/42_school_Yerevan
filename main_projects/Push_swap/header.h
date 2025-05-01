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
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	int		size;
	char	name;
}	t_stack;

//Valid arguments
int				is_valid_integer(const char *str);
int				is_valid_format(const char *str);
int				is_within_int_range(const char *str);
int				validate_argument(const char **str, int count);
int				hash_duplicates(int *arr, int size);
int				*add_int(const char **str, int count, int size);
void			insertion_sort(int *arr, int size);
int				count_int(const char **str, int count);
void			free_split(char **split);

// Hash function
unsigned long	hash_int(int n);

#endif
