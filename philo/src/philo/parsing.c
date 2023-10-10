/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/06 11:03:57 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/10/10 14:16:35 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int32_t	argument_parsing(t_general *general, char **argv)
{
	ph_bzero(general, sizeof(general));
	general->nbr_philo = ph_atoi(argv[1]);
	general->time_die = ph_atoi(argv[2]);
	general->time_eat = ph_atoi(argv[3]);
	general->time_sleep = ph_atoi(argv[4]);
	general->inited_chops = 0;
	general->inited_threads = 0;
	if (argv[5])
		general->max_meals = ph_atoi(argv[5]);
	if (!argv[5])
		general->max_meals = -1;
	if (general->max_meals == 0)
		return (ERROR_INPUT);
	if (general->nbr_philo == 1)
		return (SINGLE_PHILO);
	if (general->nbr_philo > INT_MAX || general->time_die > INT_MAX || \
		general->time_eat > INT_MAX || general->time_sleep > INT_MAX)
		return (ERROR_INPUT);
	if (general->nbr_philo < 1 || general->nbr_philo > 200 || \
		general->time_die < 1 || general->time_eat < 1 || \
		general->time_sleep < 1)
		return (ERROR_INPUT);
	return (SUCCESS);
}
