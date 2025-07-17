/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapoghos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 11:36:14 by vapoghos          #+#    #+#             */
/*   Updated: 2025/06/24 11:36:18 by vapoghos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	check_stop(t_data *data)
{
	bool	stop;

	pthread_mutex_lock(&data->stop_mtx);
	stop = data->stop;
	pthread_mutex_unlock(&data->stop_mtx);
	return (stop);
}

static bool	check_meal_completion(t_data *data)
{
	int	i;

	if (data->must_eat == 0)
		return (true);
	i = 0;
	while (i < data->num_philos)
	{
		pthread_mutex_lock(&data->stop_mtx);
		if (data->philos[i].eat_count < data->must_eat)
		{
			pthread_mutex_unlock(&data->stop_mtx);
			return (false);
		}
		pthread_mutex_unlock(&data->stop_mtx);
		++i;
	}
	return (true);
}

static bool	check_philosopher_death(t_data *data)
{
	int			i;
	long long	current_time;

	i = 0;
	current_time = ft_gettime();
	while (i < data->num_philos)
	{
		pthread_mutex_lock(&data->stop_mtx);
		if (current_time - data->philos[i].last_meal
			> data->time_to_die && !data->stop)
		{
			data->stop = true;
			pthread_mutex_unlock(&data->stop_mtx);
			print_status(&data->philos[i], "died");
			return (true);
		}
		pthread_mutex_unlock(&data->stop_mtx);
		++i;
	}
	return (false);
}

void	*monitor_routine(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	while (true)
	{
		if (check_philosopher_death(data))
			break ;
		if (data->must_eat != -1 && check_meal_completion(data))
		{
			pthread_mutex_lock(&data->stop_mtx);
			data->stop = true;
			pthread_mutex_unlock(&data->stop_mtx);
			break ;
		}
		ft_sleep(5);
	}
	return (NULL);
}
