#include <unistd.h>
#include <stdio.h>

int ft_strlen(const char *s)
{
    int len = 0;
    while (s[len])
        len++;
    return (len);
}

void ft_swap(char *a, char *b)
{
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

static void ft_sort(char *s)
{
    int len = ft_strlen(s);
    for (int i = 0; i < len - 1; i++)
        for (int j = i + 1; j < len; j++)
            if (s[i] > s[j])
                ft_swap(&s[i], &s[j]);
}

// find next permutation in lexicographic order
int next_permutation(char *s, int n)
{
    int i = n - 2;
    while (i >= 0 && s[i] >= s[i + 1])
        i--;
    if (i < 0)
        return 0;

    int j = n - 1;
    while (s[j] <= s[i])
        j--;
    ft_swap(&s[i], &s[j]);

    // reverse suffix
    int l = i + 1, r = n - 1;
    while (l < r)
        ft_swap(&s[l++], &s[r--]);
    return 1;
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return 1;

    char *s = argv[1];
    int n = ft_strlen(s);

    ft_sort(s);              // start with smallest lexicographic
    do {
        puts(s);
    } while (next_permutation(s, n));

    return 0;
}
