#include <stdlib.h>
#include <unistd.h>

void print_solution(int *board, int n)
{
	char buf[12];

	for (int i = 0; i < n; ++i){
		int len = 0;
		int val = board[i];

		if (val == 0)
			buf[len++] = '0';
		else {
			int tmp = val;
			int rev[10], ri = 0;
			while (tmp) {
				rev[ri++] = tmp % 10;
				tmp /= 10;
			}
			for (int j = ri -1; j >= 0; --j)
				buf[len++] = rev[j] + '0';
		}
		buf[len++] = (i == n - 1) ? '\n' : ' ';
		write(1, buf, len);
	}
}
int ft_abs(int x)
{
	return (x < 0) ? -x : x;
}

int is_safe(int *board, int col, int row)
{
	for (int i = 0; i < col; ++i) {
		if (board[i] == row || ft_abs(board[i] - row) == ft_abs(i - col))
			return 0;
	}
	return 1;
}

void solve(int *board, int col, int n)
{
	if (col == n)
	{
		print_solution(board, n);
		return ;
	}
	for (int row = 0; row < n; ++row) {
		if (is_safe(board, col, row)) {
			board[col] = row;
			solve(board, col +1, n);
		}
	}
}

int main(int argc, char **argv)
{
	if (argc != 2)
		return 1;
	int n = atoi(argv[1]);
	if (n <= 0)
		return 0;
	int *board = (int *)malloc(sizeof(int) * n);
	if (!board)
		return 1;
	solve(board, 0, n);
	free(board);
	return 0;
}
