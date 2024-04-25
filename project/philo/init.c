/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcapistr <jcapistr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 09:08:30 by jcapistr          #+#    #+#             */
/*   Updated: 2024/04/25 10:42:49 by jcapistr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_args(t_philo *philo, char **argv)
{
	philo->num_of_philos = ft_atoi(argv[1]);
	philo->time_to_die = ft_atoi(argv[2]);
	philo->time_to_eat = ft_atoi(argv[3]);
	philo->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		philo->num_times_to_eat = ft_atoi(argv[5]);
	else
		philo->num_times_to_eat = -1;
}

void	init_philos(t_program *program, pthread_mutex_t *forks, char **argv)
{
	int	i;
	int	num_of_philos;

	i = 0;
	num_of_philos = ft_atoi(argv[1]);
	while (i < ft_atoi(argv[1]))
	{
		program->philos[i].id = i + 1;
		program->philos[i].is_dead = &program->dead_flag;
		program->philos[i].eating = 0;
		program->philos[i].meals_eaten = 0;
		init_args(&program->philos[i], argv);
		program->philos[i].start_time = get_current_time();
		program->philos[i].last_meal = get_current_time();
		program->philos[i].l_fork = &forks[i];
		if (i == 0)
			program->philos[i].r_fork = &forks[num_of_philos - 1];
		else
			program->philos[i].r_fork = &forks[i - 1];
		program->philos[i].dead_lock = &program->dead_lock;
		program->philos[i].meal_lock = &program->meal_lock;
		program->philos[i].write_lock = &program->write_lock;
		i++;
	}
}

void	init_forks(pthread_mutex_t *forks, int num_of_philos)
{
	int	i;

	i = 0;
	while (i < num_of_philos)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
}

void	init_program(t_program *program, t_philo *philos)
{
	program->philos = philos;
	program->dead_flag = 0;
	pthread_mutex_init(&program->dead_lock, NULL);
	pthread_mutex_init(&program->meal_lock, NULL);
	pthread_mutex_init(&program->write_lock, NULL);
}

// vim: ts=4 sts=4 sw=4 noet
