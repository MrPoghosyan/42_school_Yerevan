#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

int print_d(int num)
{
	int size = 0;

	if (num == -2147483648)
		return (write(1, "-2147483648", 11));
	if (num < 0)
	{
		size += write(1, "-", 1);
		num = -num;
	}
	if (num > 9)
	{
		size += print_d(num / 10);
	}
	char c = "0123456789"[num % 10];
	size += write(1, &c, 1);

	return size;
}

int print_s(char *s)
{
	int len = 0;

	if (!s)
		return (write(1, "(null)", 6));
	while (s[len]) len++;
	return (write(1, s, len));
}

int print_x(unsigned int n)
{
	int size = 0;

	if (n >= 16)
		size += print_x(n / 16);
	char c = "0123456789abcdef"[n % 16];
	size += write(1, &c, 1);
	return size;
}

int ft_printf(const char *form, ...)
{
	int size = 0;
    va_list ap;
	va_start(ap, form);

	if (!form)
		return (va_end(ap), -1);
	while (*form != '\0')
	{
		if (*form == '%')
		{
			form++;
			if (*form == 'd')
				size += print_d(va_arg(ap, int));
			else if (*form == 's')
				size += print_s(va_arg(ap, char *));
			else if (*form == 'x')
				size += print_x(va_arg(ap, unsigned int));
		}
		else
			size += write(1, form, 1);
		form++;
	}

	va_end(ap);
	return size;
}
