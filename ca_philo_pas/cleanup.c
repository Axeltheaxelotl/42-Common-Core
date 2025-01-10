#include "philosopher.h"

void cleanup_simulation(t_simulation *sim)
{
    int i;

    for (i = 0; i < sim->total_philosophers; i++)
    {
        pthread_mutex_destroy(&sim->philosophers[i].fork);
    }
    pthread_mutex_destroy(&sim->print_mutex);
    free(sim->philosophers);
}
