#include <stdio.h>
#include <stdlib.h>

// Ֆունկցիա՝ գտնելու երկու թվի GCD-ը (Եվկլիդեսի ալգորիթմ)
int	find_gcd(int a, int b)
{
	int temp;

	while (b != 0)
	{
		temp = a % b ;	// Հաշվում ենք մնացորդը
		a = b;			// "a" դառնում է "b"
		b = temp;		// "b" դառնում է մնացորդը
	}
	return (a); // Երբ մնացորդը 0 է, "a" դառնում է GCD
}

int	main (int argc, char **argv)
{
	if (argc == 3) // Պետք է ճիշտ 2 արգումենտ լինի
	{
		int a = atoi(argv[1]);
		int b = atoi(argv[2]);

		if (a > 0 && b > 0) // Պարտադիր դրական թվեր են պահանջվում
			printf("%d", find_gcd(a, b));
	}

	printf("\n"); // Վերջում newline
	return (0);
}
