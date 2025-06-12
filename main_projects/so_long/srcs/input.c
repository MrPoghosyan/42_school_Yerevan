#include "../includes/so_long.h"

int handle_keypress(int keycode, t_game *game)
{
    if (keycode == ESC || keycode == Q)
        close_game(game);
    return (0);
}
