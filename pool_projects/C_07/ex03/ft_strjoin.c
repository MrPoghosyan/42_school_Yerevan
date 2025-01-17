#include <stdlib.h>

int str_len(char *str)
{
    int len = 0;
    while (str[len] != '\0')
    {
        len++;
    }
    return len;
}

int get_total_len(int size, char **strs, char *sep)
{
    int total_len = 0;
    while (size-- > 0)
    {
        total_len += str_len(*strs++);
        if (size > 0)
        {
            total_len += str_len(sep);
        }
    }
    return total_len;
}

void copy_string(char *result, char *str, int *index)
{
    int j = 0;
    while (str[j] != '\0')
    {
        result[(*index)++] = str[j++];
    }
}

char *ft_strjoin(int size, char **strs, char *sep)
{
    if (size == 0)
    {
        char *empty_str = malloc(1);
        if (!empty_str)
        {
            return NULL;
        }
        empty_str[0] = '\0';
        return empty_str;
    }

    int total_len;
    total_len = get_total_len(size, strs, sep);
    char *result = malloc(total_len + 1);
    if (!result)
    {
        return NULL;
    }

    int index = 0;
    while (size-- > 0)
    {
        copy_string(result, *strs++, &index);
        if (size > 0)
        {
            int k = 0;
            while (sep[k] != '\0')
            {
                result[index++] = sep[k++];
            }
        }
    }

    result[index] = '\0';
    return result;
}
/*
#include <stdio.h>
int main()
{
    // Пример 1
    char *strs1[] = {"Hello", "world", "42"};
    int size1 = 3;
    char *sep1 = " ";

    char *result1 = ft_strjoin(size1, strs1, sep1);
    if (result1)
    {
        printf("Result 1: %s\n", result1);
        free(result1);  // Освобождаем память
    }

    // Пример 2
    char *strs2[] = {"This", "is", "a", "test"};
    int size2 = 4;
    char *sep2 = "-";

    char *result2 = ft_strjoin(size2, strs2, sep2);
    if (result2)
    {
        printf("Result 2: %s\n", result2);
        free(result2);  // Освобождаем память
    }

    // Пример 3 (пустая строка)
    char *strs3[] = {};
    int size3 = 0;
    char *sep3 = ", ";

    char *result3 = ft_strjoin(size3, strs3, sep3);
    if (result3)
    {
        printf("Result 3: '%s'\n", result3);
        free(result3);  // Освобождаем память
    }

    return 0;
}*/
