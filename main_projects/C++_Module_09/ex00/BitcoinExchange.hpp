#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <string>

class BitcoinExchange
{
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &src);
		BitcoinExchange &operator=(const BitcoinExchange &src);
		~BitcoinExchange();

		void	loadDatabase(const std::string &filename);
		void	processInput(const std::string &filename) const;

	private:
		std::map<std::string, double>	_database;

		std::string	trim(const std::string &str) const;
		bool		isLeapYear(int year) const;
		int			daysInMonth(int month, int year) const;
		bool		isValidDate(const std::string &date) const;
		bool		isValidValue(const std::string &value, double &result) const;
		double		getRate(const std::string &date) const;
};

#endif
