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

void print_status(t_philo *philo, const char *status)
{
    pthread_mutex_lock(&philo->data->print);
    if (!check_stop(philo->data) || ft_strncmp(status, "died", 4) == 0)
    {
        printf("%lld %d %s\n", ft_gettime() - philo->data->start_time,
               philo->id, status);
    }
    pthread_mutex_unlock(&philo->data->print);
}

bool    is_full(t_philo *philo)
{
    bool    full;

    pthread_mutex_lock(&philo->data->meal_mtx);
    full = (philo->data->must_eat > 0 && philo->eat_count >= philo->data->must_eat);
    pthread_mutex_unlock(&philo->data->meal_mtx);
    return (full);
}

void    smart_thinking(t_philo *philo)
{
    long long last_meal;
    long long current_time;
    long long time_since_meal;
    long long think_time;

    pthread_mutex_lock(&philo->data->meal_mtx);
    last_meal = philo->last_meal;
    pthread_mutex_unlock(&philo->data->meal_mtx);

    current_time = ft_gettime();
    time_since_meal = current_time - last_meal;

    // Եթե մոտ է մահանալուն, արագ դիտարկել
    if (time_since_meal > philo->data->time_to_die * 0.7)
        think_time = 1;
    else
        think_time = (philo->data->time_to_die - time_since_meal
                     - philo->data->time_to_eat - philo->data->time_to_sleep) / 2;

    if (think_time > 0)
        ft_sleep(think_time, philo->data);
}
