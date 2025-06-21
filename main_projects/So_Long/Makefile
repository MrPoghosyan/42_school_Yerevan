NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
MLX_DIR = ./libs/minilibx-linux
MLX_LINUX = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lbsd

SRCS = srcs/main.c \
       srcs/map_validation/map_validation.c \
       srcs/map_validation/check_file.c \
       srcs/map_validation/read_map.c \
       srcs/map_validation/validate_contents.c \
       srcs/map_validation/walls_path.c \
       libs/gnl/get_next_line.c \
       libs/gnl/get_next_line_utils.c \
       srcs/utils.c srcs/graphics.c \
	   srcs/input.c srcs/cleanup.c \
	   srcs/player_movement.c \
	   srcs/game_init.c

OBJS = $(SRCS:.c=.o)

LIBFT = ./libs/Libft/libft.a
PRINTF = ./libs/ft_printf/libftprintf.a

all: mlx $(NAME)

mlx:
	@make -C $(MLX_DIR)

$(NAME): $(OBJS) $(LIBFT) $(PRINTF)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_LINUX) $(LIBFT) $(PRINTF) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -Iincludes -I$(MLX_DIR) -c $< -o $@

$(LIBFT):
	make -C ./libs/Libft

$(PRINTF):
	make -C ./libs/ft_printf

clean:
	rm -f $(OBJS)
	make -C ./libs/Libft clean
	make -C ./libs/ft_printf clean
	make -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C ./libs/Libft fclean
	make -C ./libs/ft_printf fclean

re: fclean all

.PHONY: all clean fclean re mlx
