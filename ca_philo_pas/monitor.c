#include "philosopher.h"

void	custom_sleep(int duration, t_simulation *sim)
{
	int	start;

	start = get_current_time(sim);
	if (!sim->has_finished)
	{
		while (start + duration > get_current_time(sim) && !sim->has_finished)
			;
	}
}

void	monitor_philosophers(t_simulation *sim)
{
	int	i;
	int	satisfied_philosophers;

	while (1)
	{
		i = 0;
		satisfied_philosophers = 0;
		while (i < sim->total_philosophers)
		{
			if (get_current_time(sim) > sim->philosophers[i].last_meal_time
				+ sim->time_to_die)
			{
				log_philosopher_action("died", &sim->philosophers[i]);
				sim->has_finished = 1;
				return ;
			}
			if (sim->philosophers[i].meals_eaten >= sim->required_meals)
				satisfied_philosophers++;
			i++;
		}
		if (sim->has_required_meals && satisfied_philosophers
			== sim->total_philosophers)
			return ;
	}
}
