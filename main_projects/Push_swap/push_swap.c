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
	t_stack arr;

	if (argc <= 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	if (!check_int(argc, (const char **)argv))
	{
		write (1, "Error\n", 6);
		return (1);
	}
	else
		write(1, "OK!\n", 4);
	arr = append_valid_int(argc, argv);
// TESTER
	
	int	i = 0;
	while (i < argc - 1)
	{
		printf("t_stack->arr: %d\n", arr.arr[i]);
		i++;
	}
	printf("t_stack->size: %d\n", arr.size);
// END

	free(arr.arr);

//	push_swap(arr);
	return (0);
}
