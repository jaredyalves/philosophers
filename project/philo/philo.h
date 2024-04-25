/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcapistr <jcapistr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 12:04:59 by jcapistr          #+#    #+#             */
/*   Updated: 2024/04/25 12:05:15 by jcapistr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define MAX_NUM_PHILOS 200

typedef struct s_program	t_program;
typedef struct s_philo		t_philo;

struct						s_philo
{
	pthread_t				thread;

	int						id;
	int						*is_dead;
	int						eating;
	int						meals_eaten;
	size_t					start_time;
	size_t					last_meal;
	int						num_of_philos;
	size_t					time_to_die;
	size_t					time_to_eat;
	size_t					time_to_sleep;
	int						num_times_to_eat;
	pthread_mutex_t			*l_fork;
	pthread_mutex_t			*r_fork;
	pthread_mutex_t			*dead_lock;
	pthread_mutex_t			*meal_lock;
	pthread_mutex_t			*write_lock;
};

struct						s_program
{
	t_philo					*philos;
	int						dead_flag;
	pthread_mutex_t			dead_lock;
	pthread_mutex_t			meal_lock;
	pthread_mutex_t			write_lock;
};

int							create_threads(t_program *program,
								pthread_mutex_t *forks);
int							ft_atoi(char *str);
int							is_philo_dead(t_philo *philo);
size_t						get_current_time(void);
void						*monitor_routine(void *pointer);
void						*philo_routine(void *pointer);
void						check_args(int argc, char **argv);
void						destroy_mutexes(char *str, t_program *program,
								pthread_mutex_t *forks);
void						ft_usleep(size_t milliseconds);
void						init_forks(pthread_mutex_t *forks, int philo_num);
void						init_philos(t_program *program,
								pthread_mutex_t *forks, char **argv);
void						init_program(t_program *program, t_philo *philos);
void						philo_eat(t_philo *philo);
void						philo_sleep(t_philo *philo);
void						philo_think(t_philo *philo);
void						print_error(char *err);
void						print_error_and_exit(char *err);
void						print_message(char *str, t_philo *philo, int id);

#endif

// vim: ts=4 sts=4 sw=4 noet
