/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapoghos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:50:58 by vapoghos          #+#    #+#             */
/*   Updated: 2024/12/06 11:07:37 by vapoghos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	is_valid_base(char *base)
{
	int	i;
	int	j;

	if (ft_strlen(base) < 2)
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		base_len;
	char	c;

	if (!is_valid_base(base))
		return ;
	base_len = ft_strlen(base);
	if (nbr == -2147483648)
	{
		write(1, "-", 1);
		ft_putnbr_base(-(nbr / base_len), base);
		c = base[-(nbr % base_len)];
		write(1, &c, 1);
		return ;
	}
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
	}
	if (nbr >= base_len)
		ft_putnbr_base(nbr / base_len, base);
	c = base[nbr % base_len];
	write(1, &c, 1);
}
/*
int	main(void)
{
	ft_putnbr_base(42, "0123456789");        // 42
	write(1, "\n", 1);
	ft_putnbr_base(-42, "01");              // -101010
	write(1, "\n", 1);
	ft_putnbr_base(255, "0123456789ABCDEF"); // FF
	write(1, "\n", 1);
	ft_putnbr_base(100, "poneyvif");        // eyy
	write(1, "\n", 1);
	ft_putnbr_base(42, "");                 // no
	ft_putnbr_base(42, "028+8");            // no
	ft_putnbr_base(42, "0123-56");          // no
	write(1, "\n", 1);
	ft_putnbr_base(42, "01234567789");      // no
}
*/
