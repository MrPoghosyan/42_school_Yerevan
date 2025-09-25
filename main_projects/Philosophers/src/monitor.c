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

#include "../includ/philo.h"

bool	check_stop(t_data *data)
{
	bool	stop;

	pthread_mutex_lock(&data->stop_mtx);
	stop = data->stop;
	pthread_mutex_unlock(&data->stop_mtx);
	return (stop);
}

static bool	check_death(t_data *data, int i)
{
	long long	current;
	bool		died;

	died = false;
	pthread_mutex_lock(&data->meal_mtx);
	current = ft_gettime();
	if (current - data->philos[i].last_meal > data->time_to_die)
	{
		pthread_mutex_lock(&data->stop_mtx);
		if (!data->stop)
		{
			data->stop = true;
			died = true;
		}
		pthread_mutex_unlock(&data->stop_mtx);
		if (died)
		{
			pthread_mutex_unlock(&data->meal_mtx);
			print_status(&data->philos[i], "died");
			return (true);
		}
	}
	pthread_mutex_unlock(&data->meal_mtx);
	return (false);
}

static bool	check_all_meals(t_data *data)
{
	pthread_mutex_lock(&data->meal_mtx);
	if (data->must_eat > 0 && data->finished_count >= data->num_philos)
	{
		pthread_mutex_unlock(&data->meal_mtx);
		pthread_mutex_lock(&data->stop_mtx);
		data->stop = true;
		pthread_mutex_unlock(&data->stop_mtx);
		return (true);
	}
	pthread_mutex_unlock(&data->meal_mtx);
	return (false);
}

void	*monitor_routine(void *arg)
{
	t_data	*data;
	int		i;

	data = (t_data *)arg;
	while (true)
	{
		i = -1;
		while (++i < data->num_philos)
			if (check_death(data, i) || check_all_meals(data))
				return (NULL);
		usleep(1000);
	}
	return (NULL);
}
