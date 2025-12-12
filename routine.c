/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhor <jhor@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 17:48:09 by jhor              #+#    #+#             */
/*   Updated: 2025/12/12 18:53:55 by jhor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*the routine for a philosopher is to try to pick up the fork. If successful mutex would locked
and the philo can eat. Other philo would thinking or sleeping. If failed indicating there is another philo eating, it will think*/

void	*philo_routine(void *arg)
{
	
	//philo would try to get the fork to eat
	t_philo *stat;

	stat = (t_philo*)arg;
	stat->philo_num; //label the number on the philo
	stat->meals; //
	if ()
}