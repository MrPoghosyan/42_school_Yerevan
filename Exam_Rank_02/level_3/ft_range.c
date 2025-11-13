#include <stdlib.h>

int *ft_range(int start, int end)
{
	int len = (start <= end) ? (end - start +1) : (start - end +1);
	int *arr = (int *)malloc(sizeof(int) * len);
	int i = 0;

	if (!arr)
		return (NULL);
	while (i < len)
	{
		arr[i] = (start <= end) ? (start + i) : (start - i);
		i++;
	}
	return (arr);
}

#include <stdio.h>

int main(void)
{
    int *arr;
    int i;
    int start = -2;
    int end = 2;
    int len = (start <= end) ? (end - start + 1) : (start - end + 1);

    arr = ft_range(start, end);

    for (i = 0; i < len; i++)
        printf("%d ", arr[i]);
    printf("\n");

    free(arr);
    return 0;
}
