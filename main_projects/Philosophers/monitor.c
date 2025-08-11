/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   monitor.c										  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: vapoghos <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/06/24 11:36:14 by vapoghos		  #+#	#+#			 */
/*   Updated: 2025/06/24 11:36:18 by vapoghos		 ###   ########.fr	   */
/*																			*/
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

static bool	check_philosopher_death(t_data *data)
{
	int			i;
	long long	current_time;
	bool		someone_died;

	i = -1;
	someone_died = false;
	while (++i < data->num_philos)
	{
		pthread_mutex_lock(&data->meal_mtx);
		current_time = ft_gettime();
		if (current_time - data->philos[i].last_meal > data->time_to_die)
		{
			pthread_mutex_lock(&data->stop_mtx);
			if (!data->stop)
			{
				data->stop = true;
				pthread_mutex_unlock(&data->stop_mtx);
				print_status(&data->philos[i], "died");
				someone_died = true;
			}
			else
			{
				pthread_mutex_unlock(&data->stop_mtx);
			}
			pthread_mutex_unlock(&data->meal_mtx);
			return (true);
		}
		pthread_mutex_unlock(&data->meal_mtx);
	}
	return (someone_died);
}

static bool	check_meal_completion(t_data *data)
{
	bool	all_ate;

	pthread_mutex_lock(&data->meal_mtx);
	all_ate = (data->must_eat > 0) && (data->finished_count
			>= data->num_philos);
	pthread_mutex_unlock(&data->meal_mtx);
	return (all_ate);
}

void	*monitor_routine(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	while (true)
	{
		if (check_philosopher_death(data))
			return (NULL);
		if (check_meal_completion(data))
		{
			pthread_mutex_lock(&data->stop_mtx);
			data->stop = true;
			pthread_mutex_unlock(&data->stop_mtx);
			return (NULL);
		}
		usleep(1000);
	}
	return (NULL);
}
