#include "../includ/philo.h"

static bool	check_meals(t_data *data, int argc)
{
	if (argc == 6 && data->must_eat <= 0)
		return (printf("Error: meals must be > 0\n"), false);
	return (true);
}

bool	validate_args(t_data *data, int argc, char **argv)
{
	if (!check_numbers(argc, argv)
		|| !check_philo_count(data)
		|| !check_times(data)
		|| !check_meals(data, argc))
		return (false);
	return (true);
}

void	single_philo(t_philo *philo)
{
	print_status(philo, "has taken a fork");
	ft_sleep(philo->data->time_to_die, philo->data);
}
