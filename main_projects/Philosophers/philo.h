/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapoghos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 11:34:17 by vapoghos          #+#    #+#             */
/*   Updated: 2025/07/07 12:59:53 by vapoghos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/*       <pathread.h>
 * pthread_create, pthread_detach, pthread_join, pthread_mutex_init,
 * pthread_mutex_destroy, pthread_mutex_lock or pthread_mutex_unlock.
 */
# include <pthread.h> 
# include <stdlib.h>	//free(), malloc()
# include <string.h>	//memset()
# include <stdio.h>		//printf()
# include <unistd.h>	//write(), usleep()
# include <sys/time.h>	//gettimeofday()
# include <stdbool.h>	//type for bool

# define PHILO_MAX 250

# define ERR_ARGS "Error: wrong arguments!\n"
# define ERR_RANGE "Error: arguments out of range!\n"
# define ERR_INIT "Error: init failed!\n"
# define ERR_THREAD "Error: thread creation failed!\n"

typedef struct s_data	t_data;

typedef struct s_philo
{
	int				id;
	int				eat_count;
	long long		last_meal;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_data			*data;
}	t_philo;

struct s_data
{
	int				num_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	bool			stop;
	long long		start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	pthread_mutex_t	stop_mtx;
	t_philo			*philos;
};

// utils.c
long long	ft_gettime(void);
void		ft_sleep(int ms);
void		cleanup(t_data *data);
void		print_status(t_philo *philo, const char *status);

// init.c
int			init_data(t_data *data, int argc, char **argv);
int			init_philos(t_data *data);

// actions.c
void		*philo_routine(void *arg);
void		take_forks(t_philo *philo);
void		releases_forks(t_philo *philo);

//monitor.c
void		*monitor_routine(void *arg);
bool		check_stop(t_data *data);

//valid.c
bool	is_valid_number(const char *str);
bool	validate_args(t_data *data, int argc, char **argv);

int			ft_atoi(const char *nptr);

#endif
