NAME	= pipex
BONUS	= pipex_bonus

CC		= cc
CFLAGS	= -g -Wall -Wextra -Werror

LIBFT_DIR	= Libft
LIBFT		= $(LIBFT_DIR)/libft.a
INCLUDE		= -I. -I$(LIBFT_DIR)

SRC			= main.c pipex.c pipex_utils.c utils.c
BONUS_SRC	= pipex_bonus.c utils_bonus.c pipex_utils.c utils.c get_next_line.c get_next_line_utils.c

OBJ			= $(SRC:.c=.o)
BONUS_OBJ	= $(BONUS_SRC:.c=.o)

# Targets
all: $(LIBFT) $(NAME)

bonus: $(LIBFT) $(BONUS)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(BONUS): $(BONUS_OBJ)
	$(CC) $(CFLAGS) $(BONUS_OBJ) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
