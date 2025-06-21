#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

int ft_strlen(char *s);
int ft_strchr(char *s, char c);
char *ft_strjoin(char *s1, char *s2);
char *read_line(char *stash);
char *update_stash(char *stash);

#endif
