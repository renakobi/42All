/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobeiss <rkobeiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 19:49:02 by rkobeiss          #+#    #+#             */
/*   Updated: 2026/02/12 20:04:24 by rkobeiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_eat(t_philo *philo)
{
	philo_lock(philo);
	ft_sleep(1);
	print_state(philo->data, philo->id, "is eating");
	pthread_mutex_lock(&philo->data->dead_msg);
	philo->lm = get_time();
	pthread_mutex_unlock(&philo->data->dead_msg);
	ft_sleep(philo->data->tte);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

int	set_death(t_philo *philo, int i)
{
	if ((get_time() - philo[i].lm) >= philo->data->ttd)
	{
		philo->data->death = 1;
		pthread_mutex_unlock(&philo->data->dead_msg);
		pthread_mutex_lock(&philo->data->print_msg);
		printf("%ld %d died\n",
			get_time() - philo->data->start, philo[i].id);
		pthread_mutex_unlock(&philo->data->print_msg);
		return (1);
	}
	return (0);
}

int	more_init(char **av, int i, t_data *data)
{
	if (!data)
		return (1);
	memset(data, 0, sizeof(t_data));
	data->start = get_time();
	set_data(av, data);
	data->fork = malloc(sizeof(pthread_mutex_t) * data->n_philo);
	pthread_mutex_init(&data->print_msg, NULL);
	pthread_mutex_init(&data->dead_msg, NULL);
	while (i < data->n_philo)
		pthread_mutex_init(&data->fork[i++], NULL);
	return (0);
}
