#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <cstddef>
# include <iterator>
# include <algorithm>
# include <stdexcept>

class Span
{
	public:
		Span(unsigned int n);
		Span(const Span &src);
		Span &operator=(const Span &src);
		~Span();

		void	addNumber(int value);

		template <typename InputIterator>
		void	addRange(InputIterator first, InputIterator last);

		int	shortestSpan() const;
		int	longestSpan() const;

	private:
		Span();

		unsigned int		_maxSize;
		std::vector<int>	_numbers;
};

# include "Span.tpp"

#endif
