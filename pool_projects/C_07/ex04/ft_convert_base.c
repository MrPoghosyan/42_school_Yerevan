#include <stdlib.h>
#include "ft_convert_base2.c"

// Converts an integer to a string in a specified base
char *convert_int_to_base(int num, char *base_to)
{
    int base_len = ft_strlen(base_to);
    int len = 1;
    int temp_num = num;

    // Handle special case for 0
    if (num == 0)
    {
        char *result = malloc(2);
        if (!result)
            return NULL;
        result[0] = base_to[0];
        result[1] = '\0';
        return result;
    }

    // Calculate the length of the number in the new base
    while (temp_num /= base_len)
        len++;

    char *result = malloc(len + 1);
    if (!result)
        return NULL;
    result[len] = '\0';

    // Convert the number to the target base
    while (len--)
    {
        result[len] = base_to[num % base_len];
        num /= base_len;
    }

    return result;
}

char *ft_convert_base(char *nbr, char *base_from, char *base_to)
{
    int num;
    char *result;

    // Check if the base_from and base_to are valid
    if (!is_valid_base(base_from) || !is_valid_base(base_to))
        return NULL;

    // Convert the number from the base_from to decimal
    num = ft_atoi_base(nbr, base_from);

    // Convert the decimal number to the base_to
    result = convert_int_to_base(num, base_to);

    return result;
}

