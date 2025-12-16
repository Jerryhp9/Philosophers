/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhor <jhor@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 16:04:11 by jhor              #+#    #+#             */
/*   Updated: 2025/12/16 18:29:30 by jhor             ###   ########.fr       */
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
# include <stdbool.h>

typedef struct s_philo
{
	int				philo_num;
	long			last_meal;
	int				meals;
}	t_philo;

typedef struct s_data
{
	long			start_time;
	int				num_philo;
	long			time_to_eat;
	long			time_to_sleep;
	long			time_to_die;
	int				num_of_meals;
}	t_data;

long	ft_atol(const char *str);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
bool	arg_all_digits(int argc, char **argv);
void	get_time_in_ms(t_data *arg);
void	*philo_start(void *arg);
void	philo_routine(pthread_mutex_t *forks, t_philo *stats, t_data *info);
void	monitoring_thread_creation(t_philo *stats, t_data *info);

#endif