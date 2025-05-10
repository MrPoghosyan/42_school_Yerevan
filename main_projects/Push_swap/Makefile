NAME	= push_swap
CC		= cc
CFLAGS	= -g -Wall -Wextra -Werror

SRC	= main.c input_validation.c validation_utils.c\
	  a_operations.c b_operations.c sort.c utils.c
OBJ	= $(SRC:.c=.o)

LIBFT_DIR	= Libft
LIBFT		= $(LIBFT_DIR)/libft.a
INCLUDE		= -I. -I$(LIBFT_DIR)

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(OBJ): %.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	rm -f $(OBJ)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
