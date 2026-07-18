#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cctype>
#include <stdexcept>

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
{
	*this = src;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src)
{
	if (this != &src)
		this->_database = src._database;
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}

std::string	BitcoinExchange::trim(const std::string &str) const
{
	std::size_t	start;
	std::size_t	end;

	start = str.find_first_not_of(" \t");
	if (start == std::string::npos)
		return ("");
	end = str.find_last_not_of(" \t");
	return (str.substr(start, end - start + 1));
}

bool	BitcoinExchange::isLeapYear(int year) const
{
	if (year % 4 != 0)
		return (false);
	if (year % 100 == 0 && year % 400 != 0)
		return (false);
	return (true);
}

int	BitcoinExchange::daysInMonth(int month, int year) const
{
	static const int	days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (month == 2 && isLeapYear(year))
		return (29);
	return (days[month - 1]);
}

bool	BitcoinExchange::isValidDate(const std::string &date) const
{
	std::size_t	i;
	int			year;
	int			month;
	int			day;

	if (date.size() != 10)
		return (false);
	if (date[4] != '-' || date[7] != '-')
		return (false);
	for (i = 0; i < date.size(); i++)
	{
		if (i == 4 || i == 7)
			continue ;
		if (!std::isdigit(static_cast<unsigned char>(date[i])))
			return (false);
	}
	year = std::atoi(date.substr(0, 4).c_str());
	month = std::atoi(date.substr(5, 2).c_str());
	day = std::atoi(date.substr(8, 2).c_str());
	if (month < 1 || month > 12)
		return (false);
	if (day < 1 || day > daysInMonth(month, year))
		return (false);
	return (true);
}

bool	BitcoinExchange::isValidValue(const std::string &value, double &result) const
{
	std::size_t	i;
	std::size_t	j;
	bool		dotSeen;

	if (value.empty())
		return (false);
	i = 0;
	if (value[0] == '-' || value[0] == '+')
		i = 1;
	if (i >= value.size())
		return (false);
	dotSeen = false;
	for (j = i; j < value.size(); j++)
	{
		if (value[j] == '.')
		{
			if (dotSeen)
				return (false);
			dotSeen = true;
		}
		else if (!std::isdigit(static_cast<unsigned char>(value[j])))
			return (false);
	}
	result = std::atof(value.c_str());
	return (true);
}

double	BitcoinExchange::getRate(const std::string &date) const
{
	std::map<std::string, double>::const_iterator	it;

	it = _database.lower_bound(date);
	if (it == _database.end())
	{
		--it;
		return (it->second);
	}
	if (it->first != date && it != _database.begin())
		--it;
	return (it->second);
}

void	BitcoinExchange::loadDatabase(const std::string &filename)
{
	std::ifstream	file(filename.c_str());
	std::string		line;
	std::size_t		pos;
	std::string		date;
	std::string		rate;

	if (!file.is_open())
		throw (std::runtime_error("Error: could not open database."));
	std::getline(file, line);
	while (std::getline(file, line))
	{
		pos = line.find(',');
		if (pos == std::string::npos)
			continue ;
		date = line.substr(0, pos);
		rate = line.substr(pos + 1);
		_database[date] = std::atof(rate.c_str());
	}
}

void	BitcoinExchange::processInput(const std::string &filename) const
{
	std::ifstream	file(filename.c_str());
	std::string		line;
	std::size_t		pos;
	std::string		date;
	std::string		value;
	double			amount;
	double			rate;

	if (!file.is_open())
		throw (std::runtime_error("Error: could not open file."));
	std::getline(file, line);
	while (std::getline(file, line))
	{
		if (line.empty())
			continue ;
		pos = line.find('|');
		if (pos == std::string::npos)
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue ;
		}
		date = trim(line.substr(0, pos));
		value = trim(line.substr(pos + 1));
		if (!isValidDate(date))
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue ;
		}
		if (!isValidValue(value, amount))
		{
			std::cout << "Error: bad input => " << line << std::endl;
			continue ;
		}
		if (amount < 0)
		{
			std::cout << "Error: not a positive number." << std::endl;
			continue ;
		}
		if (amount > 1000)
		{
			std::cout << "Error: too large a number." << std::endl;
			continue ;
		}
		rate = getRate(date);
		std::cout << date << " => " << value << " = " << amount * rate << std::endl;
	}
}
