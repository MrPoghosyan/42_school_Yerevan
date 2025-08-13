#include <stdio.h>

int ft_scanf(const char *format, ...);

int main(void)
{
    char c;
    int num;
    char str[100];

    printf("=== Փորձարկում ft_scanf ===\n");
    printf("Մուտքագրիր 1 char, 1 int և 1 string (օր. A 123 Hello):\n");

    int ret = ft_scanf("%c %d %s", &c, &num, str);

    printf("\n--- Արդյունք ---\n");
    printf("Կարդացած տարրերի քանակը: %d\n", ret);
    printf("Char: '%c'\n", c);
    printf("Int: %d\n", num);
    printf("String: \"%s\"\n", str);

    printf("\n=== Համեմատություն scanf-ի հետ ===\n");
    printf("Մուտքագրիր 1 char, 1 int և 1 string (օր. A 123 Hello):\n");

    ret = scanf(" %c %d %99s", &c, &num, str);

    printf("\n--- Արդյունք ---\n");
    printf("Կարդացած տարրերի քանակը: %d\n", ret);
    printf("Char: '%c'\n", c);
    printf("Int: %d\n", num);
    printf("String: \"%s\"\n", str);

    return 0;
}

