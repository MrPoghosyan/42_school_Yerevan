#ifndef BSQ_H
# define BSQ_H

# define _GNU_SOURCE
# include <stdio.h>
# include <stdlib.h>
# include <errno.h>

typedef struct s_map
{
	int		rows;
	int		cols;
	char	empty;
	char	obstacle;
	char	full;
	char	**grid;
	int		*lengths;
}	t_map;

int		process_stream(FILE *fp);
int		read_header(FILE *fp, t_map *map);
int		read_grid(FILE *fp, t_map *map);
int		check_grid(t_map *map);
void	solve_map(t_map *map);
void	print_map(t_map *map);
void	free_map(t_map *map);

#endif
