// str_capitalizer.c

#include <unistd.h>

// Ֆունկցիա՝ տպելու մեկ սիմվոլ
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

// Ֆունկցիա՝ փոքրատառ դարձնելու սիմվոլը, եթե մեծատառ է
char	to_lower(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

// Ֆունկցիա՝ մեծատառ դարձնելու սիմվոլը, եթե փոքրատառ է
char	to_upper(char c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

// Ֆունկցիա՝ մշակելու և տպելու տեքստը
void	str_capitalize(char *str)
{
	while (*str)
	{
		// Եթե տառ է
		if ((*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z'))
		{
			// Եթե բացատ կամ tab է, ապա հաջորդ տառը նոր բառի սկիզբ է
			if (*(str +1) == ' ' || *(str +1) == '\t' || *(str +1) == '\0') // Եթե բառի սկիզբ է, դարձնում ենք մեծատառ
				ft_putchar(to_upper(*str));
			else // Հակառակ դեպքում դարձնում ենք փոքրատառ
				ft_putchar(to_lower(*str));
		}
		else
		{
			ft_putchar(*str); // Տպում ենք այն, ինչ կա (բացատ, թիվ, սիմվոլ)
		}
		str++;
	}
}

int	main(int argc, char **argv)
{
	int i = 1;

	if (argc > 1)
	{
		while (i < argc)
		{
			str_capitalize(argv[i]);
			ft_putchar('\n');
			i++;
		}
	}
	else
		ft_putchar('\n');
	return (0);
}
