#include "flood_fill.h"

static void fill(char **tab, t_point size, int x, int y, char target)
{
	if (x < 0 || x >= size.x || y < 0 || y >= size.y)
		return;
	if (tab[y][x] != target)
		return;

	tab[y][x] = 'F';

	fill(tab, size, x + 1, y, target);	// right
	fill(tab, size, x - 1, y, target);	// left
	fill(tab, size, x, y + 1, target);	// down
	fill(tab, size, x, y - 1, target);	// up
}

void  flood_fill(char **tab, t_point size, t_point begin)
{
	char	target = tab[begin.y][begin.x];

	if (target == 'F')
		return;
	fill (tab, size, begin.x, begin.y, target);
}
