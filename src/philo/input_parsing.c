/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_parsing.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/06 11:03:57 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/09/07 16:26:56 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int32_t	input_parsing(t_philo *ph, char **argv)
{
	ph_bzero(ph, sizeof(ph));
	ph->nbr_philo = ph_atoi(argv[1]);
	ph->time_die = ph_atoi(argv[2]);
	ph->time_eat = ph_atoi(argv[3]);
	ph->time_sleep = ph_atoi(argv[4]);
	if (argv[5])
		ph->nbr_meal = ph_atoi(argv[5]);
	else
		ph->nbr_meal = -1;
	
	printf("%i\n", ph->nbr_philo);
	printf("%i\n", ph->time_die);
	printf("%i\n", ph->time_eat);
	printf("%i\n", ph->time_sleep);
	printf("%i\n", ph->nbr_meal);
	return (SUCCESS);
}
