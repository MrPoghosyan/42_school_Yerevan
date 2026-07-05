#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <exception>
# include <cstdlib>
# include <ctime>

template <typename T>
class Array
{
	public:
		Array(void);
		Array(unsigned int n);
		Array(Array const &src);
		~Array(void);

		Array			&operator=(Array const &rhs);
		T				&operator[](unsigned int index);
		T const			&operator[](unsigned int index) const;
		unsigned int	size(void) const;

		class OutOfBoundsException : public std::exception
		{
			public:
				virtual const char	*what(void) const throw();
		};

	private:
		T				*_data;
		unsigned int	_size;
};

# include "Array.tpp"

#endif
