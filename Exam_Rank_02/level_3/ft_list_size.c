#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	int size = 0;

	while (begin_list != NULL)
	{
		begin_list = begin_list->next;
		size++;
	}
	return (size);
}

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    t_list n3 = {NULL, "third"};
    t_list n2 = {&n3, "second"};
    t_list n1 = {&n2, "first"};

    printf("Size: %d\n", ft_list_size(&n1));  // Должно вывести: Size: 3
    return 0;
}
