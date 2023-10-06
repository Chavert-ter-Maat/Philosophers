/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/06 11:03:57 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/10/05 13:34:47 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int32_t	argument_parsing(t_args *args, char **argv)
{
	ph_bzero(args, sizeof(args));
	args->nbr_philo = ph_atoi(argv[1]);
	args->time_die = ph_atoi(argv[2]);
	args->time_eat = ph_atoi(argv[3]);
	args->time_sleep = ph_atoi(argv[4]);
	if (argv[5])
		args->max_meals = ph_atoi(argv[5]);
	else
		args->max_meals = -1;
	if (args->nbr_philo == 1)
		return (SINGLE_PHILO);
	if (args->nbr_philo > INT_MAX || args->time_die > INT_MAX || \
		args->time_eat > INT_MAX || args->time_sleep > INT_MAX)
		return (ERROR_INPUT);
	if (args->nbr_philo < 1 || args->nbr_philo > 200 || args->time_die < 1 \
		|| args->time_eat < 1 || args->time_sleep < 1)
		return (ERROR_INPUT);
	return (SUCCESS);
}
