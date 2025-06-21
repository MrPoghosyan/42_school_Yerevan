#include <limits.h>
#include <stdio.h>

int ft_printf(const char *form, ...);

int main(void)
{
	int n;

	// === %d TESTS ===
	printf("======== %%d TESTS =========\n");

	n = printf("Original: %d\n", 0);
	printf("Return:   %d\n", n);
	n = ft_printf("My:       %d\n", 0);
	printf("Return:   %d\n\n", n);

	n = printf("Original: %d\n", INT_MAX);
	printf("Return:   %d\n", n);
	n = ft_printf("My:       %d\n", INT_MAX);
	printf("Return:   %d\n\n", n);

	n = printf("Original: %d\n", INT_MIN);
	printf("Return:   %d\n", n);
	n = ft_printf("My:       %d\n", INT_MIN);
	printf("Return:   %d\n\n", n);

	n = printf("Original: %d\n", -12345);
	printf("Return:   %d\n", n);
	n = ft_printf("My:       %d\n", -12345);
	printf("Return:   %d\n\n", n);

	n = printf("Original: %d, %d, %d\n", 1, -1, 100);
	printf("Return:   %d\n", n);
	n = ft_printf("My:       %d, %d, %d\n", 1, -1, 100);
	printf("Return:   %d\n\n", n);

	// === %s TESTS ===
	printf("======== %%s TESTS =========\n");

	n = printf("Original: %s\n", "Hello");
	printf("Return:   %d\n", n);
	n = ft_printf("My:       %s\n", "Hello");
	printf("Return:   %d\n\n", n);

	n = printf("Original: %s\n", "");
	printf("Return:   %d\n", n);
	n = ft_printf("My:       %s\n", "");
	printf("Return:   %d\n\n", n);

	n = printf("Original: %s\n", (char *)NULL);
	printf("Return:   %d\n", n);
	n = ft_printf("My:       %s\n", NULL);
	printf("Return:   %d\n\n", n);

	n = printf("Original: %s, %s\n", "Test1", "Test2");
	printf("Return:   %d\n", n);
	n = ft_printf("My:       %s, %s\n", "Test1", "Test2");
	printf("Return:   %d\n\n", n);

	// === %x TESTS ===
	printf("======== %%x TESTS =========\n");

	n = printf("Original: %x\n", 0);
	printf("Return:   %d\n", n);
	n = ft_printf("My:       %x\n", 0);
	printf("Return:   %d\n\n", n);

	n = printf("Original: %x\n", 10);
	printf("Return:   %d\n", n);
	n = ft_printf("My:       %x\n", 10);
	printf("Return:   %d\n\n", n);

	n = printf("Original: %x\n", 255);
	printf("Return:   %d\n", n);
	n = ft_printf("My:       %x\n", 255);
	printf("Return:   %d\n\n", n);

	n = printf("Original: %x\n", INT_MAX);
	printf("Return:   %d\n", n);
	n = ft_printf("My:       %x\n", INT_MAX);
	printf("Return:   %d\n\n", n);

	n = printf("Original: %x\n", (unsigned int)INT_MIN);
	printf("Return:   %d\n", n);
	n = ft_printf("My:       %x\n", (unsigned int)INT_MIN);
	printf("Return:   %d\n\n", n);

	n = printf("Original: %x, %x\n", 0xABCDEF, 0x123456);
	printf("Return:   %d\n", n);
	n = ft_printf("My:       %x, %x\n", 0xABCDEF, 0x123456);
	printf("Return:   %d\n\n", n);

	return 0;
}
