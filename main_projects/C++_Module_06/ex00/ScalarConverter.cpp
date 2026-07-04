#include "ScalarConverter.hpp"
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cctype>
#include <climits>
#include <cfloat>
#include <cmath>
#include <iomanip>
#include <limits>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &src)
{
	(void)src;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &rhs)
{
	(void)rhs;
	return *this;
}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::LiteralType ScalarConverter::detectType(const std::string &literal)
{
	// Check for empty string
	if (literal.empty())
		return (UNKNOWN);

	// Check for pseudo-literals first
	if (literal == "nan" || literal == "+inf" || literal == "-inf" || literal == "inf")
		return (PSEUDO_DOUBLE);
	if (literal == "nanf" || literal == "+inff" || literal == "-inff" || literal == "inff")
		return (PSEUDO_FLOAT);

	// Check for char literal: 'c'
	if (literal.size() == 3 && literal[0] == '\'' && literal[2] == '\'')
		return (CHAR);

	// Check for single character (not digit)
	if (literal.size() == 1 && !std::isdigit(static_cast<unsigned char>(literal[0])))
		return (CHAR);

	// Check for float (ends with 'f')
	if (!literal.empty() && literal[literal.size() - 1] == 'f')
	{
		std::string numberPart = literal.substr(0, literal.size() - 1);
		if (!numberPart.empty())
		{
			char *end = 0;
			std::strtod(numberPart.c_str(), &end);
			if (end && *end == '\0')
				return (FLOAT);
		}
	}

	// Check for double (contains '.')
	if (literal.find('.') != std::string::npos)
	{
		char *end = 0;
		std::strtod(literal.c_str(), &end);
		if (end && *end == '\0')
			return (DOUBLE);
	}

	// Check for int
	if (!literal.empty())
	{
		char *end = 0;
		std::strtol(literal.c_str(), &end, 10);
		if (end && *end == '\0')
		{
			// Check that all characters are digits (or +/-)
			size_t i = 0;
			if (literal[0] == '+' || literal[0] == '-')
				i++;
			bool allDigits = true;
			for (; i < literal.size(); i++)
			{
				if (!std::isdigit(static_cast<unsigned char>(literal[i])))
				{
					allDigits = false;
					break;
				}
			}
			if (allDigits)
				return (INT);
		}
	}

	// If no type matches, return UNKNOWN
	return (UNKNOWN);
}

static bool parseAsDouble(const std::string &literal, double &out)
{
	if (literal.empty())
		return (false);

	std::string numberPart = literal;
	if (!numberPart.empty() && numberPart[numberPart.size() - 1] == 'f')
		numberPart.erase(numberPart.size() - 1);

	// Check for char literal with quotes
	if (literal.size() == 3 && literal[0] == '\'' && literal[2] == '\'')
	{
		out = static_cast<double>(literal[1]);
		return (true);
	}

	// Check for single character - but ONLY if original size is 1
	if (literal.size() == 1 && !std::isdigit(static_cast<unsigned char>(literal[0])))
	{
		out = static_cast<double>(literal[0]);
		return (true);
	}

	char *end = 0;
	double value = std::strtod(numberPart.c_str(), &end);
	if (numberPart.empty() || end == 0 || *end != '\0')
		return (false);
	out = value;
	return (true);
}

void ScalarConverter::printAsChar(double value, bool isValid)
{
	std::cout << "char: ";
	if (!isValid || std::isnan(value) || std::isinf(value)
		|| value < static_cast<double>(CHAR_MIN) || value > static_cast<double>(CHAR_MAX))
	{
		std::cout << "impossible" << std::endl;
		return ;
	}
	char c = static_cast<char>(value);
	if (std::isprint(static_cast<unsigned char>(c)))
		std::cout << "'" << c << "'" << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
}

void ScalarConverter::printAsInt(double value, bool isValid)
{
	std::cout << "int: ";
	if (!isValid || std::isnan(value) || std::isinf(value)
		|| value < static_cast<double>(INT_MIN) || value > static_cast<double>(INT_MAX))
	{
		std::cout << "impossible" << std::endl;
		return ;
	}
	std::cout << static_cast<int>(value) << std::endl;
}

void ScalarConverter::printAsFloat(double value, bool isValid)
{
	std::cout << "float: ";
	if (!isValid)
	{
		std::cout << "impossible" << std::endl;
		return ;
	}
	if (std::isnan(value))
	{
		std::cout << "nanf" << std::endl;
		return ;
	}
	if (std::isinf(value))
	{
		std::cout << (value > 0 ? "+inff" : "-inff") << std::endl;
		return ;
	}
	// Check if value can be represented as float
	if (value > static_cast<double>(std::numeric_limits<float>::max()) ||
		value < -static_cast<double>(std::numeric_limits<float>::max()))
	{
		std::cout << "impossible" << std::endl;
		return ;
	}
	std::ostringstream oss;
	oss << std::fixed << std::setprecision(1) << static_cast<float>(value);
	std::cout << oss.str() << "f" << std::endl;
}

void ScalarConverter::printAsDouble(double value, bool isValid)
{
	std::cout << "double: ";
	if (!isValid)
	{
		std::cout << "impossible" << std::endl;
		return ;
	}
	if (std::isnan(value))
	{
		std::cout << "nan" << std::endl;
		return ;
	}
	if (std::isinf(value))
	{
		std::cout << (value > 0 ? "+inf" : "-inf") << std::endl;
		return ;
	}
	std::ostringstream oss;
	oss << std::fixed << std::setprecision(1) << value;
	std::cout << oss.str() << std::endl;
}

void ScalarConverter::convert(const std::string &literal)
{
	LiteralType type = detectType(literal);
	double value = 0.0;
	bool isValid = true;

	// If type is UNKNOWN, print impossible for all
	if (type == UNKNOWN)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return ;
	}

	switch (type)
	{
		case CHAR:
			if (literal.size() == 3 && literal[0] == '\'' && literal[2] == '\'')
				value = static_cast<double>(literal[1]);
			else
				value = static_cast<double>(literal[0]);
			break ;
		case PSEUDO_DOUBLE:
		case PSEUDO_FLOAT:
		{
			std::string clean = literal;
			if (!clean.empty() && clean[clean.size() - 1] == 'f')
				clean.erase(clean.size() - 1);
			if (clean == "nan")
				value = std::numeric_limits<double>::quiet_NaN();
			else if (clean == "+inf" || clean == "inf")
				value = std::numeric_limits<double>::infinity();
			else if (clean == "-inf")
				value = -std::numeric_limits<double>::infinity();
			break ;
		}
		case INT:
		case FLOAT:
		case DOUBLE:
			isValid = parseAsDouble(literal, value);
			break ;
		default:
			isValid = false;
			break ;
	}

	printAsChar(value, isValid);
	printAsInt(value, isValid);
	printAsFloat(value, isValid);
	printAsDouble(value, isValid);
}
