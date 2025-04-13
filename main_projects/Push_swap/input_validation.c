#include "header.h"

int is_valid_format(const char *str)
{
	while (*str)
	{
		if (!(*str >= '0' && *str <= '9') || !(*str == ' ' || *str == '\t')
			|| !(*str == '+' || *str == '-'))
		{
			write (1, "Error\n", 6);
			exit (EXIT_FAILURE);
		}
		++str;
	}
}
int is_within_int_range(const char *str);
int has_duplicate(t_list *stack, int value);
int validate_argument(const char *str, t_list *stack);

