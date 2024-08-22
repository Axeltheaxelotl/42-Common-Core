#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <sys/time.h>

typedef unsigned int			t_bool;

typedef struct s_philosopher	t_philosopher;
typedef struct s_simulation		t_simulation;

typedef struct s_philosopher
{
	int				id;
	int				last_meal_time;
	int				meals_eaten;
	t_simulation	*sim;
	pthread_t		thread;
	pthread_mutex_t	fork;

}	t_philosopher;

typedef struct s_simulation
{
	int				total_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				start_time;
	int				required_meals;
	t_philosopher	*philosophers;
	t_bool			has_started;
	t_bool			has_finished;
	t_bool			has_required_meals;
	pthread_mutex_t	print_mutex;
}	t_simulation;

int		show_error(int code);
void	validate_input(int argc, char **argv, t_simulation *sim);
void	check_min_values(char **argv);
void	initialize_simulation(int argc, char **argv, t_simulation *sim);
int		str_to_int(const char *str);
int		get_current_time(t_simulation *sim);
void	log_philosopher_action(char *msg, t_philosopher *philosopher);
void	custom_sleep(int duration, t_simulation *sim);
void	simulate_philosopher(t_philosopher *philosopher,
			pthread_mutex_t *left_fork,
			pthread_mutex_t	*right_fork);
void	handle_single_philosopher(pthread_mutex_t *fork,
			t_philosopher *philosopher);
void	monitor_philosophers(t_simulation *sim);
void	*philosopher_routine(void *param);
t_bool	initialize_philosophers(t_simulation *sim);
void	clear_memory(void *ptr, size_t size);
void cleanup_simulation(t_simulation *sim);

#endif
