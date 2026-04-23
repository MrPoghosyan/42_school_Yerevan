NAME	= a.out

CPPC		= clang++
CPPFLAGS	= -Wall -W -Werror -g #-std=c++98

SRC	= main.cpp AMateria.cpp Cure.cpp Ice.cpp \
	  Character.cpp MateriaSource.cpp
OBJ	= $(SRC:.cpp=.o)

# Targets
all: $(NAME)

$(NAME): $(OBJ)
	$(CPPC) $(CPPFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CPPC) $(CPPFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
