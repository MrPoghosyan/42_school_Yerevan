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

bool	check_numbers(int argc, char **argv)
{
	int	i;

	i = 0;
	while (++i < argc)
		if (!is_valid_number(argv[i]))
			return (printf("Error: arg %d invalid\n", i), false);
	return (true);
}

bool	check_philo_count(t_data *data)
{
	if (data->num_philos <= 0 || data->num_philos > PHILO_MAX)
		return (printf("Error: philo count 1-%d\n", PHILO_MAX), false);
	return (true);
}

bool	check_times(t_data *data)
{
	if (data->time_to_die <= 0 || data->time_to_eat <= 0
		|| data->time_to_sleep <= 0)
		return (printf("Error: times must be > 0\n"), false);
	return (true);
}

bool	check_meals(t_data *data, int argc)
{
	if (argc == 6 && data->must_eat <= 0)
		return (printf("Error: meals must be > 0\n"), false);
	return (true);
}

bool	validate_args(t_data *data, int argc, char **argv)
{
	if (!check_numbers(argc, argv)
		|| !check_philo_count(data)
		|| !check_times(data)
		|| !check_meals(data, argc))
		return (false);
	return (true);
}

void single_philo(t_philo *philo)
{
    print_status(philo, "has taken a fork");
    ft_sleep(philo->data->time_to_die, philo->data);
}
