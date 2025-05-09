int	ft_atoi_base(const char *str, int str_base)
{
	int	result = 0;
	int	sign = 1;
	int	value;

	if (*str == '-' || *str == '+') // Ստուգում ենք բացասական նշանը
	{
		if (*str == '-')
			sign = -1;
		str++;
	}

	while (*str) // Մինչև տողը վերջանա
	{
		if (*str >= '0' && *str <= '9') // Եթե թիվ է
			value = *str - '0';
		else if (*str >= 'a' && *str <= 'f') // Եթե փոքրատառ հեքս թվանշան է
			value = *str - 'a' + 10;
		else if (*str >= 'A' && *str <= 'F') // Եթե մեծատառ հեքս թվանշան է
			value = *str - 'A' + 10;
		else
			break; // Այլ սիմվոլ՝ կանգնեցնել
		
		if (value >= str_base) // Եթե սիմվոլը չի տեղավորվում բազայում
			break;
		
		result = result * str_base + value; // Թարմացնում ենք արդյունքը
		str++;
	}
	return (result * sign); // Հաշվի առնելով նշանը
}

#include <stdio.h>

int main(void)
{
	printf("%d\n", ft_atoi_base("1010", 2));        // 10
	printf("%d\n", ft_atoi_base("-1A", 16));		// -26
	printf("%d\n", ft_atoi_base("+FF", 16));         // 255
	printf("%d\n", ft_atoi_base("77", 8));          // 63
	printf("%d\n", ft_atoi_base("123", 10));        // 123
	printf("%d\n", ft_atoi_base("12FDB3", 16));     // 1246899
	return (0);
}
