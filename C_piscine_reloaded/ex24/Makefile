CC      = cc
CFLAGS  = -Wall -Wextra -Werror
NAME    = libft.a
SRCDIR  = srcs
INCDIR  = includes

SRC     = ft_putchar.c ft_putstr.c ft_strcmp.c ft_strlen.c ft_swap.c
OBJ     = $(SRC:%.c=$(SRCDIR)/%.o)

INCLUDES = -I$(INCDIR)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $@ $^

$(SRCDIR)/%.o: $(SRCDIR)/%.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
