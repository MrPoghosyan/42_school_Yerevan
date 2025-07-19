/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapoghos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 11:35:51 by vapoghos          #+#    #+#             */
/*   Updated: 2025/06/24 11:35:54 by vapoghos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	ft_gettime(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	ft_sleep(int ms)
{
	long long	start;

	start = ft_gettime();
	while (ft_gettime() - start < ms)
		usleep(500);
}

void	print_status(t_philo *philo, const char *status)
{
	pthread_mutex_lock(&philo->data->print);
	if (!check_stop(philo->data) || ft_strncmp(status, "died", ft_strlen(status)) == 0)
		printf("%lld %d %s\n",
				ft_gettime() - philo->data-> start_time,
				philo->id,
				status);
	pthread_mutex_unlock(&philo->data->print);
}

void	cleanup(t_data *data)
{
	int	i;

	if (data->forks)
	{
		i = 0;
		while (i < data->num_philos)
		{
			pthread_mutex_destroy(&data->forks[i]);
			++i;
		}
		free(data->forks);
	}
	if (data->philos)
		free(data->philos);
	pthread_mutex_destroy(&data->print);
	pthread_mutex_destroy(&data->stop_mtx);
}

void	start_eating(t_philo *philo)
{
	long long	time;

	time = ft_gettime();
	safe_mutex_lock(&philo->data->stop_mtx);
	philo->last_meal = time;
	philo->eat_count++;
	safe_mutex_unlock(&philo->data->stop_mtx);
	print_status(philo, "is eating");
	if (!check_stop(philo->data))
		ft_sleep(philo->data->time_to_eat);
}
