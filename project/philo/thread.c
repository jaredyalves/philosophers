/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcapistr <jcapistr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 11:21:16 by jcapistr          #+#    #+#             */
/*   Updated: 2024/04/25 11:26:56 by jcapistr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_philo_dead(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	if (*philo->is_dead == 1)
	{
		pthread_mutex_unlock(philo->dead_lock);
		return (1);
	}
	pthread_mutex_unlock(philo->dead_lock);
	return (0);
}

void	*philo_routine(void *ptr)
{
	t_philo	*philo;

	philo = (t_philo *)ptr;
	if (philo->id % 2 == 0)
		ft_usleep(1);
	while (!is_philo_dead(philo))
	{
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
	return (ptr);
}

int	create_threads(t_program *program, pthread_mutex_t *forks)
{
	char		*err_msg;
	pthread_t	monitor;
	int			i;

	err_msg = "Error creating threads.";
	if (pthread_create(&monitor, NULL, &monitor_routine, program->philos) != 0)
		destroy_mutexes(err_msg, program, forks);
	i = 0;
	while (i < program->philos[0].num_of_philos)
	{
		if (pthread_create(&program->philos[i].thread, NULL, &philo_routine,
				&program->philos[i]) != 0)
			destroy_mutexes(err_msg, program, forks);
		i++;
	}
	i = 0;
	if (pthread_join(monitor, NULL) != 0)
		destroy_mutexes(err_msg, program, forks);
	while (i < program->philos[0].num_of_philos)
	{
		if (pthread_join(program->philos[i].thread, NULL) != 0)
			destroy_mutexes(err_msg, program, forks);
		i++;
	}
	return (0);
}

// vim: ts=4 sts=4 sw=4 noet
