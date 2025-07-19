/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapoghos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 11:35:41 by vapoghos          #+#    #+#             */
/*   Updated: 2025/06/24 11:35:44 by vapoghos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_single_mutex(pthread_mutex_t *mutex)
{
	if (pthread_mutex_init(mutex, NULL) != 0)
	{
		printf("Error: mutex init failed!\n");
		return (1);
	}
	return (0);
}

static int	init_mutexes(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->num_philos)
		if (init_single_mutex(&data->forks[i]))
			return (1);
	if (init_single_mutex(&data->print))
		return (1);
	if (init_single_mutex(&data->stop_mtx))
		return (1);
	return (0);
}

int	init_data(t_data *data, int argc, char **argv)
{
	memset(data, 0, sizeof(t_data));
	data->num_philos = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->must_eat = -1;
	if (argc == 6)
		data->must_eat = ft_atoi(argv[5]);
	if (!validate_args(data, argc, argv))
		return (1);
	data->forks = malloc(sizeof(pthread_mutex_t)
			* data->num_philos);
	if (!data->forks)
		return (1);
	if (init_mutexes(data))
	{
		free(data->forks);
		data->forks = NULL;
		return (1);
	}
	return (0);
}

int	init_philos(t_data *data)
{
	int	i;

	data->philos = malloc(sizeof(t_philo) * data->num_philos);
	if (!data->philos)
		return (1);
	data->start_time = ft_gettime();
	i = -1;
	while (++i < data->num_philos)
	{
		data->philos[i] = (t_philo){
			.id = i + 1,
			.eat_count = 0,
			.last_meal = data->start_time,
			.left_fork = &data->forks[i],
			.right_fork = &data->forks[(i + 1) % data->num_philos],
			.data = data
		};
	}
	return (0);
}
