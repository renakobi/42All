/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobeiss <rkobeiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 19:53:46 by rkobeiss          #+#    #+#             */
/*   Updated: 2026/01/29 21:41:23 by rkobeiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
//add timestamps for eat sleep and think
void	ft_sleep(long time)
{
	usleep(time);
}

void	philo_lock(t_philo *philo)
{
		printf("entered philo_lock\n");
	if (philo->id % 2 != 0)
	{
		pthread_mutex_lock(philo->l_fork);
		ft_sleep(200);
		pthread_mutex_lock(philo->r_fork);
	}
	else
	{
		pthread_mutex_lock(philo->r_fork);
		ft_sleep(200);
		pthread_mutex_lock(philo->l_fork);
	}
}

void	philo_think(void *args)
{
		printf("entered philo_think\n");
	t_philo			*philo;
	int				ttt;
	struct timeval	time;

	philo = (t_philo *)args;
	ttt = philo->data.ttd - philo->data.tts;
	gettimeofday(&time, NULL);
	pthread_mutex_lock(&philo->data.print_msg);
	printf("%ld %d is thinking\n",
		get_time() - philo->data.start, philo->id);
	pthread_mutex_unlock(&philo->data.print_msg);
	ft_sleep(ttt * 1000);
}

void	philo_eat_sleep(void *args)
{
	printf("entered philo_eat_sleep\n");
	t_philo			*philo;
	struct timeval	time;

	philo = (t_philo *)args;
	while (!philo->data.death)
	{
		//if (check_death(philo))
		//	break ;
		//FIGURE THIS PART OUT!!!!!!!!!
		philo_lock(philo);
		printf("entered philo_eat_sleep2\n");
		pthread_mutex_lock(&philo->data.print_msg);
		gettimeofday(&time, NULL);
		printf("%ld %d is eating\n", get_time() - philo->data.start,
			philo->id);
		pthread_mutex_unlock(&philo->data.print_msg);
		philo->lm = get_time();
		ft_sleep(philo->data.tte * 1000);
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
		pthread_mutex_lock(&philo->data.print_msg);
		printf("%ld %d is sleeping\n", get_time() - philo->data.start,
			philo->id);
		pthread_mutex_unlock(&philo->data.print_msg);
		ft_sleep(philo->data.tts * 1000);
		philo_think(philo);
	}
}

void	*p_death(void *args)
{
	printf("entered philo_death\n");
	t_philo	*philo;
	int		i;

	philo = (t_philo *)args;
	while (!philo->data.death)
	{
		i = 0;
		while (i < philo->data.n_philo)
		{
			if (get_time() - philo[i].lm > philo->data.ttd)
			{
				check_death(philo + i);
				return (NULL);
			}
			i++;
		}
		ft_sleep(500);
		return (NULL);
	}
	return (NULL);
}
