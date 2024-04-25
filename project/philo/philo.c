/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcapistr <jcapistr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 09:07:35 by jcapistr          #+#    #+#             */
/*   Updated: 2024/04/25 10:45:03 by jcapistr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_program		program;
	t_philo			philos[MAX_NUM_PHILOS];
	pthread_mutex_t	forks[MAX_NUM_PHILOS];

	check_args(argc, argv);
	init_program(&program, philos);
	init_forks(forks, ft_atoi(argv[1]));
	init_philos(&program, forks, argv);
	create_threads(&program, forks);
	destroy_mutexes(NULL, &program, forks);
	return (0);
}

// vim: ts=4 sts=4 sw=4 noet
