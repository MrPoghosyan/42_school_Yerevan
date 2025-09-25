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

#include "../includ/philo.h"

void	take_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		safe_mutex_lock(philo->left_fork);
		print_status(philo, "has taken a fork");
		safe_mutex_lock(philo->right_fork);
		print_status(philo, "has taken a fork");
	}
	else
	{
		safe_mutex_lock(philo->right_fork);
		print_status(philo, "has taken a fork");
		safe_mutex_lock(philo->left_fork);
		print_status(philo, "has taken a fork");
	}
}

void	releases_forks(t_philo *philo)
{
	safe_mutex_unlock(philo->left_fork);
	safe_mutex_unlock(philo->right_fork);
}

static void	philo_eat(t_philo *philo)
{
	if (check_stop(philo->data))
		return ;
	take_forks(philo);
	if (check_stop(philo->data))
	{
		releases_forks(philo);
		return ;
	}
	print_status(philo, "is eating");
	pthread_mutex_lock(&philo->data->meal_mtx);
	philo->last_meal = ft_gettime();
	pthread_mutex_unlock(&philo->data->meal_mtx);
	ft_sleep(philo->data->time_to_eat, philo->data);
	pthread_mutex_lock(&philo->data->meal_mtx);
	philo->eat_count++;
	if (philo->data->must_eat > 0
		&& philo->eat_count == philo->data->must_eat
		&& !philo->finished)
	{
		philo->data->finished_count++;
		philo->finished = true;
	}
	pthread_mutex_unlock(&philo->data->meal_mtx);
	releases_forks(philo);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		ft_sleep(philo->data->time_to_eat / 2, philo->data);
	if (philo->data->num_philos == 1)
		return (single_philo(philo), NULL);
	while (!check_stop(philo->data) && !is_full(philo))
	{
		philo_eat(philo);
		if (check_stop(philo->data) || is_full(philo))
			break ;
		print_status(philo, "is sleeping");
		ft_sleep(philo->data->time_to_sleep, philo->data);
		if (check_stop(philo->data) || is_full(philo))
			break ;
		print_status(philo, "is thinking");
		smart_thinking(philo);
	}
	return (NULL);
}
