#include "philo.h"

bool	is_valid_number(const char *str)
{
	int	i;

	i = 0;
	if (!str || *str == '\0')
		return (false);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (false);
		++i;
	}
	return (true);
}

bool	validate_args(t_data *data, int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!is_valid_number(argv[i]))
		{
			printf("Error: argument %d is not a valid number: %s\n", i, argv[i]);
			return (false);
		}
		++i;
	}
	if (data->num_philos <= 0 || data->num_philos > PHILO_MAX)
    {
        printf("Error: number of philosophers must be between 1 and %d\n", PHILO_MAX);
        return (false);
    }

    if (data->time_to_die <= 0 || data->time_to_eat <= 0 || data->time_to_sleep <= 0)
    {
        printf("Error: time arguments must be greater than 0\n");
        return (false);
    }

    if (argc == 6 && data->must_eat <= 0)
    {
        printf("Error: must_eat must be greater than 0\n");
        return (false);
    }

    return (true);
}

