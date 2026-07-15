#ifndef SPAN_TPP
# define SPAN_TPP

template <typename InputIterator>
void	Span::addRange(InputIterator first, InputIterator last)
{
	typename std::iterator_traits<InputIterator>::difference_type	dist;

	dist = std::distance(first, last);
	if (dist < 0)
		throw (std::length_error("Span: invalid range."));
	if (_numbers.size() + static_cast<std::size_t>(dist) > _maxSize)
		throw (std::length_error("Span: adding this range would exceed capacity."));
	_numbers.insert(_numbers.end(), first, last);
}

#endif
