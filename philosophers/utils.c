/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobeiss <rkobeiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 16:58:17 by rkobeiss          #+#    #+#             */
/*   Updated: 2026/02/10 16:33:02 by rkobeiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000 + time.tv_usec / 1000));
}

// void	meals_reached(void *args)
// {
// 	t_philo			*philo;

// 	philo = (t_philo *)args;
// 	if (philo->data->meals != -1 && !philo->done
// 		&& philo->n_meals >= philo->data->meals)
// 	{
// 		philo->done = 1;
// 		pthread_mutex_lock(&philo->data->finish);
// 		philo->data->fin += 1;
// 		if (philo->data->fin == philo->data->n_philo)
// 		{
// 			pthread_mutex_lock(&philo->data->dead_msg);
// 			philo->data->death = 1;
// 			pthread_mutex_unlock(&philo->data->dead_msg);
// 		}
// 		pthread_mutex_unlock(&philo->data->finish);
// 	}
// }

// void	*single_philo_case(void *args)
// {
// 	t_philo			*philo;

// 	philo = (t_philo *)args;
// 	pthread_mutex_lock(philo->l_fork);
// 	print_state(philo->data, philo->id, "has taken a fork");
// 	while (!check_death(philo))
// 		ft_sleep(1);
// 	pthread_mutex_unlock(philo->l_fork);
// 	return (NULL);
// }

void	print_state(t_data *d, int id, const char *msg)
{
	long	t;

	pthread_mutex_lock(&d->dead_msg);
	if (d->death)
	{
		pthread_mutex_unlock(&d->dead_msg);
		return ;
	}
	pthread_mutex_unlock(&d->dead_msg);
	pthread_mutex_lock(&d->print_msg);
	t = get_time() - d->start;
	printf("%ld %d %s\n", t, id, msg);
	pthread_mutex_unlock(&d->print_msg);
}

// int	check_death(t_philo *philo)
// {
// 	long	curr;
// 	long	times;

// 	pthread_mutex_lock(&philo->data->dead_msg);
// 	times = (get_time() - (philo->lm));
// 	if (times > philo->data->ttd)
// 	{
// 		philo->data->death = 1;
// 		curr = get_time() - philo->data->start;
// 		pthread_mutex_unlock(&philo->data->dead_msg);
// 		return (1);
// 	}
// 	pthread_mutex_unlock(&philo->data->dead_msg);
// 	return (0);
// }
int	check_death(t_philo *philo)
{
	int	d;

	pthread_mutex_lock(&philo->data->dead_msg);
	d = philo->data->death;
	pthread_mutex_unlock(&philo->data->dead_msg);
	return (d);
}
