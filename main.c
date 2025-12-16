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

void	get_time_in_ms(t_data *arg)
{
	struct timeval	tv;
	long			result;

	gettimeofday(&tv, NULL);
	result = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	arg->start_time = result;
	return ;
}

void	create_philo_thread(t_philo *stats, t_data *info)
{
	pthread_t	philo[info->num_philo];
	int			i;
	
	i = 0;
	while (i < info->num_philo)
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
	monitoring_thread_creation(stats, info); //where the monitoring thread is created and run to check on other philos
	i = 0;
	while (i < info->num_philo)
	{
		if (pthread_join(philo[i], NULL) != 0)
		{
			perror("Error to join thread\n");
			break ;
		}
		i++;
	}
}

void	info_init(t_data *info)
{
	info->start_time = 0;
	info->num_philo = 0;
	info->time_to_die = 0;
	info->time_to_eat = 0;
	info->time_to_sleep = 0;
	info->num_of_meals = 0;
}

int	collect_user_info(t_data *info, int argc, char **argv)
{
	for (int i = 0; i < argc; i++)
		printf("argv:%s\n", argv[i]);
	printf("atoi:%d\n", ft_atoi(argv[1]));
	info_init(info);
	if (arg_all_digits(argc, argv) == 1)
	{
		printf("Please insert integer characters\n");
		return (1);
	}
	get_time_in_ms(info);
	printf("%p\n", &info->num_philo);
	printf("what is num_philo:%d\n", info->num_philo);
	info->num_philo = ft_atoi(argv[1]);
	info->time_to_die = ft_atol(argv[2]);
	info->time_to_eat = ft_atol(argv[3]);
	info->time_to_sleep = ft_atol(argv[4]);
	if (argc == 6)
		info->num_of_meals = ft_atoi(argv[5]);
	return (0);
}


int main(int argc, char **argv)
{
	if (argc == 5 || argc == 6)
	{
		t_philo	stats;
		t_data	*info;

		info = malloc(sizeof(t_data));
		if (collect_user_info(info, argc, argv) == 1)
			return (1);
		printf("start time:%ld\n", info->start_time);
		printf("number of philos:%d\n", info->num_philo);
		printf("time to die:%ld\n", info->time_to_die);
		printf("time to eat:%ld\n", info->time_to_eat);
		printf("time to sleep:%ld\n", info->time_to_sleep);
		printf("number of meals:%d\n", info->num_of_meals);
		create_philo_thread(&stats, info);
		return (0);
	}
	else
		return (1);
}
