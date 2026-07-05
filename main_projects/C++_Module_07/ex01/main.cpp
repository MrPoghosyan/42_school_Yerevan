#include <iostream>
#include <string>
#include "iter.hpp"

template <typename T>
void	print(T const &elem)
{
	std::cout << elem << " ";
}

template <typename T>
void	increment(T &elem)
{
	elem = elem + 1;
}

static void	test_ints(void)
{
	int	tab[5];
	int	i;

	i = 0;
	while (i < 5)
	{
		tab[i] = i;
		i++;
	}
	std::cout << "Before increment: ";
	::iter(tab, static_cast<std::size_t>(5), print<int>);
	std::cout << std::endl;
	::iter(tab, static_cast<std::size_t>(5), increment<int>);
	std::cout << "After increment: ";
	::iter(tab, static_cast<std::size_t>(5), print<int>);
	std::cout << std::endl;
}

static void	test_strings(void)
{
	std::string	words[3];

	words[0] = "one";
	words[1] = "two";
	words[2] = "tree";
	std::cout << "Words: ";
	::iter(words, static_cast<std::size_t>(3), print<std::string>);
	std::cout << std::endl;
}

int	main(void)
{
	test_ints();
	test_strings();
	return (0);
}
