/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapoghos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 22:07:46 by vapoghos          #+#    #+#             */
/*   Updated: 2024/12/02 22:17:29 by vapoghos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	int		i;
	char	c;

	i = 0;
	while (str[i])
	{
		c = str[i];
		if ((c < 'a' || c > 'z') && (c < 'A' || c > 'Z'))
			return (0);
		i++;
	}
	return (1);
}

/* int	main(void)
{
	printf("%d\n", ft_str_is_alpha("abcdefg"));
	printf("%d\n", ft_str_is_alpha("hello, world!"));
	printf("%d\n", ft_str_is_alpha(""));
} */
