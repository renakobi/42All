/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobeiss <rkobeiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 16:58:17 by rkobeiss          #+#    #+#             */
/*   Updated: 2026/01/29 19:50:42 by rkobeiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	check_death(t_philo *philo)
{
	long	curr;

	pthread_mutex_lock(&philo->data.dead_msg);
	if (get_time() - philo->lm > philo->data.ttd)
	{
		curr = get_time() - philo->data.start;
		pthread_mutex_lock(&philo->data.print_msg);
		printf("%ld %d died\n", curr, philo->id);
		pthread_mutex_unlock(&philo->data.print_msg);
		philo->data.death = 1;
		pthread_mutex_unlock(&philo->data.dead_msg);
		return (1);
	}
	pthread_mutex_unlock(&philo->data.dead_msg);
	return (0);
}
