#include <unistd.h>

void	print_bits(unsigned char octet)
{
	int index = 8;
	unsigned char bits;

	while (index--)
	{
		bits = (octet >> index & 1) + '0';
		write (1, &bits, 1);
	}
}

unsigned char	reverse_bits(unsigned char octet)
{
	octet = (octet >> 1 & 0x55) | (octet << 1 & 0xAA);
	octet = (octet >> 2 & 0x33) | (octet << 2 & 0xCC);
	octet = (octet >> 4 & 0x0F) | (octet << 4 & 0xF0);
	return (octet);
}

unsigned char	swap_bits(unsigned char octet)
{
	return ((octet >> 4) | (octet << 4));
}

int main()
{
	print_bits(11);
	write(1,"\n", 1);
	print_bits(reverse_bits(11));
	write(1,"\n", 1);
	print_bits(swap_bits(11));
	return 0;
}
