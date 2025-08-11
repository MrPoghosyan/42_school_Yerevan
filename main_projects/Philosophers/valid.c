/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapoghos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 11:36:26 by vapoghos          #+#    #+#             */
/*   Updated: 2025/06/24 11:36:29 by vapoghos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	is_valid_number(const char *str)
{
	int	i;

	i = 0;
	if (!str || *str == '\0')
		return (false);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (false);
		++i;
	}
	return (true);
}

bool	validate_args(t_data *data, int argc, char **argv)
{
	int	i;

	i = 0;
	while (++i < argc)
	{
		if (!is_valid_number(argv[i]))
		{
			printf("Error: arg %d invalid number: %s\n", i, argv[i]);
			return (false);
		}
	}
	if (data->num_philos <= 0 || data->num_philos > PHILO_MAX)
	{
		printf("Error: philosophers must be 1-%d\n", PHILO_MAX);
		return (false);
	}
	if (data->time_to_die <= 0 || data->time_to_eat <= 0
		|| data->time_to_sleep <= 0)
	{
		printf("Error: time args must be > 0\n");
		return (false);
	}
	if (argc == 6 && data->must_eat <= 0)
	{
		printf("Error: must_eat must be > 0\n");
		return (false);
	}
	return (true);
}
