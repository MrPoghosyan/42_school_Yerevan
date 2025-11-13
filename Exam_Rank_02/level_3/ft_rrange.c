#include <stdlib.h>

int     *ft_rrange(int start, int end)
{
	int *arr;
	int i = 0;
	int len;

	if (start < end)
		len = end - start + 1;
	else
		len = start - end + 1;
	
	arr = (int *)malloc(sizeof(int) * len);
	if (!arr)
		return (NULL);
	while (i < len)
	{
		arr[i] = end;
		if (start < end)
			end--;
		else
			end++;
		i++;
	}
	return arr;
}

#include <stdio.h>

int main(int argc, char **argv)
{
	if (argc == 3)
	{
		int len;
		int a = atoi(argv[1]);
		int b = atoi(argv[2]);

		if (a < b)
			len = b - a +1;
		else
			len = a - b +1;
		int *arr = ft_rrange(a, b);
		if (!arr)
			return (printf("NULL\n"), 1);

		for (int i = 0; i < len; ++i) {
			printf("%d ", arr[i]);
		}
		free(arr);
	}
	printf("\n");
	return 0;
}
