#include "RPN.hpp"
#include <stack>
#include <sstream>
#include <stdexcept>
#include <cctype>

RPN::RPN()
{
}

RPN::RPN(const RPN &src)
{
	(void)src;
}

RPN &RPN::operator=(const RPN &src)
{
	(void)src;
	return (*this);
}

RPN::~RPN()
{
}

bool	RPN::isOperator(const std::string &token) const
{
	return (token == "+" || token == "-" || token == "*" || token == "/");
}

bool	RPN::isNumber(const std::string &token) const
{
	if (token.size() != 1)
		return (false);
	return (std::isdigit(static_cast<unsigned char>(token[0])) != 0);
}

int	RPN::evaluate(const std::string &expression) const
{
	std::stack<int>		numbers;
	std::istringstream	iss(expression);
	std::string			token;
	int					left;
	int					right;
	int					result;

	while (iss >> token)
	{
		if (isNumber(token))
			numbers.push(token[0] - '0');
		else if (isOperator(token))
		{
			if (numbers.size() < 2)
				throw (std::runtime_error("Error"));
			right = numbers.top();
			numbers.pop();
			left = numbers.top();
			numbers.pop();
			if (token == "+")
				result = left + right;
			else if (token == "-")
				result = left - right;
			else if (token == "*")
				result = left * right;
			else
			{
				if (right == 0)
					throw (std::runtime_error("Error"));
				result = left / right;
			}
			numbers.push(result);
		}
		else
			throw (std::runtime_error("Error"));
	}
	if (numbers.size() != 1)
		throw (std::runtime_error("Error"));
	return (numbers.top());
}
