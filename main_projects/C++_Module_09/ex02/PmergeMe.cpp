#include "PmergeMe.hpp"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <stdexcept>
#include <cctype>
#include <cstdlib>
#include <cerrno>
#include <climits>
#include <ctime>

namespace
{
	std::vector<int>	jacobsthalNumbers(std::size_t count)
	{
		std::vector<int>	jacob;

		jacob.push_back(0);
		jacob.push_back(1);
		while (jacob.back() < static_cast<int>(count))
			jacob.push_back(jacob[jacob.size() - 1] + 2 * jacob[jacob.size() - 2]);
		return (jacob);
	}
}

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &src)
{
	*this = src;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &src)
{
	if (this != &src)
	{
		this->_vec = src._vec;
		this->_deq = src._deq;
	}
	return (*this);
}

PmergeMe::~PmergeMe()
{
}

bool	PmergeMe::isValidNumber(const std::string &str, long &value) const
{
	std::size_t	i;
	char		*end;

	if (str.empty())
		return (false);
	i = 0;
	if (str[0] == '+')
		i = 1;
	if (i >= str.size())
		return (false);
	while (i < str.size())
	{
		if (!std::isdigit(static_cast<unsigned char>(str[i])))
			return (false);
		i++;
	}
	errno = 0;
	value = std::strtol(str.c_str(), &end, 10);
	if (errno == ERANGE || value <= 0 || value > INT_MAX)
		return (false);
	return (true);
}

void	PmergeMe::parseArguments(int argc, char **argv)
{
	long	value;
	int		i;

	for (i = 1; i < argc; i++)
	{
		if (!isValidNumber(argv[i], value))
			throw (std::runtime_error("Error"));
		_vec.push_back(static_cast<int>(value));
	}
	_deq.assign(_vec.begin(), _vec.end());
}

void	PmergeMe::printSequence(const std::vector<int> &vec) const
{
	std::size_t	i;

	for (i = 0; i < vec.size(); i++)
	{
		if (i != 0)
			std::cout << " ";
		std::cout << vec[i];
	}
}

void	PmergeMe::mergeInsertVector(std::vector<int> &vec) const
{
	bool								hasStray;
	int									stray;
	std::vector<std::pair<int, int> >	pairs;
	std::vector<int>					largerElements;
	std::vector<std::pair<int, int> >	sortedPairs;
	std::vector<bool>					used;
	std::vector<int>					mainChain;
	std::vector<int>					pend;
	std::vector<int>					jacob;
	std::vector<std::size_t>			order;
	std::vector<bool>					inserted;
	std::size_t							prev;
	std::size_t							i;
	std::size_t							j;

	if (vec.size() <= 1)
		return ;
	hasStray = (vec.size() % 2 != 0);
	stray = 0;
	if (hasStray)
	{
		stray = vec.back();
		vec.pop_back();
	}
	for (i = 0; i < vec.size(); i += 2)
	{
		if (vec[i] > vec[i + 1])
			pairs.push_back(std::make_pair(vec[i], vec[i + 1]));
		else
			pairs.push_back(std::make_pair(vec[i + 1], vec[i]));
	}
	for (i = 0; i < pairs.size(); i++)
		largerElements.push_back(pairs[i].first);
	mergeInsertVector(largerElements);
	used.assign(pairs.size(), false);
	for (i = 0; i < largerElements.size(); i++)
	{
		for (j = 0; j < pairs.size(); j++)
		{
			if (!used[j] && pairs[j].first == largerElements[i])
			{
				sortedPairs.push_back(pairs[j]);
				used[j] = true;
				break ;
			}
		}
	}
	mainChain = largerElements;
	mainChain.insert(mainChain.begin(), sortedPairs[0].second);
	for (i = 1; i < sortedPairs.size(); i++)
		pend.push_back(sortedPairs[i].second);
	inserted.assign(pend.size(), false);
	jacob = jacobsthalNumbers(pend.size());
	prev = 0;
	for (i = 2; i < jacob.size(); i++)
	{
		std::size_t	limit;
		std::size_t	idx;

		limit = static_cast<std::size_t>(jacob[i]);
		if (limit > pend.size())
			limit = pend.size();
		idx = limit;
		while (idx > prev)
		{
			if (!inserted[idx - 1])
			{
				order.push_back(idx - 1);
				inserted[idx - 1] = true;
			}
			idx--;
		}
		prev = limit;
		if (limit >= pend.size())
			break ;
	}
	for (i = 0; i < pend.size(); i++)
	{
		if (!inserted[i])
			order.push_back(i);
	}
	for (i = 0; i < order.size(); i++)
	{
		int							value;
		std::vector<int>::iterator	it;

		value = pend[order[i]];
		it = std::lower_bound(mainChain.begin(), mainChain.end(), value);
		mainChain.insert(it, value);
	}
	if (hasStray)
	{
		std::vector<int>::iterator	it;

		it = std::lower_bound(mainChain.begin(), mainChain.end(), stray);
		mainChain.insert(it, stray);
	}
	vec = mainChain;
}

