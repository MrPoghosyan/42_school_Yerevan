/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapoghos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 22:11:42 by vapoghos          #+#    #+#             */
/*   Updated: 2024/12/02 22:18:19 by vapoghos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < 32 || str[i] > 126)
			return (0);
		i++;
	}
	return (1);
}

/* int	main(void)
{
	printf("%d\n", ft_str_is_printable("hello"));
	printf("%d\n", ft_str_is_printable("hello\nworld"));
	printf("%d\n", ft_str_is_printable(""));
} */
