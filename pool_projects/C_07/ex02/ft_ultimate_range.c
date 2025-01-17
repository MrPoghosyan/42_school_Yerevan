#include <stdlib.h>

int ft_ultimate_range(int **range, int min, int max)
{
    int *arr;
    int i;
    int size;

    if (min >= max)
    {
        *range = NULL;
        return (0);
    }
    size = max - min;
    arr = (int *)malloc(size * sizeof(int));
    if (!arr)
    {
        *range = NULL;
        return (-1);
    }
    i = 0;
    while (min < max)
        arr[i++] = min++;
    *range = arr;
    return (size);
}
/*
#include <stdio.h>

int ft_ultimate_range(int **range, int min, int max);

int main(void)
{
    int *range;
    int size;
    int i;

    size = ft_ultimate_range(&range, 1, 5);
    if (size == -1)
    {
        printf("Memory allocation failed\n");
        return (1);
    }
    else if (size == 0)
    {
        printf("Invalid range\n");
        return (0);
    }

    for (i = 0; i < size; i++)
        printf("%d ", range[i]);
    printf("\n");

    free(range); // Ազատում ենք հատկացված հիշողությունը
    return (0);
}
*/
