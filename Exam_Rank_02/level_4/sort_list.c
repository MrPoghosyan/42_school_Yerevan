#include "list.h"

int cmp(int a, int b);
#include "list.h"

t_list  *sort_list(t_list *lst, int (*cmp)(int, int))
{
    t_list *start;
    int swapped = 1;
    int temp;

    if (!lst || !lst->next) // դատարկ կամ մեկ տարրով ցուցակ
        return (lst);

    start = lst;
    while (swapped)
    {
        swapped = 0;
        lst = start; // ԱՆՊԱՅՄԱՆ ամեն անգամ lst֊ը վերադարձնենք սկզբում
        while (lst && lst->next)
        {
            if (!cmp(lst->data, lst->next->data))
            {
                temp = lst->data;
                lst->data = lst->next->data;
                lst->next->data = temp;
                swapped = 1;
            }
            lst = lst->next;
        }
    }
    return (start);
}

#include <stdio.h>
#include <stdlib.h>

// Функция сравнения (по возрастанию)
int cmp(int a, int b)
{
	return (a <= b);
}

// Функция создания нового элемента
t_list *new_node(int data)
{
	t_list *node = malloc(sizeof(t_list));
	if (!node)
		return NULL;
	node->data = data;
	node->next = NULL;
	return node;
}

// Вывод списка
void print_list(t_list *head)
{
	while (head)
	{
		printf("%d ", head->data);
		head = head->next;
	}
	printf("\n");
}

// MAIN
int main(void)
{
	// Создаём список: 4 -> 2 -> 3 -> 1
	t_list *n1 = new_node(4);
	t_list *n2 = new_node(2);
	t_list *n3 = new_node(3);
	t_list *n4 = new_node(1);
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;

	printf("Before sorting: ");
	print_list(n1);

	t_list *sorted = sort_list(n1, cmp);

	printf("After sorting:  ");
	print_list(sorted);

	// Освобождение памяти
	free(n1);
	free(n2);
	free(n3);
	free(n4);

	return 0;
}
