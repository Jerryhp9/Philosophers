/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhor <jhor@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 17:48:09 by jhor              #+#    #+#             */
/*   Updated: 2025/12/17 15:52:33 by jhor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
//!How do i make it so where a philo knows when to take the fork when it's not under mutex. I am using mutex to represents as right and left fork
/*the routine for a philosopher is to try to pick up the fork. If successful mutex would locked
and the philo can eat. Other philo would be thinking or sleeping. If failed indicating there is another philo eating, it will think*/

long	get_start_time(long time)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (time);
}

void	print_thinking(void *arg, t_philo *stats) //!remove this for now
{
	pthread_mutex_t	think;

	pthread_mutex_init(&think, NULL);
	pthread_mutex_lock(&think);
	printf("%ld %d is thinking\n", *(long *)arg, stats->philo_num);
	pthread_mutex_unlock(&think);
	pthread_mutex_destroy(&think);
}

void	*philo_start(void *arg)
{
	long	time;

	time = 0;
	time = get_start_time(time);
	print_thinking(&time, (t_philo *)arg);
	return (arg);
}

bool	not_all_philo_eaten(t_data *info)
{
	int	i;

	i = 0;
	while ()
	{
		
	}
	if (i == info->num_philo)
		
}

void	get_fork(t_philo *philo)
{
	philo->info->pforks[philo->info->num_philo]
}

void	*philo_routine(void *arg)
{
	t_philo	*argp;
	
	argp = (t_philo *)arg;
	if (argp->philo_num % 2 != 0)
		usleep(1000);
	while (!argp->info->simulation_ends)
	{
		//get the time with gettimeofday func and print timestamp of sleeping
		//get the fork (lock mutex) and eat
		//get the time with gettimeofday func and print timestamp of taking fork and eat
		//once finish, put back fork (unlock mutex) and sleep
		get_fork(argp);
		eat(argp);
		sleep_think(argp);
	}
}
