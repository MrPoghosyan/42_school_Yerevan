# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: labroyan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/10 20:49:21 by labroyan          #+#    #+#              #
#    Updated: 2025/02/10 21:35:23 by labroyan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME		= libft.a

SRCS		= ft_isalnum.c ft_isprint.c ft_memcmp.c ft_putchar_fd.c ft_split.c\
		  	ft_strlcat.c ft_strncmp.c ft_substr.c ft_atoi.c ft_isalpha.c\
		  	ft_itoa.c ft_memcpy.c ft_putendl_fd.c ft_strchr.c ft_strlcpy.c\
		  	ft_strnstr.c ft_tolower.c ft_bzero.c ft_isascii.c ft_memmove.c\
		  	ft_putnbr_fd.c ft_strdup.c ft_strlen.c ft_strrchr.c ft_toupper.c\
		  	ft_calloc.c ft_isdigit.c ft_memchr.c ft_memset.c ft_putstr_fd.c\
		  	ft_strjoin.c ft_strmapi.c ft_strtrim.c ft_striteri.c

OBJ		= $(SRCS:.c=.o)

CC		= cc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror

all:		$(NAME)

$(NAME):	$(OBJ)
			ar rcs $(NAME) $(OBJ)

%.o: %.c libft.h Makefile
			$(CC) $(CFLAGS) -c $< -o $@

clean:
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re

