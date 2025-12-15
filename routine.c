/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhor <jhor@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 17:48:09 by jhor              #+#    #+#             */
/*   Updated: 2025/12/15 15:40:17 by jhor             ###   ########.fr       */
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

void	print_thinking(void *arg, t_philo *stats)
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

void	philo_routine(t_philo *stats, t_data *info)
{
	int	i = 0;

	while (not_all_philo_eaten)
	{
		if (stats[i].philo_num % 2 == 0)
		{
			//get the time with gettimeofday func and print timestamp of taking fork and eat, lock mutex and unlock mutex when finish
			//once finish, put back fork (unlock mutex) and sleep
		}
		else if (stats[i].philo_num % 2 != 0)
		{
			//get the time with gettimeofday func and print timestamp of sleeping
			usleep(1000);
			//get the fork (lock mutex) and eat
			//get the time with gettimeofday func and print timestamp of taking fork and eat
			//once finish, put back fork (unlock mutex) and sleep
		}
	}
}
