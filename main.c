/*
!Notes on the subject
There will be a spaghetti on the middle of the table. 
Each Philosopher (thread) has to eat the spaghetti. 
Each Philosopher has a fork to themselves but to eat the spaghetti it requires two forks.
Number of forks is equal to number of philosophers.
Philo's activities: sleep, think and eat.
When a philo is performing one task, they are not performing another task.
Every philo is required to eat and should never starve.
The simulation stops when one of the philo dies of stravation.
When a philo finished eating, they would put back the fork on the table.

Program arguments input in order: 
number_of_philosophers - The number of philosophers and also the number of forks.

time_to_dies (in miliseconds) - If a philosopher has not started eating within time_to_die miliseconds
since the start of thier last meal or the start of the simulation, they die.

time_to_eat (in miliseconds) - The time it takes for a philosopher to eat.

time_to_sleep (in miliseconds) - The time a philosopher will spend sleeping.

number_of_times_each_philosopher_must_eat (optional argument) - If all philosophers have eaten
at least number_of_times_each_philosopher_must_eat times, the simulation stops. If not specified,
the simulation stops when a philosopher dies.

!#Philo Code Structure#
Start of simulation
track the start_time inside t_data struct
create monitoring thread loop
create threads (philosophers) Keep track of how many philos to know how many forks are on the table
print out the statement and timestamp when a philo pick up a fork and when it starts to eat
print out the statement and timestamp when a philo goes to sleep
print out the statement and timestamp when a philo is thinking
print out the statement and timestamp when a philo died and end the program
*/

#include "philo.h"

void	*get_time_in_ms(void *arg)
{
	struct timeval	tv;
	long			result;
	t_data			*temp;

	temp = (t_data *) arg;
	gettimeofday(&tv, NULL);
	result = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	temp->start_time = result;
	return (temp);
}

void	create_philo_thread(long num_philo, t_philo *stats, t_data *info)
{
	pthread_t	philo[num_philo];
	int			i;
	
	i = 0;
	pthread_mutex_init(&info->fork, NULL);
	while (i < num_philo)
	{
		stats[i].philo_num = (i + 1);
		if (pthread_create(&philo[i], NULL, &philo_start, &stats[i]) != 0)
		{
			perror("Error to create thread\n");
			break ;
		}
		i++;
		usleep(1000);
	}
	routine_
	i = 0;
	while (i < num_philo)
	{
		if (pthread_join(philo[i], NULL) != 0)
		{
			perror("Error to join thread\n");
			break ;
		}
		i++;
	}
}

int main(int argc, char **argv)
{
	if (argc > 1)
	{
		long	philo_num;
		t_philo	stats;
		t_data	info;

		philo_num = ft_atol(argv[1]);
		get_time_in_ms(&info);
		create_philo_thread(philo_num, &stats, &info);
		return (0);
	}
	else
		return (1);
}
