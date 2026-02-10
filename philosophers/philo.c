/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobeiss <rkobeiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 19:53:46 by rkobeiss          #+#    #+#             */
/*   Updated: 2026/02/10 16:16:51 by rkobeiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_sleep(long time)
{
	usleep(time * 1000);
}

void	philo_lock(t_philo *philo)
{
	if (philo->id % 2 != 0)
	{			
		pthread_mutex_lock(philo->l_fork);
		print_state(philo->data, philo->id, "has taken a fork");
		ft_sleep(1);
		pthread_mutex_lock(philo->r_fork);
		print_state(philo->data, philo->id, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philo->r_fork);
		print_state(philo->data, philo->id, "has taken a fork");
		ft_sleep(1);
		pthread_mutex_lock(philo->l_fork);
		print_state(philo->data, philo->id, "has taken a fork");
	}
}

void	*philo_think(void *args)
{
	t_philo			*philo;
	long			ttt;
	struct timeval	time;

	philo = (t_philo *)args;
	if (!check_death(philo))
	{
		ttt = (philo->data->tte / 2);
		if (ttt < 0)
			ttt = 0;
		gettimeofday(&time, NULL);
		print_state(philo->data, philo->id, "is thinking");
		ft_sleep(ttt);
		return (NULL);
	}
	return (NULL);
}

void	*philo_eat_sleep(void *args)
{
	t_philo			*philo;

	philo = (t_philo *)args;
	if (philo->data->n_philo == 1)
	{
		pthread_mutex_lock(philo->l_fork);
		print_state(philo->data, philo->id, "has taken a fork");
		while (!check_death(philo))
			ft_sleep(1);
		pthread_mutex_unlock(philo->l_fork);
		return (NULL);
	}
	while (!check_death(philo))
	{
		pthread_mutex_lock(&philo->data->dead_msg);
		if (philo->data->death)
		{
			pthread_mutex_unlock(&philo->data->dead_msg);
			break ;
		}
		pthread_mutex_unlock(&philo->data->dead_msg);
		philo_lock(philo);
		ft_sleep(1);
		print_state(philo->data, philo->id, "is eating");
		pthread_mutex_lock(&philo->data->dead_msg);
		philo->lm = get_time();
		pthread_mutex_unlock(&philo->data->dead_msg);
		ft_sleep(philo->data->tte);
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
		philo->n_meals += 1;
		if (philo->data->meals != -1 && !philo->done
			&& philo->n_meals >= philo->data->meals)
		{
			philo->done = 1;
			pthread_mutex_lock(&philo->data->finish);
			philo->data->fin += 1;
			if (philo->data->fin == philo->data->n_philo)
			{
				pthread_mutex_lock(&philo->data->dead_msg);
				philo->data->death = 1;
				pthread_mutex_unlock(&philo->data->dead_msg);
			}
			pthread_mutex_unlock(&philo->data->finish);
		}
		print_state(philo->data, philo->id, "is sleeping");
		ft_sleep(philo->data->tts);
		philo_think(philo);
	}
	return (NULL);
}

void	*p_death(void *arg)
{
	t_philo	*philo;
	int		i;

	philo = (t_philo *)arg;
	while (1)
	{
		i = 0;
		while (i < philo->data->n_philo)
		{
			pthread_mutex_lock(&philo->data->dead_msg);
			if (philo->data->death)
			{
				pthread_mutex_unlock(&philo->data->dead_msg);
				return (NULL);
			}
			if ((get_time() - philo[i].lm) >= philo->data->ttd)
			{
				philo->data->death = 1;
				pthread_mutex_unlock(&philo->data->dead_msg);
				pthread_mutex_lock(&philo->data->print_msg);
				printf("%ld %d died\n",
					get_time() - philo->data->start, philo[i].id);
				pthread_mutex_unlock(&philo->data->print_msg);
				return (NULL);
			}
			pthread_mutex_unlock(&philo->data->dead_msg);
			i++;
		}
		usleep(10);
	}
}
