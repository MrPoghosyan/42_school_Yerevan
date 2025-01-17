#include <stdlib.h>

int is_charset(char c, char *charset)
{
    while (*charset)
    {
        if (c == *charset)
            return 1;  // Character found in charset
        charset++;
    }
    return 0;  // Character not found in charset
}

int count_words(char *str, char *charset)
{
    int count = 0;
    int in_word = 0;

    while (*str)
    {
        if (is_charset(*str, charset))
            in_word = 0;  // We're in a delimiter, so we're not in a word
        else if (!in_word)
        {
            in_word = 1;  // We've found a new word
            count++;
        }
        str++;
    }
    return count;
}

char *get_next_word(char *str, char *charset)
{
    char *start = str;
    while (*str && !is_charset(*str, charset))
        str++;  // Find the end of the word
    char *word = (char *)malloc((str - start + 1) * sizeof(char));  // Allocate memory for the word
    if (!word)
        return NULL;  // Allocation failure
    int i = 0;
    while (start < str)
    {
        word[i++] = *start++;  // Copy the word
    }
    word[i] = '\0';  // Null-terminate the string
    return word;
}

char **ft_split(char *str, char *charset)
{
    if (!str || !charset)
        return NULL;  // Handle NULL input

    int words_count = count_words(str, charset);
    char **result = (char **)malloc((words_count + 1) * sizeof(char *));  // Allocate memory for the array of strings
    if (!result)
        return NULL;  // Allocation failure

    int i = 0;
    while (*str)
    {
        if (!is_charset(*str, charset))  // Found the start of a word
        {
            result[i++] = get_next_word(str, charset);
            while (*str && !is_charset(*str, charset))
                str++;  // Skip the word to the next delimiter
        }
        else
        {
            str++;  // Skip the delimiter
        }
    }
    result[i] = NULL;  // Null-terminate the array of strings
    return result;
}
/*
 #include <stdio.h>

int main()
{
    char **result = ft_split("Hello, world! How are you?", " ,!?");
    int i = 0;
    while (result[i])
    {
        printf("Word: %s\n", result[i]);
        free(result[i]);  // Don't forget to free each string
        i++;
    }
    free(result);  // Free the array of strings
    return 0;
}
*/
