/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapoghos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 13:04:24 by vapoghos          #+#    #+#             */
/*   Updated: 2025/06/12 20:45:54 by vapoghos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	validate_map(char *file, t_map *map)
{
	if (!check_file_extension(file))
		exit_with_error("Map file must have .ber extension", NULL);
	if (!check_file_exists(file))
		exit_with_error("Cannot open map file", NULL);
	if (!read_map_file(file, map))
		exit_with_error("Failed to read map file", map);
	if (!validate_map_contents(map))
		exit_with_error("Invalid map contents", map);
	if (!has_valid_path(map))
		exit_with_error("No valid path in map", map);
	return (1);
}