void	PmergeMe::mergeInsertDeque(std::deque<int> &deq) const
{
	bool								hasStray;
	int									stray;
	std::vector<std::pair<int, int> >	pairs;
	std::deque<int>						largerElements;
	std::vector<std::pair<int, int> >	sortedPairs;
	std::vector<bool>					used;
	std::deque<int>						mainChain;
	std::deque<int>						pend;
	std::vector<int>					jacob;
	std::vector<std::size_t>			order;
	std::vector<bool>					inserted;
	std::size_t							prev;
	std::size_t							i;
	std::size_t							j;

	if (deq.size() <= 1)
		return ;
	hasStray = (deq.size() % 2 != 0);
	stray = 0;
	if (hasStray)
	{
		stray = deq.back();
		deq.pop_back();
	}
	for (i = 0; i < deq.size(); i += 2)
	{
		if (deq[i] > deq[i + 1])
			pairs.push_back(std::make_pair(deq[i], deq[i + 1]));
		else
			pairs.push_back(std::make_pair(deq[i + 1], deq[i]));
	}
	for (i = 0; i < pairs.size(); i++)
		largerElements.push_back(pairs[i].first);
	mergeInsertDeque(largerElements);
	used.assign(pairs.size(), false);
	for (i = 0; i < largerElements.size(); i++)
	{
		for (j = 0; j < pairs.size(); j++)
		{
			if (!used[j] && pairs[j].first == largerElements[i])
			{
				sortedPairs.push_back(pairs[j]);
				used[j] = true;
				break ;
			}
		}
	}
	mainChain = largerElements;
	mainChain.insert(mainChain.begin(), sortedPairs[0].second);
	for (i = 1; i < sortedPairs.size(); i++)
		pend.push_back(sortedPairs[i].second);
	inserted.assign(pend.size(), false);
	jacob = jacobsthalNumbers(pend.size());
	prev = 0;
	for (i = 2; i < jacob.size(); i++)
	{
		std::size_t	limit;
		std::size_t	idx;

		limit = static_cast<std::size_t>(jacob[i]);
		if (limit > pend.size())
			limit = pend.size();
		idx = limit;
		while (idx > prev)
		{
			if (!inserted[idx - 1])
			{
				order.push_back(idx - 1);
				inserted[idx - 1] = true;
			}
			idx--;
		}
		prev = limit;
		if (limit >= pend.size())
			break ;
	}
	for (i = 0; i < pend.size(); i++)
	{
		if (!inserted[i])
			order.push_back(i);
	}
	for (i = 0; i < order.size(); i++)
	{
		int							value;
		std::deque<int>::iterator	it;

		value = pend[order[i]];
		it = std::lower_bound(mainChain.begin(), mainChain.end(), value);
		mainChain.insert(it, value);
	}
	if (hasStray)
	{
		std::deque<int>::iterator	it;

		it = std::lower_bound(mainChain.begin(), mainChain.end(), stray);
		mainChain.insert(it, stray);
	}
	deq = mainChain;
}

void	PmergeMe::run(int argc, char **argv)
{
	std::vector<int>	vecCopy;
	std::deque<int>		deqCopy;
	std::clock_t		vecStart;
	std::clock_t		vecEnd;
	std::clock_t		deqStart;
	std::clock_t		deqEnd;
	double				vecTime;
	double				deqTime;

	parseArguments(argc, argv);
	std::cout << "Before: ";
	printSequence(_vec);
	std::cout << std::endl;
	vecCopy = _vec;
	deqCopy = _deq;
	vecStart = std::clock();
	mergeInsertVector(vecCopy);
	vecEnd = std::clock();
	deqStart = std::clock();
	mergeInsertDeque(deqCopy);
	deqEnd = std::clock();
	std::cout << "After: ";
	printSequence(vecCopy);
	std::cout << std::endl;
	vecTime = static_cast<double>(vecEnd - vecStart) / CLOCKS_PER_SEC * 1000000.0;
	deqTime = static_cast<double>(deqEnd - deqStart) / CLOCKS_PER_SEC * 1000000.0;
	std::cout << "Time to process a range of " << _vec.size()
		<< " elements with std::vector<int> : " << vecTime << " us" << std::endl;
	std::cout << "Time to process a range of " << _deq.size()
		<< " elements with std::deque<int> : " << deqTime << " us" << std::endl;
}
