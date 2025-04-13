#include <stdio.h> // For printf()
#include "header.h"

/*
static void	push_swap(t_stack arr)
{
	///
}
*/
int	main(int argc, char **argv)
{
	int i;

	i = 1;
	if (argc > 1)
	{
		while (argv[i])
		{
			printf("argv: %s\nis_valit_int: %d\n", *argv, is_valid_integer(argv[i]));
			i++;
		}
		printf("hash_funqtia in main(): %d\n", hash_duplicates((argv +1), argc));
	}
	else
		write(1, "\n", 1);
	return (0);
}
