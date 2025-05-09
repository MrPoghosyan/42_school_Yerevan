// Օգնական ֆունկցիա՝ գտնելու երկու թվերի GCD (Եվկլիդեսի ալգորիթմ)
static unsigned int gcd(unsigned int a, unsigned int b)
{
	unsigned int temp;

    while (b != 0)
    {
        temp = a % b;
        a = b;
        b = temp;
    }
    return (a);
}

// Գլխավոր ֆունկցիա՝ հաշվարկելու LCM
unsigned int lcm(unsigned int a, unsigned int b)
{
    if (a == 0 || b == 0) // Եթե գոնե մեկը 0 է, վերադարձնել 0
        return (0);
    return (a / gcd(a, b)) * b; // Հաշվարկում ենք LCM՝ առանց overflow-ի
}

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    if (argc == 3) {
    printf("%u\n", lcm(atoi(argv[1]), atoi(argv[2])));
    }
    else
        printf("No valid argument!\n");
    return (0);
}
