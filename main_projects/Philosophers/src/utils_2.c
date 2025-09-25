#include "../includ/philo.h"

void	safe_mutex_lock(pthread_mutex_t *mutex)
{
	if (pthread_mutex_lock(mutex) != 0)
		printf("Error: mutex lock failed\n");
}

void	safe_mutex_unlock(pthread_mutex_t *mutex)
{
	if (pthread_mutex_unlock(mutex) != 0)
		printf("Error: mutex unlock failed\n");
}

bool	is_full(t_philo *philo)
{
	bool	full;

	pthread_mutex_lock(&philo->data->meal_mtx);
	full = (philo->data->must_eat > 0
			&& philo->eat_count >= philo->data->must_eat);
	pthread_mutex_unlock(&philo->data->meal_mtx);
	return (full);
}

void	smart_thinking(t_philo *philo)
{
	long long	last_meal;
	long long	current_time;
	long long	time_since_meal;
	long long	think_time;

	pthread_mutex_lock(&philo->data->meal_mtx);
	last_meal = philo->last_meal;
	pthread_mutex_unlock(&philo->data->meal_mtx);
	current_time = ft_gettime();
	time_since_meal = current_time - last_meal;
	if (time_since_meal > philo->data->time_to_die * 0.7)
		think_time = 1;
	else
		think_time = (philo->data->time_to_die
				- time_since_meal
				- philo->data->time_to_eat
				- philo->data->time_to_sleep) / 2;
	if (think_time > 0)
		ft_sleep(think_time, philo->data);
}
