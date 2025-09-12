#include <unistd.h>
#include <stdlib.h>

static int  ft_strlen(char *s)
{
    int i = 0;
    while (s[i])
        i++;
    return (i);
}

static void ft_swap(char *a, char *b)
{
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

static void ft_sort(char *s)
{
    int len = ft_strlen(s);
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            if (s[i] > s[j])
                ft_swap(&s[i], &s[j]);
        }
    }
}

static void putstr(char *s, int n)
{
    write(1, s, n);
    write(1, "\n", 1);
}

static void backtrack(char *str, int len, int used, char *buf, int depth)
{
    if (depth == len)
    {
        putstr(buf, len);
        return;
    }
    for (int i = 0; i < len; i++)
    {
        if (!(used & (1 << i)))
        {
            buf[depth] = str[i];
            backtrack(str, len, used | (1 << i), buf, depth + 1);
        }
    }
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return (1);

    char *s = argv[1];
    int len = ft_strlen(s);
    ft_sort(s); // important! ensures alphabetical order

    char *buf = malloc(len);
    if (!buf)
        return (1);

    backtrack(s, len, 0, buf, 0);

    free(buf);
    return (0);
}
