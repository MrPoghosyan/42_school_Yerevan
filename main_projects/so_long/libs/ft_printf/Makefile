NAME	= libftprintf.a
CC		= cc
CFLAGS	= -Wall -Wextra -Werror -I.
AR		= ar rcs

SRC		= ft_printf_utils.c ft_printf_conversions.c \
		  ft_printf_conversions_bonus.c ft_printf_flags_bonus.c ft_printf.c

OBJ		= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus: all

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
