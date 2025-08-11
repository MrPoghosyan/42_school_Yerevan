/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   utils.c											:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: vapoghos <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/06/24 11:35:51 by vapoghos		  #+#	#+#			 */
/*   Updated: 2025/06/24 11:35:54 by vapoghos		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "philo.h"

long long	ft_gettime(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

void	ft_sleep(int ms, t_data *data)
{
	long long	start;
	long long	elapsed;
	long long	remaining;
	long long	sleep_time;

	start = ft_gettime();
	elapsed = ft_gettime() - start;
	while (elapsed < ms)
	{
		if (check_stop(data))
			break ;
		remaining = ms - elapsed;
		if (remaining > 100)
			sleep_time = 100;
		else
			sleep_time = remaining * 1000;
		usleep(sleep_time);
		elapsed = ft_gettime() - start;
	}
}

void	cleanup(t_data *data)
{
	int	i;

	if (data->forks)
	{
		i = -1;
		while (++i < data->num_philos)
			pthread_mutex_destroy(&data->forks[i]);
		free(data->forks);
	}
	if (data->philos)
		free(data->philos);
	pthread_mutex_destroy(&data->print);
	pthread_mutex_destroy(&data->stop_mtx);
	pthread_mutex_destroy(&data->meal_mtx);
}

void	print_status(t_philo *philo, const char *status)
{
	pthread_mutex_lock(&philo->data->print);
	if (!check_stop(philo->data))
		printf("%lld %d %s\n", ft_gettime() - philo->data->start_time,
			philo->id, status);
	pthread_mutex_unlock(&philo->data->print);
}

void	start_eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->meal_mtx);
	philo->last_meal = ft_gettime();
	pthread_mutex_unlock(&philo->data->meal_mtx);
	print_status(philo, "is eating");
	ft_sleep(philo->data->time_to_eat, philo->data);
	pthread_mutex_lock(&philo->data->meal_mtx);
	philo->eat_count++;
	if (philo->data->must_eat > 0 && philo->eat_count
		>= philo->data->must_eat)
	{
		philo->data->finished_count++;
	}
	pthread_mutex_unlock(&philo->data->meal_mtx);
}
