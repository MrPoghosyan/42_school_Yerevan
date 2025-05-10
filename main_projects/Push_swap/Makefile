NAME	= push_swap
CC		= cc
CFLAGS	= -g -Wall -Wextra -Werror

SRC		= main.c input_validation.c validation_utils.c\
		  operations.c sort.c utils.c
B_SRC	= checker.c checker_utils.c input_validation.c validation_utils.c\
		  a_operations.c b_operations.c a_b_operations.c operations.c\
		  utils.c sort.c

OBJ		= $(SRC:.c=.o)
B_OBJ	= $(B_SRC:.c=.o)

LIBFT_DIR	= Libft
LIBFT		= $(LIBFT_DIR)/libft.a
INCLUDE		= -I. -I$(LIBFT_DIR)

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

bonus: $(LIBFT) $(B_OBJ)
	$(CC) $(CFLAGS) $(INCLUDE) $(B_OBJ) $(LIBFT) -o checker

$(OBJ): %.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	rm -f $(OBJ) $(B_OBJ)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -f $(NAME) checker

re: fclean all

.PHONY: all clean fclean re bonus
