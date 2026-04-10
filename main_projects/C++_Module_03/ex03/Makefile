NAME	= DiamondTrap

CPPC		= c++
CPPFLAGS	= -Wall -Wextra -Werror -std=c++98# -Wno-shadow -Wshadow

SRC	= main.cpp DiamondTrap.cpp ScavTrap.cpp FragTrap.cpp ClapTrap.cpp
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
