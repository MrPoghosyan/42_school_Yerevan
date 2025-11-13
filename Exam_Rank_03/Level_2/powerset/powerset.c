#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

static void putnbr_fd(int n, int fd)
{
	char c;
	long num = n;

	if (num < 0){
		write(1, "-", 1);
		num = -num;
	}
	if (num >= 10)
		putnbr_fd(num / 10, fd);
	c = (num % 10) + '0';
	write(fd, &c, 1);
}

static void print_subset(int *subset, int size)
{
	for (int i = 0; i < size; ++i){
		putnbr_fd(subset[i], 1);
		if (i != size -1)
			write(1, " ", 1);
	}
	write(1, "\n", 1);
}

static void find_subsets(int *set, int set_size, int target, int *subset, int subset_size, int index, int current_sum)
{
	if (index == set_size){
		if (current_sum == target)
			print_subset(subset, subset_size);
		return ;
	}
	//choose to include the given element in the subset
	subset[subset_size] = set[index];
	find_subsets(set, set_size, target, subset, subset_size +1, index +1, current_sum + set[index]);
	// exclude the given element
	find_subsets(set, set_size, target, subset, subset_size, index +1, current_sum);
}

int main(int argc, char **argv)
{
	if (argc < 2)
		return 1;

	int target = atoi(argv[1]);
	int set_size = argc -2;
	int *set = (int *)malloc(sizeof(int) * set_size);
	int *subset = (int *)malloc(sizeof(int) * set_size);

	if (!set || !subset)
		return 1; //malloc error
	for (int i = 0; i < set_size; ++i){
		set[i] = atoi(argv[i +2]);
	}
	find_subsets(set, set_size, target, subset, 0, 0, 0);

	free(set);
	free(subset);
	return 0;
}
