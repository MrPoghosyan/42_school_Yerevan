/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   actions.c										  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: vapoghos <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/06/24 11:36:01 by vapoghos		  #+#	#+#			 */
/*   Updated: 2025/06/24 11:36:04 by vapoghos		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "philo.h"

void	safe_mutex_lock(pthread_mutex_t *mutex)
{
	if (pthread_mutex_lock(mutex) != 0)
		printf("Error: mutex lock failed!\n");
}

void	safe_mutex_unlock(pthread_mutex_t *mutex)
{
	if (pthread_mutex_unlock(mutex) != 0)
		printf("Error: mutex unlock failed!\n");
}

void	take_forks(t_philo *philo)
{
	pthread_mutex_t	*first;
	pthread_mutex_t	*second;

	if (philo->left_fork < philo->right_fork)
	{
		first = philo->left_fork;
		second = philo->right_fork;
	}
	else
	{
		first = philo->right_fork;
		second = philo->left_fork;
	}
	safe_mutex_lock(first);
	print_status(philo, "has taken a fork");
	safe_mutex_lock(second);
	print_status(philo, "has taken a fork");
}

void	releases_forks(t_philo *philo)
{
	safe_mutex_unlock(philo->left_fork);
	safe_mutex_unlock(philo->right_fork);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		ft_sleep(philo->data->time_to_eat / 2, philo->data);
	if (philo->data->num_philos == 1)
	{
		print_status(philo, "has taken a fork");
		ft_sleep(philo->data->time_to_die, philo->data);
		print_status(philo, "died");
		return (NULL);
	}
	while (!check_stop(philo->data))
	{
		take_forks(philo);
		if (check_stop(philo->data))
		{
			releases_forks(philo);
			break ;
		}
		start_eating(philo);
		releases_forks(philo);
		if (check_stop(philo->data))
			break ;
		print_status(philo, "is sleeping");
		ft_sleep(philo->data->time_to_sleep, philo->data);
		if (check_stop(philo->data))
			break ;
		print_status(philo, "is thinking");
	}
	return (NULL);
}
