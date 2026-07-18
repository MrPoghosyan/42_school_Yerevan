#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <string>
# include <vector>
# include <deque>
# include <utility>

class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &src);
		PmergeMe &operator=(const PmergeMe &src);
		~PmergeMe();

		void	run(int argc, char **argv);

	private:
		std::vector<int>	_vec;
		std::deque<int>		_deq;

		bool	isValidNumber(const std::string &str, long &value) const;
		void	parseArguments(int argc, char **argv);
		void	printSequence(const std::vector<int> &vec) const;

		void	mergeInsertVector(std::vector<int> &vec) const;
		void	mergeInsertDeque(std::deque<int> &deq) const;
};

#endif
