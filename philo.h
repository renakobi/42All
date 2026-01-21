/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobeiss <rkobeiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 17:31:43 by rkobeiss          #+#    #+#             */
/*   Updated: 2025/10/30 20:15:10 by rkobeiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <stdio.h>

typedef struct s_data
{
	int				n_philo;
	long			tte;
	long			ttd;
	long			tts;
	long			start;
	int				meals;
	int				death;
	pthread_mutex_t	*fork;
	pthread_mutex_t	print_msg;
	pthread_mutex_t	dead_msg;
}t_data;
typedef struct s_philo
{
	int				id;
	int				n_meals;
	int				lm;
	pthread_t		thread;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	t_data			data;
}t_philo;

typedef struct s_timevalue
{
	time_t		tv_sec;
	suseconds_t	tv_usec;
}	t_timevalue;

void	philo_eat_sleep(void *args);
long	get_time(void);
int		check_death(t_philo *philo);
#endif