#include "philosopher.h"

void	simulate_philosopher(t_philosopher *philosopher
		, pthread_mutex_t *left_fork, pthread_mutex_t	*right_fork)
{
	pthread_mutex_lock(left_fork);
	log_philosopher_action("has taken a fork", philosopher);
	pthread_mutex_lock(right_fork);
	log_philosopher_action("has taken a fork", philosopher);
	log_philosopher_action("is eating", philosopher);
	philosopher->last_meal_time = get_current_time(philosopher->sim);
	custom_sleep(philosopher->sim->time_to_eat, philosopher->sim);
	philosopher->meals_eaten++;
	pthread_mutex_unlock(left_fork);
	pthread_mutex_unlock(right_fork);
	log_philosopher_action("is sleeping", philosopher);
	custom_sleep(philosopher->sim->time_to_sleep, philosopher->sim);
	log_philosopher_action("is thinking", philosopher);
}

void	handle_single_philosopher(pthread_mutex_t *fork,
		t_philosopher *philosopher)
{
	pthread_mutex_lock(fork);
	log_philosopher_action("has taken a fork", philosopher);
}

void	*philosopher_routine(void *param)
{
	t_philosopher	*philosopher;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;

	philosopher = (t_philosopher *)param;
	while (philosopher->sim->has_started == 0)
		;
	left_fork = &philosopher->fork;
	right_fork = &philosopher->sim->philosophers[(philosopher->id + 1)
		% philosopher->sim->total_philosophers].fork;
	if (philosopher->id % 2 == 1)
	{
		left_fork = &philosopher->sim->philosophers[(philosopher->id + 1)
			% philosopher->sim->total_philosophers].fork;
		right_fork = &philosopher->fork;
		custom_sleep(10, philosopher->sim);
	}
	if (left_fork == right_fork)
	{
		handle_single_philosopher(left_fork, philosopher);
		return (NULL);
	}
	while (philosopher->sim->has_finished == 0)
		simulate_philosopher(philosopher, left_fork, right_fork);
	return (NULL);
}

t_bool	initialize_philosophers(t_simulation *sim)
{
	int	i;

	sim->philosophers = malloc(sim->total_philosophers * sizeof(t_philosopher));
	if (sim->philosophers == NULL)
		return (0);
	if (pthread_mutex_init(&sim->print_mutex, NULL) != 0)
		return (0);
	i = 0;
	while (i < sim->total_philosophers)
	{
		clear_memory(&sim->philosophers[i], sizeof(t_philosopher));
		sim->philosophers[i].id = i;
		sim->philosophers[i].sim = sim;
		if (pthread_mutex_init(&sim->philosophers[i].fork, NULL) != 0)
			return (0);
		if (pthread_create(&sim->philosophers[i].thread, NULL,
				philosopher_routine, &sim->philosophers[i]) != 0)
			return (0);
		i++;
	}
	sim->start_time = get_current_time(sim);
	sim->has_started = 1;
	return (1);
}
