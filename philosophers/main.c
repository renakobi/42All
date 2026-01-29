/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobeiss <rkobeiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 17:40:13 by rkobeiss          #+#    #+#             */
/*   Updated: 2026/01/29 20:34:52 by rkobeiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create(t_philo *philo, t_data data)
{
	int	i;

	i = 0;
	while (i < philo->data.n_philo)
	{
		pthread_create(&philo[i].thread, NULL, (void *)&philo_eat_sleep,
			&philo[i]);
		i++;
	}
	i = 0;
	while (i < data.n_philo)
		pthread_join(philo[i++].thread, NULL);
}

void	data_init(t_philo *philo, t_data data)
{
	int	i;

	i = 0;
	while (i < data.n_philo)
	{
		philo[i].id = i + 1;
		philo[i].data = data;
		philo[i].l_fork = &data.fork[i];
		philo[i].r_fork = &data.fork[(i + 1) % data.n_philo];
		philo[i].lm = data.start;
		philo[i].n_meals = 0;
		philo[i].data = data;
		philo[i].data.death = 0;
		i++;
	}
}

void	set_data(char **av, t_data *data)
{
	data->n_philo = atoi(av[1]);
	data->ttd = atoi(av[2]);
	data->tte = atoi(av[3]);
	data->tts = atoi(av[4]);
}

void	free_philo(t_data data, t_philo *philo)
{
	free(data.fork);
	free(philo);
}

int	main(int ac, char **av)
{
	struct timeval	tv;
	t_philo			*philo;
	t_data			data;
	int				i;

	i = 0;
	if (ac == 5 || ac == 6)
	{
		gettimeofday(&tv, NULL);
		data.start = tv.tv_sec * 1000 + tv.tv_usec / 1000;
		set_data(av, &data);
		data.fork = malloc(sizeof(pthread_mutex_t) * data.n_philo);
		pthread_mutex_init(&data.print_msg, NULL);
		pthread_mutex_init(&data.dead_msg, NULL);
		while (i < data.n_philo)
			pthread_mutex_init(&data.fork[i++], NULL);
		philo = malloc(sizeof(t_philo) * data.n_philo);
		data_init(philo, data);
		create(philo, data);
		i = 0;
		while (i < data.n_philo)
			pthread_mutex_destroy(&data.fork[i++]);
		pthread_mutex_destroy(&data.print_msg);
		pthread_mutex_destroy(&data.dead_msg);
		free_philo(data, philo);
	}
}
