/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapoghos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 13:21:10 by vapoghos          #+#    #+#             */
/*   Updated: 2025/01/29 14:05:59 by vapoghos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*last;

	last = (char *)str + ft_strlen(str);
	while (last >= str)
	{
		if (*last == (char)c)
			return (last);
		last--;
	}
	return (NULL);
}
