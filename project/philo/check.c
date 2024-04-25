/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcapistr <jcapistr@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 14:20:16 by jcapistr          #+#    #+#             */
/*   Updated: 2024/04/25 10:42:44 by jcapistr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	is_valid_number(char *str)
{
	if (*str == '\0')
		return (0);
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

void	check_args(int argc, char **argv)
{
	int	i;

	if (argc != 5 && argc != 6)
		print_error_and_exit("Invalid number of arguments.");
	i = 1;
	while (i < argc)
	{
		if (i < 5 && (!is_valid_number(argv[i]) || ft_atoi(argv[i]) <= 0))
			print_error_and_exit("One or more arguments are invalid.");
		else if (i < 6 && (!is_valid_number(argv[i]) || ft_atoi(argv[i]) < 0))
			print_error_and_exit("Last argument is invalid.");
		i++;
	}
	if (ft_atoi(argv[1]) > MAX_NUM_PHILOS)
		print_error_and_exit("Invalid number of philosophers.");
}

// vim: ts=4 sts=4 sw=4 noet
