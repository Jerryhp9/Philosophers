/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhor <jhor@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 16:04:11 by jhor              #+#    #+#             */
/*   Updated: 2025/12/15 15:36:23 by jhor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_philo
{
	int		philo_num;
	long	last_meal;
	int		meals;
}	t_philo;

typedef struct s_data
{
	long			start_time;
	pthread_mutex_t	fork;
}	t_data;

long	ft_atol(const char *str);
void	*get_time_in_ms(void *arg);
void	*philo_start(void *arg);
void	philo_routine(t_philo *stats, t_data *info);

#endif