#include "Span.hpp"

Span::Span() : _maxSize(0)
{
}

Span::Span(unsigned int n) : _maxSize(n)
{
	_numbers.reserve(n);
}

Span::Span(const Span &src) : _maxSize(src._maxSize), _numbers(src._numbers)
{
}

Span &Span::operator=(const Span &src)
{
	if (this != &src)
	{
		this->_maxSize = src._maxSize;
		this->_numbers = src._numbers;
	}
	return (*this);
}

Span::~Span()
{
}

void	Span::addNumber(int value)
{
	if (_numbers.size() >= _maxSize)
		throw (std::length_error("Span: maximum size reached."));
	_numbers.push_back(value);
}

int Span::shortestSpan() const
{
    std::vector<int> sorted;
    std::vector<int>::size_type i;
    long long minSpan;
    long long diff;

    if (_numbers.size() < 2)
        throw std::logic_error("Span: not enough numbers to find a span.");

    sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());

    minSpan = static_cast<long long>(sorted[1])
            - static_cast<long long>(sorted[0]);

    for (i = 2; i < sorted.size(); ++i)
    {
        diff = static_cast<long long>(sorted[i])
             - static_cast<long long>(sorted[i - 1]);

        if (diff < minSpan)
            minSpan = diff;
    }

    return static_cast<int>(minSpan);
}

int	Span::longestSpan() const
{
	std::vector<int>::const_iterator	maxIt;
	std::vector<int>::const_iterator	minIt;

	if (_numbers.size() < 2)
		throw (std::length_error("Span: not enough numbers to find a span."));
	maxIt = std::max_element(_numbers.begin(), _numbers.end());
	minIt = std::min_element(_numbers.begin(), _numbers.end());
	return (*maxIt - *minIt);
}
