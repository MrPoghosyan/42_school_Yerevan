#ifndef BIGINT_HPP
# define BIGINT_HPP

# include <string>
# include <iostream>
# include <cstddef>

class bigint
{
	public:
		bigint();
		bigint(unsigned int n);
		bigint(const bigint& other);
		bigint& operator=(const bigint& other);
		~bigint();

		bigint operator+(const bigint& rhs) const;
		bigint& operator+=(const bigint& rhs);

		bigint& operator++();
		bigint operator++(int);

		bigint operator<<(const bigint& n) const;
		bigint operator>>(const bigint& n) const;
		bigint& operator<<=(const bigint& n);
		bigint& operator>>=(const bigint& n);

		bool operator==(const bigint& rhs) const;
		bool operator!=(const bigint& rhs) const;
		bool operator<(const bigint& rhs) const;
		bool operator<=(const bigint& rhs) const;
		bool operator>(const bigint& rhs) const;
		bool operator>=(const bigint& rhs) const;

		const std::string& getValue() const;

	private:
		std::string	_value;

		std::size_t	toSize(void) const;
};

std::ostream& operator<<(std::ostream& os, const bigint& n);

#endif
