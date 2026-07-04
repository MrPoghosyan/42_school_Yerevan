#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>

class ScalarConverter
{
	public:
		static void convert(const std::string &literal);

	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &src);
		ScalarConverter &operator=(const ScalarConverter &rhs);
		~ScalarConverter();

		enum LiteralType
		{
			CHAR,
			INT,
			FLOAT,
			DOUBLE,
			PSEUDO_FLOAT,
			PSEUDO_DOUBLE,
			UNKNOWN
		};

		static LiteralType detectType(const std::string &literal);

		static void printAsChar(double value, bool isValid);
		static void printAsInt(double value, bool isValid);
		static void printAsFloat(double value, bool isValid);
		static void printAsDouble(double value, bool isValid);
};

#endif /* SCALARCONVERTER_HPP */
