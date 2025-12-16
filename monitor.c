/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhor <jhor@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 10:35:58 by jhor              #+#    #+#             */
/*   Updated: 2025/12/16 18:37:42 by jhor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	monitoring_thread_creation(t_philo *stats, t_data *info)
{
	(void)stats;
	pthread_mutex_t	*forks;
	int				i;
	int				init_mutex;
	
	i = 0;
	init_mutex = 0;
	forks = malloc(sizeof(pthread_mutex_t) * (info->num_philo - 1));
	if (!forks)
	{
		perror("Malloc failed\n");
		return ;
	}
	while (i < info->num_philo)
	{
		init_mutex = pthread_mutex_init(forks, NULL);
		if (init_mutex != 0)
			printf("fork[%d] failed to initialize: %s\n", i, strerror(init_mutex));
		else
			printf("SUCCESS on initialising mutex\n");
		i++;
	}
	// philo_routine(forks, stats, info);
	free(forks);
}
