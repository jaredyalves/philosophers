/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcapistr <jcapistr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 15:58:57 by jcapistr          #+#    #+#             */
/*   Updated: 2024/04/25 10:44:47 by jcapistr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (str[i] - '0') + (result * 10);
		i++;
	}
	return (result * sign);
}

void	destroy_mutexes(char *err, t_program *program, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	if (err)
		print_error(err);
	pthread_mutex_destroy(&program->dead_lock);
	pthread_mutex_destroy(&program->meal_lock);
	pthread_mutex_destroy(&program->write_lock);
	while (i < program->philos[0].num_of_philos)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
}

void	print_error(char *err)
{
	int	i;

	i = 0;
	while (err[i] != '\0')
	{
		write(STDERR_FILENO, &err[i], 1);
		i++;
	}
	write(STDERR_FILENO, "\n", 1);
}

void	print_error_and_exit(char *err)
{
	print_error(err);
	exit(EXIT_FAILURE);
}

void	print_message(char *str, t_philo *philo, int philo_id)
{
	size_t	time;

	pthread_mutex_lock(philo->write_lock);
	time = get_current_time() - philo->start_time;
	if (!is_philo_dead(philo))
		printf("%zu %d %s\n", time, philo_id, str);
	pthread_mutex_unlock(philo->write_lock);
}

// vim: ts=4 sts=4 sw=4 noet
