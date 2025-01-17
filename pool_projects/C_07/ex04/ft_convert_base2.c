#include <unistd.h>

int ft_strlen(char *str)
{
    int len = 0;
    while (str[len])  // Count the number of characters in the string
        len++;
    return (len);
}

int is_valid_base(char *base)
{
    int i, j;

    if (ft_strlen(base) < 2)  // Base must have at least two characters
        return (0);
    
    i = 0;
    while (base[i])
    {
        // Check for invalid characters like '+' and '-'
        if (base[i] == '+' || base[i] == '-' || base[i] == ' '
            || (base[i] >= '\t' && base[i] <= '\r'))
            return (0);

        j = i + 1;
        while (base[j])  // Check for duplicate characters in the base
        {
            if (base[i] == base[j])
                return (0);
            j++;
        }
        i++;
    }
    return (1);  // Return true if the base is valid
}

int get_index(char c, char *base)
{
    int i = 0;
    while (base[i])
    {
        if (base[i] == c)  // Return the index of the character in the base
            return (i);
        i++;
    }
    return (-1);  // Return -1 if the character is not found in the base
}

void skip_whitespace_and_sign(char **str, int *sign)
{
    *sign = 1;
    while (**str == ' ' || (**str >= '\t' && **str <= '\r'))  // Skip whitespace
        (*str)++;
    
    while (**str == '-' || **str == '+')  // Handle the sign
    {
        if (**str == '-')
            *sign *= -1;
        (*str)++;
    }
}

int ft_atoi_base(char *str, char *base)
{
    int sign = 1;
    int result = 0;
    int base_len = ft_strlen(base);
    int index;

    skip_whitespace_and_sign(&str, &sign);

    while ((index = get_index(*str, base)) != -1)  // Iterate through the string and get the index for each character
    {
        result = result * base_len + index;
        str++;
    }

    return (result * sign);
}
