void sort_int_tab(int *tab, unsigned int size)
{
	unsigned int i;
	int temp;
	int swapped = 1;

	if (size < 2)
		return;
	while (swapped)
	{
		swapped = 0;
		i = 0;
		while (i < size - 1)
		{
			if (tab[i] > tab[i + 1])
			{
				temp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = temp;
				swapped = 1;
			}
			++i;
		}
	}
}

#include <stdio.h>

int main()
{
	int arr[] = {5, 2, 5, 8, 1, 3, 4, 8};
	unsigned int size = sizeof(arr) / sizeof(int);

	sort_int_tab(arr, size);

	for (unsigned int i = 0; i < size; ++i)
		printf("%d ", arr[i]);
	printf("\n");

	return 0;
}
