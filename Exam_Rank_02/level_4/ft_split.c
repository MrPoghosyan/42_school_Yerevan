#include <stdlib.h>

int     is_separator(char c)
{
        return (c == ' ' || c == '\t' || c == '\n');
}

int     words_count(char *str)
{
        int count = 0;
        int in_word = 0;

        while (*str)
        {
                if (!is_separator(*str) && !in_word)
                {
                        in_word = 1;
                        count++;
                }
                else if (is_separator(*str))
                        in_word = 0;
                str++;
        }
        return count;
}

char *word_dup(char *start, int len)
{
        char *word = malloc(len + 1);
        int i = 0;

        if (!word)
                return NULL;
        while (i < len)
        {
                word[i] = start[i];
                i++;
        }
        word[i] = '\0';
        return word;
}

char    **ft_split(char *str)
{
        char **result;
        int i = 0, len;

        if (!str)
                return NULL;  // Ստուգում, եթե str-ը NULL է, վերադարձնել NULL

        result = (char **)malloc(sizeof(char *) * (words_count(str) + 1));
        if (!result)
                return NULL;

        while (*str)
        {
                if (!is_separator(*str))
                {
                        len = 0;
                        while (str[len] && !is_separator(str[len]))
                                len++;
                        result[i++] = word_dup(str, len);
                        str += len;
                }
                else
                        str++;
        }
        result[i] = NULL;
        return result;
}

#include <stdio.h>

int main()
{
        char tox[] = "Barev ashxar, vonc es!";
        printf("%s\n", tox);

        char **str = ft_split(tox);
        if (str)
        {
                for (int i = 0; str[i] != NULL; ++i)  // Ստուգում ենք, թե երբ ցուցակը վերջանում է
                {
                        printf("%s\n", str[i]);
                        free(str[i]);  // Հիշողության ազատում
                }
                free(str);  // Ազատում ենք նաև գլխավոր ցուցակը
        }

        return 0;
}
