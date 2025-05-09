#include <stdlib.h>
#include "ft_list.h"

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*current;
	t_list	*prev;
	t_list	*tmp;

	while (*begin_list && cmp((*begin_list)->data, data_ref) == 0)
	{
		tmp = *begin_list;
		*begin_list = (*begin_list)->next;
		free(tmp);
	}
	prev = *begin_list;
	if (!prev)
		return;
	current = prev->next;

	while (current)
	{
		if (cmp(current->data, data_ref) == 0)
		{
			prev->next = current->next;
			free(current);
			current = prev->next;
		}
		else
		{
			prev = current;
			current = current->next;
		}
	}
}

#include <stdio.h>	// printf()
#include <string.h>	// strcmp()
					//
// === Օգտակար ֆունկցիա նոր տարր ստեղծելու համար ===
t_list *create_elem(char *data)
{
	t_list *new = malloc(sizeof(t_list));
	if (!new) return NULL;
	new->data = data;
	new->next = NULL;
	return new;
}

// === Համեմատման ֆունկցիա strcmp-ի միջոցով ===
int cmp(void *a, void *b)
{
	return strcmp((char *)a, (char *)b);
}

// === Տպում է ամբողջ ցուցակը ===
void print_list(t_list *head)
{
	while (head)
	{
		printf("%s -> ", (char *)head->data);
		head = head->next;
	}
	printf("NULL\n");
}

// === Գլխավոր ֆունկցիա ===
int main(void)
{
	// Քայլ 1. Ստեղծում ենք ցուցակ՝ "one" -> "two" -> "three" -> "two" -> NULL
	t_list *head = create_elem("one");
	head->next = create_elem("two");
	head->next->next = create_elem("three");
	head->next->next->next = create_elem("two");

	printf("Before removal:\n");
	print_list(head);

	// Քայլ 2. Կանչում ենք ft_list_remove_if՝ հեռացնելու բոլոր "two" արժեքները
	ft_list_remove_if(&head, "two", cmp);

	printf("\nAfter removal of \"two\":\n");
	print_list(head);

	// Քայլ 3. Ազատում ենք մնացած հիշողությունը
	t_list *tmp;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}

	return 0;
}
