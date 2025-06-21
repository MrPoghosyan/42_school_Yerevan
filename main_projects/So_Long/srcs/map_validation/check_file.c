/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapoghos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 13:03:59 by vapoghos          #+#    #+#             */
/*   Updated: 2025/06/13 14:06:54 by vapoghos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	check_file_extension(char *file)
{
	int	len;

	if (!file)
		return (0);
	len = ft_strlen(file);
	if (len < 4)
		return (0);
	if (ft_strncmp(file + len - 4, ".ber", 4) != 0)
		return (0);
	return (1);
}

int	check_file_exists(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	close(fd);
	return (1);
}
