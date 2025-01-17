# Compiler and flags
CC       = cc
CFLAGS   = -Wall -Wextra -Werror

# File names
NAME     = libft.a
SRCDIR   = srcs
INCDIR   = includes
SRC      = ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c
OBJ      = $(SRC:%.c=$(SRCDIR)/%.o)  # Create full path for object files
HEADERS  = $(INCDIR)/ft.h

# Include path
INCLUDES = -I$(INCDIR)

# Targets
all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $@ $^

$(SRCDIR)/%.o: $(SRCDIR)/%.c $(HEADERS)
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
