#include "philosopher.h"

int	main(int argc, char **argv)
{
	int		i;
	t_simulation	sim;

	sim = (t_simulation){0};
	initialize_simulation(argc, argv, &sim);
	if (!initialize_philosophers(&sim))
		show_error(3);
	monitor_philosophers(&sim);
	sim.has_finished = 1;
	i = -1;
	while (++i < sim.total_philosophers)
		pthread_join(sim.philosophers[i].thread, 0);
	
	// Libérer la mémoire allouée
	cleanup_simulation(&sim);

	return (0);
}
