/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkobeiss <rkobeiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 17:40:13 by rkobeiss          #+#    #+#             */
/*   Updated: 2026/02/12 20:04:15 by rkobeiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create(t_philo *philo, t_data data)
{
	int			i;
	pthread_t	monitor;

	i = 0;
	pthread_create(&monitor, NULL, &p_death, &philo[0]);
	while (i < philo->data->n_philo)
	{
		pthread_create(&philo[i].thread, NULL, &philo_eat_sleep,
			&philo[i]);
		i++;
	}
	i = 0;
	pthread_join(monitor, NULL);
	while (i < data.n_philo)
		pthread_join(philo[i++].thread, NULL);
}

void	data_init(t_philo *philo, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->n_philo)
	{
		philo[i].id = i + 1;
		philo[i].data = data;
		philo[i].l_fork = &data->fork[i];
		philo[i].r_fork = &data->fork[(i + 1) % data->n_philo];
		philo[i].lm = data->start;
		philo[i].n_meals = 0;
		philo[i].data->death = 0;
		data->fin = 0;
		philo->done = 0;
		pthread_mutex_init(&data->finish, NULL);
		i++;
	}
}

void	set_data(char **av, t_data *data)
{
	data->n_philo = atoi(av[1]);
	if (data->n_philo < 1)
		exit(1);
	data->ttd = atoi(av[2]);
	data->tte = atoi(av[3]);
	data->tts = atoi(av[4]);
	if (av[5])
		data->meals = atoi(av[5]);
	else
		data->meals = -1;
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
	t_data			*data;
	int				i;

	i = 0;
	if (ac != 5 && ac != 6)
		return (1);
	data = malloc(sizeof(t_data));
	gettimeofday(&tv, NULL);
	if (more_init(av, i, data))
		return (1);
	philo = malloc(sizeof(t_philo) * data->n_philo);
	if (!philo)
		return (1);
	memset(philo, 0, sizeof(t_philo) * data->n_philo);
	data_init(philo, data);
	create(philo, *data);
	i = 0;
	while (i < data->n_philo)
		pthread_mutex_destroy(&data->fork[i++]);
	pthread_mutex_destroy(&data->print_msg);
	pthread_mutex_destroy(&data->dead_msg);
	free_philo(*data, philo);
	free(data);
}
