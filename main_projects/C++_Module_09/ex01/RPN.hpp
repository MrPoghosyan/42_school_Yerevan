#ifndef RPN_HPP
# define RPN_HPP

# include <string>

class RPN
{
	public:
		RPN();
		RPN(const RPN &src);
		RPN &operator=(const RPN &src);
		~RPN();

		int	evaluate(const std::string &expression) const;

	private:
		bool	isOperator(const std::string &token) const;
		bool	isNumber(const std::string &token) const;
};

#endif
