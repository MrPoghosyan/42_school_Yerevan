NAME	= philo

SRCS	= main.c init.c utils.c actions.c monitor.c valid.c\
		  ft_atoi.c ft_strlen.c ft_strncmp.c
OBJS	= $(SRCS:.c=.o)

CC		= cc
CFLAGS	= -Wall -Wextra -Werror -pthread
DEBUG_THREAD = -g -fsanitize=thread
DEBUG_ADDRESS = -g -fsanitize=address
DEBUG_UNDEF = -g -fsanitize=undefined

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

debug_thread: CFLAGS += $(DEBUG_THREAD)
debug_thread: $(NAME)

debug_address: CFLAGS += $(DEBUG_ADDRESS)
debug_address: $(NAME)

debug_undef: CFLAGS += $(DEBUG_UNDEF)
debug_undef: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re debug_thread debug_address debug_undef
