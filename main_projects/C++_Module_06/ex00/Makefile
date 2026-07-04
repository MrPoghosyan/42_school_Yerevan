NAME		= convert

CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

SRC			= main.cpp ScalarConverter.cpp
OBJ			= $(SRC:.cpp=.o)
DEPS = ScalarConverter.hpp

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
