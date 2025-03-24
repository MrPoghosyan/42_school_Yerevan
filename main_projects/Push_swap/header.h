#ifndef HEADER_H
# define HEADER_H

#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include "/home/aranea/42_school_Erevan/main_projects/Libft/libft.h"

typedef struct s_stack
{
    int *arr;
    int size;
} t_stack;

int     check_int(int count, const char **arg);
t_stack append_valid_int(int argc, char **argv);
void    free_steck(t_stack arr);

#endif
