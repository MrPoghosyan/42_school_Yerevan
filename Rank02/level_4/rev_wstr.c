#include <unistd.h>

// Ստուգում ենք, արդյոք տրված սիմվոլը բացատ է, թե ոչ
int is_separator(char c)
{
	return (c == ' ' || c == '\t');
}

int main(int argc, char **argv)
{
	// Եթե չի տրվել ճիշտ քանակի պարամետր (միայն մեկ տող), տպում ենք նոր տող և դուրս գալիս
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}

	char *str = argv[1]; // Մեր ստացած տեքստային տողը
	int i = 0;
	int end;

	// Հաշվում ենք տողի երկարությունը
	while (str[i]) i++;
	end = i;

	i = end - 1; // Սկսում ենք վերջից

	int first = 1; // Դրոշ՝ հասկանալու համար՝ արդյոք առաջին բառն ենք տպում

	while (i >= 0)
	{
		// Բաց ենք թողնում վերջում եղած բացատները
		while (i >= 0 && is_separator(str[i]))
			i--;

		if (i < 0)
			break;

		// Գտնում ենք բառի վերջը
		int word_end = i;

		// Գտնում ենք բառի սկիզբը՝ քայլելով հակառակ ուղղությամբ
		while (i >= 0 && !is_separator(str[i]))
			i--;

		int word_start = i + 1;

		// Եթե սա առաջին բառը չէ, ապա տպում ենք բացատ
		if (!first)
			write(1, " ", 1);

		// Տպում ենք բառը
		write(1, &str[word_start], word_end - word_start + 1);

		first = 0; // Հաջորդ բառը արդեն երկրորդն է
	}

	// Վերջում տպում ենք նոր տող
	write(1, "\n", 1);

	return (0);
}
