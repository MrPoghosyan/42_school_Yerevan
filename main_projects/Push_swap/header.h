#ifndef HEADER_H
# define HEADER_H

# include <stdio.h> // For printf()
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "/home/aranea/42_school_Erevan/main_projects/Libft/libft.h"

# define TABLE_SIZE 1000

typedef struct s_stack
{
    int *arr;
    int size;
} t_stack;

typedef struct s_node
{
    int             value;
    struct s_node   *next;
} t_node;

extern t_node  *g_hash_table[TABLE_SIZE];

t_stack         append_valid_int(int argc, char **argv);
void            free_steck(t_stack arr);
int             is_valid_integer(const char *str);

//Valid arguments
int             is_valid_format(const char *str);
int             is_within_int_range(const char *str);
int             validate_argument(const char **str, int count);
int             hash_duplicates(const char **arg);

// Hash function
unsigned long   hash_int(int n);
int             check_and_add(int value);
void            free_table(void);

#endif

