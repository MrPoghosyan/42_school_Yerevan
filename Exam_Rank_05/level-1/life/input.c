#include "life.h"

static void	move_pen(t_pen *pen, t_board *board, char cmd)
{
	if (cmd == 'w' && pen->y > 0)
		pen->y--;
	else if (cmd == 's' && pen->y < board->height - 1)
		pen->y++;
	else if (cmd == 'a' && pen->x > 0)
		pen->x--;
	else if (cmd == 'd' && pen->x < board->width - 1)
		pen->x++;
}

static void	apply_command(t_pen *pen, t_board *board, char cmd)
{
	if (cmd == 'x')
		pen->drawing = !pen->drawing;
	else
		move_pen(pen, board, cmd);
	if (pen->drawing && (cmd == 'w' || cmd == 'a' || cmd == 's'
			|| cmd == 'd' || cmd == 'x'))
		set_cell(board, pen->x, pen->y, 1);
}

void	read_input(t_board *board)
{
	t_pen	pen;
	char	buf[512];
	ssize_t	n;
	ssize_t	i;

	pen.x = 0;
	pen.y = 0;
	pen.drawing = 0;
	n = read(0, buf, sizeof(buf));
	while (n > 0)
	{
		i = 0;
		while (i < n)
		{
			apply_command(&pen, board, buf[i]);
			i++;
		}
		n = read(0, buf, sizeof(buf));
	}
}
