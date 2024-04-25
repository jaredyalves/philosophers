/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcapistr <jcapistr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 11:57:59 by jcapistr          #+#    #+#             */
/*   Updated: 2024/04/25 12:01:04 by jcapistr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_philo_dead(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos[0].num_of_philos)
	{
		pthread_mutex_lock(philos[i].meal_lock);
		if (get_current_time() - philos[i].last_meal >= philos[i].time_to_die
			&& philos[i].eating == 0)
		{
			print_message("died", &philos[i], philos[i].id);
			pthread_mutex_lock(philos[i].dead_lock);
			*philos[i].is_dead = 1;
			pthread_mutex_unlock(philos[i].meal_lock);
			pthread_mutex_unlock(philos[i].dead_lock);
			return (1);
		}
		pthread_mutex_unlock(philos[i].meal_lock);
		i++;
	}
	return (0);
}

static int	check_philo_full(t_philo *philos)
{
	int	i;
	int	finished_eating;

	i = 0;
	finished_eating = 0;
	if (philos[0].num_times_to_eat == -1)
		return (0);
	while (i < philos[0].num_of_philos)
	{
		pthread_mutex_lock(philos[i].meal_lock);
		if (philos[i].meals_eaten >= philos[i].num_times_to_eat)
			finished_eating++;
		pthread_mutex_unlock(philos[i].meal_lock);
		i++;
	}
	if (finished_eating == philos[0].num_of_philos)
	{
		pthread_mutex_lock(philos[0].dead_lock);
		*philos->is_dead = 1;
		pthread_mutex_unlock(philos[0].dead_lock);
		return (1);
	}
	return (0);
}

void	*monitor_routine(void *ptr)
{
	t_philo	*philos;

	philos = (t_philo *)ptr;
	while (1)
		if (check_philo_dead(philos) || check_philo_full(philos))
			break ;
	return (ptr);
}

// vim: ts=4 sts=4 sw=4 noet
