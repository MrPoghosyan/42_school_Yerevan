#include "ft_list.h"

void    ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	while (begin_list)
	{
		f(begin_list->data);
		begin_list = begin_list->next;
	}
}

#include <stdio.h>

void print_int(void *data)
{
	printf("%d\n", *(int *)data);
}

int main()
{
	int a = 123, b = 567, c = 5986;
	t_list n1 = {NULL, &a};
	t_list n2 = {&n1, &b};
	t_list n3 = {&n2, &c};

	ft_list_foreach(&n3, &print_int);

	return 0;
}
