#include "philosopher.h"

void	initialize_simulation(int argc, char **argv, t_simulation *sim)
{
	if (argc < 5 || argc > 6)
		show_error(1);
	check_min_values(argv);
	sim->total_philosophers = str_to_int(argv[1]);
	sim->time_to_die = str_to_int(argv[2]);
	sim->time_to_eat = str_to_int(argv[3]);
	sim->time_to_sleep = str_to_int(argv[4]);
	if (argc == 6)
	{
		sim->required_meals = str_to_int(argv[5]);
		sim->has_required_meals = 1;
	}
}

int	get_current_time(t_simulation *sim)
{
	struct timeval	time;

	gettimeofday(&time, 0);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000) - sim->start_time);
}

void	log_philosopher_action(char *msg, t_philosopher *philosopher)
{
	pthread_mutex_lock(&philosopher->sim->print_mutex);
	if (!philosopher->sim->has_finished)
		printf("%i %i %s \n", get_current_time(philosopher->sim),
			philosopher->id, msg);
	pthread_mutex_unlock(&philosopher->sim->print_mutex);
}
