#ifndef HEADER_H
# define HEADER_H

# include <stdio.h> // For printf()
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "/home/aranea/42_school_Erevan/main_projects/Libft/libft.h"

# define TABLE_SIZE 10000

typedef struct s_stack
{
    int *arr;
    int size;
} t_stack;

typedef struct s_node
{
    char            *str;
    struct s_node   *next;
} t_node;

t_node  *g_hash_table[TABLE_SIZE];

//int     check_int(int count, const char **arg);
t_stack         append_valid_int(int argc, char **argv);
void            free_steck(t_stack arr);
//int             check_sign(const char *c, int *sign);
int             is_valid_integer(const char *str);

// Hash function
unsigned long   hash_djb2(const char *str);
int             check_and_add(char *str);
void            free_table();
int             hash_duplicates(char **arr, int count);

#endif
