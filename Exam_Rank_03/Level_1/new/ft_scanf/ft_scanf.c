#include <stdarg.h>
#include <stdio.h>
#include <ctype.h>

int match_space(FILE *f)
{
	int c;

	do {
		c = fgetc(f);
	} while (isspace(c));
	if (c != EOF)
		ungetc(c, f);
	return 0;
}

int match_char(FILE *f, char c)
{
	int input = fgetc(f);

	if (input == c)
		return 1;
	if (input != EOF)
		ungetc(input, f);
	return 0;
}

int scan_char(FILE *f, va_list ap)
{
	int c = fgetc(f);

	if (c == EOF)
		return -1;
	char *out = va_arg(ap, char *);
	*out = c;
	return 1;
}

int scan_int(FILE *f, va_list ap)
{
	int c;
	int sign = 1;
	int result = 0;
	int found = 0;

	c = fgetc(f);
	while (isspace(c))
		c = fgetc(f);
	if (c == '-')
	{
		sign = -1;
		c = fgetc(f);
	}
	while (isdigit(c))
	{
		found = 1;
		result = result * 10 + (c - '0');
		c = fgetc(f);
	}
	if (c != EOF)
		ungetc(c, f);
	if (!found)
		return 0;
	int *out = va_arg(ap, int *);
	*out = result * sign;
	return 1;
}

int scan_string(FILE *f, va_list ap)
{
	char *str = va_arg(ap, char *);
	int c = fgetc(f);

	while(isspace(c))
		c = fgetc(f);
	int i = 0;
	while (c != EOF && !isspace(c))
	{
		str[i++] = c;
		c = fgetc(f);
	}
	if (c != EOF)
		ungetc(c, f);
	str[i] = '\0';
	return (i > 0) ? 1 : 0;
}

int	match_conv(FILE *f, const char **format, va_list ap)
{
	switch (**format)
	{
		case 'c':
			return scan_char(f, ap);
		case 'd':
			match_space(f);
			return scan_int(f, ap);
		case 's':
			match_space(f);
			return scan_string(f, ap);
		case EOF:
			return -1;
		default:
			return -1;
	}
}

int ft_vfscanf(FILE *f, const char *format, va_list ap)
{
	int nconv = 0;

	int c = fgetc(f);
	if (c == EOF)
		return EOF;
	ungetc(c, f);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (match_conv(f, &format, ap) != 1)
				break;
			else
				nconv++;
		}
		else if (isspace(*format))
		{
			if (match_space(f) == -1)
				break;
		}
		else if (match_char(f, *format) != 1)
			break;
		format++;
	}
	
	if (ferror(f))
		return EOF;
	return nconv;
}

int ft_scanf(const char *format, ...)
{
	va_list ap;
	va_start (ap, format);
	int ret = ft_vfscanf(stdin, format, ap);
	va_end(ap);
	return ret;
}
