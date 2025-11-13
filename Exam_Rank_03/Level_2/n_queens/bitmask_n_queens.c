#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

static void    putnbr(int n)
{
    char c;
    if (n >= 10)
        putnbr(n / 10);
    c = (n % 10) + '0';
    write(1, &c, 1);
}

static void    print_solution(int *sol, int n)
{
    for (int i = 0; i < n; i++)
    {
        putnbr(sol[i]);
        if (i < n - 1)
            write(1, " ", 1);
    }
    write(1, "\n", 1);
}

static void    solve(int n, int col, int cols, int diag1, int diag2, int *sol)
{
    if (col == n)
    {
        print_solution(sol, n);
        return;
    }
    int available = ((1 << n) - 1) & ~(cols | diag1 | diag2);
    while (available)
    {
        int bit = available & -available; // lowest set bit
        int row = __builtin_ctz(bit);     // row index (count trailing zeros)

        sol[col] = row;
        solve(n, col + 1,
              cols | bit,
              (diag1 | bit) << 1,
              (diag2 | bit) >> 1,
              sol);

        available &= available - 1; // remove lowest set bit
    }
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return (1);
    int n = atoi(argv[1]);
    if (n <= 0)
        return (0);

    int *solution = malloc(sizeof(int) * n);
    if (!solution)
        return (1);

    solve(n, 0, 0, 0, 0, solution);

    free(solution);
    return (0);
}
