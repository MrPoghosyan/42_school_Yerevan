#include <unistd.h>
#include <stdio.h>

static int is_balanced(const char *s)
{
    int count = 0;
    for (int i = 0; s[i]; i++)
    {
        if (s[i] == '(') count++;
        else if (s[i] == ')')
        {
            if (count == 0) return 0;
            count--;
        }
    }
    return (count == 0);
}

static void dfs(char *s, int start, int lremove, int rremove)
{
    if (lremove == 0 && rremove == 0)
    {
        if (is_balanced(s))
            puts(s);
        return;
    }

    for (int i = start; s[i]; i++)
    {
        // consecutive duplicates skip
        if (i > start && s[i] == s[i-1])
            continue;

        if (s[i] == '(' && lremove > 0)
        {
            char saved = s[i];
            s[i] = ' ';
            dfs(s, i + 1, lremove - 1, rremove);
            s[i] = saved;
        }
        else if (s[i] == ')' && rremove > 0)
        {
            char saved = s[i];
            s[i] = ' ';
            dfs(s, i + 1, lremove, rremove - 1);
            s[i] = saved;
        }
    }
}

int main(int ac, char **av)
{
    if (ac != 2) return 0;
    char *s = av[1];
    int lremove = 0, rremove = 0;

    // count minimal removals
    for (int i = 0; s[i]; i++)
    {
        if (s[i] == '(')
            lremove++;
        else if (s[i] == ')')
        {
            if (lremove > 0)
                lremove--;
            else
                rremove++;
        }
    }
    dfs(s, 0, lremove, rremove);
    return 0;
}
