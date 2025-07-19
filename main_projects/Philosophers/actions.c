/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapoghos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 11:36:01 by vapoghos          #+#    #+#             */
/*   Updated: 2025/06/24 11:36:04 by vapoghos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/// Ապահով `mutex_lock`
void safe_mutex_lock(pthread_mutex_t *mutex)
{
    if (pthread_mutex_lock(mutex) != 0)
        printf("Error: mutex lock failed!\n");
}

/// Ապահով `mutex_unlock`
void safe_mutex_unlock(pthread_mutex_t *mutex)
{
    if (pthread_mutex_unlock(mutex) != 0)
        printf("Error: mutex unlock failed!\n");
}

/// Փիլիսոփան վերցնում է պատառաքաղները՝ սատկած չլինելու դեպքում
void take_forks(t_philo *philo)
{
    pthread_mutex_t *first;
    pthread_mutex_t *second;

    // Հնարավոր մահվան ժամանակ կոնֆլիկտներից խուսափելու համար պատառաքաղների կարգ
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

/// Փիլիսոփան թողնում է պատառաքաղները
void releases_forks(t_philo *philo)
{
    safe_mutex_unlock(philo->left_fork);
    safe_mutex_unlock(philo->right_fork);
}

/// Փիլիսոփայի հիմնական գործողությունների լուպ
void *philo_routine(void *arg)
{
    t_philo *philo = (t_philo *)arg;

    // Զույգ ID-ով փիլիսոփաները մի փոքր ուշ սկսեն, կոլիզիաների նվազեցման համար
    if (philo->id % 2 == 0)
        ft_sleep(philo->data->time_to_eat / 2);

    // Եթե մեկ փիլիսոփա է, հատուկ դեպք
    if (philo->data->num_philos == 1)
    {
        print_status(philo, "has taken a fork");
        ft_sleep(philo->data->time_to_die);
        print_status(philo, "died");
        return (NULL);
    }

    // Գլխավոր ցիկլ
    while (!check_stop(philo->data))
    {
        take_forks(philo);
        if (check_stop(philo->data))
        {
            releases_forks(philo);
            break;
        }

        start_eating(philo);
        releases_forks(philo);

        if (check_stop(philo->data))
            break;

        print_status(philo, "is sleeping");
        ft_sleep(philo->data->time_to_sleep);

        if (check_stop(philo->data))
            break;

        print_status(philo, "is thinking");
    }

    return (NULL);
}
