#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

static void putnbr_fd(int n, int fd)
{
    char c;
    long num = n;
    if (num < 0) {
        write(fd, "-", 1);
        num = -num;
    }
    if (num >= 10)
        putnbr_fd(num / 10, fd);
    c = (num % 10) + '0';
    write(fd, &c, 1);
}

static void print_subset(int *set, int set_size, int mask)
{
    int first = 1;
    for (int i = 0; i < set_size; i++) {
        if (mask & (1 << i)) {
            if (!first)
                write(1, " ", 1);
            putnbr_fd(set[i], 1);
            first = 0;
        }
    }
    write(1, "\n", 1);
}

int main(int argc, char **argv)
{
    if (argc < 2)
        return 1;

    int target = atoi(argv[1]);
    int set_size = argc - 2;
    int *set = malloc(sizeof(int) * set_size);
    if (!set)
        return 1;

    for (int i = 0; i < set_size; i++)
        set[i] = atoi(argv[i + 2]);

    int total = 1 << set_size;
    for (int mask = 0; mask < total; mask++) {
        int sum = 0;
        for (int i = 0; i < set_size; i++)
            if (mask & (1 << i))
                sum += set[i];
        if (sum == target)
            print_subset(set, set_size, mask);
    }
    free(set);
    return 0;
}
