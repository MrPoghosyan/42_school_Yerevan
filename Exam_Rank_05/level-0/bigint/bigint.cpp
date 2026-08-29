#include "bigint.hpp"
#include <sstream>
#include <algorithm>

bigint::bigint() : _value("0")
{
}

/*
bigint::bigint(unsigned int n)
{
	if (n == 0)
		this->_value = "0";
	else
	{
		this->_value = "";
		while (n > 0)
		{
			this->_value = std::string(1, static_cast<char>('0' + (n % 10))) + this->_value;
			n /= 10;
		}
	}
}
*/
bigint::bigint(unsigned int n)
{
	std::stringstream ss;
	ss << n;
	this->_value = ss.str();
}


bigint::bigint(const bigint& other) : _value(other._value)
{
}

bigint& bigint::operator=(const bigint& other)
{
	if (this != &other)
		this->_value = other._value;
	return *this;
}

bigint::~bigint()
{
}

/*
bigint bigint::operator+(const bigint& rhs) const
{
	bigint	result;
	std::string	sum;
	int	i = static_cast<int>(this->_value.size()) - 1;
	int	j = static_cast<int>(rhs._value.size()) - 1;
	int	carry = 0;

	while (i >= 0 || j >= 0 || carry)
	{
		int digitA = (i >= 0) ? (this->_value[i] - '0') : 0;
		int digitB = (j >= 0) ? (rhs._value[j] - '0') : 0;
		int total = digitA + digitB + carry;

		carry = total / 10;
		sum = static_cast<char>('0' + (total % 10)) + sum;
		--i;
		--j;
	}
	result._value = sum;
	return result;
}
*/
bigint bigint::operator+(const bigint& rhs) const
{
	bigint result;
	std::string sum;
	int total;

	int i = static_cast<int>(_value.size()) - 1;
	int j = static_cast<int>(rhs._value.size()) - 1;
	int carry = 0;

	while (i >= 0 || j >= 0 || carry){
		total = carry;
		total = total + ((i >= 0) ? _value[i--] - '0' : 0);
		total = total + ((j >= 0) ? rhs._value[j--] - '0' : 0);

		carry = total / 10;
		sum.push_back(static_cast<char>('0' + total % 10));
	}

	std::reverse(sum.begin(), sum.end());
	result._value = sum;
	return result;
}

bigint& bigint::operator+=(const bigint& rhs)
{
	*this = *this + rhs;
	return *this;
}

bigint& bigint::operator++()
{
	*this = *this + bigint(1);
	return *this;
}

bigint bigint::operator++(int)
{
	bigint tmp(*this);

	++(*this);
	return tmp;
}

bigint bigint::operator<<(const bigint& n) const
{
	bigint	result(*this);
	std::size_t	shift = n.toSize();

	if (result._value != "0")
		result._value.append(shift, '0');
	return result;
}

bigint bigint::operator>>(const bigint& n) const
{
	bigint	result(*this);
	std::size_t	shift = n.toSize();

	if (shift >= result._value.size())
		result._value = "0";
	else
		result._value.erase(result._value.size() - shift);
	return result;
}

bigint& bigint::operator<<=(const bigint& n)
{
	*this = *this << n;
	return *this;
}

bigint& bigint::operator>>=(const bigint& n)
{
	*this = *this >> n;
	return *this;
}

bool bigint::operator==(const bigint& rhs) const
{
	return this->_value == rhs._value;
}

bool bigint::operator!=(const bigint& rhs) const
{
	return !(*this == rhs);
}

bool bigint::operator<(const bigint& rhs) const
{
	if (this->_value.size() != rhs._value.size())
		return this->_value.size() < rhs._value.size();
	return this->_value < rhs._value;
}

bool bigint::operator<=(const bigint& rhs) const
{
	return (*this < rhs || *this == rhs);
}

bool bigint::operator>(const bigint& rhs) const
{
	return !(*this <= rhs);
}

bool bigint::operator>=(const bigint& rhs) const
{
	return !(*this < rhs);
}

const std::string& bigint::getValue() const
{
	return this->_value;
}

std::size_t bigint::toSize(void) const
{
	std::size_t	result = 0;

	for (std::size_t i = 0; i < this->_value.size(); ++i)
		result = result * 10 + static_cast<std::size_t>(this->_value[i] - '0');
	return result;
}

std::ostream& operator<<(std::ostream& os, const bigint& n)
{
	os << n.getValue();
	return os;
}
