/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vapoghos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 11:35:26 by vapoghos          #+#    #+#             */
/*   Updated: 2025/06/24 11:35:34 by vapoghos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	start_simulation(t_data *data);
static int	start_thread(pthread_t *thread, void *(*func)(void *), void *arg);

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 5 || argc > 6)
		return (printf(ERR_ARGS), 1);
	memset(&data, 0, sizeof(t_data));
	if (init_data(&data, argc, argv))
		return (printf(ERR_INIT), 1);
	if (data.must_eat == 0)
		return (cleanup(&data), printf("All philosophers are full!\n"), 0);
	if (init_philos(&data))
		return (cleanup(&data), printf(ERR_INIT), 1);
	if (start_simulation(&data))
		return (cleanup(&data), printf(ERR_THREAD), 1);
	cleanup(&data);
//	printf("Everyone got full at once!\n");
	return (0);
}

static int	start_thread(pthread_t *thread, void *(*func)(void *), void *arg)
{
	if (pthread_create(thread, NULL, func, arg) != 0)
	{
		printf("Error: thread creation failed!\n");
		return (1);
	}
	return (0);
}

static int	start_simulation(t_data *data)
{
	int			i;
	pthread_t	monitor;

	i = 0;
	while (i < data->num_philos)
	{
		if (start_thread(&data->philos[i].thread, philo_routine,
				&data->philos[i]))
			return (1);
		i++;
	}
	if (start_thread(&monitor, monitor_routine, data))
		return (1);
	i = -1;
	while (++i < data->num_philos)
		pthread_join(data->philos[i].thread, NULL);
	pthread_join(monitor, NULL);
	return (0);
}
