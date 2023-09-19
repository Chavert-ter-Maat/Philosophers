/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_parsing.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/06 11:03:57 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/09/18 16:22:18 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int32_t single_philo(t_args *args)
{
    (void)* args;
    
    printf("single philo has died"); //adjust
    return (SUCCESS);
}

int32_t	argument_parsing(t_args *args, char **argv)
{
	ph_bzero(args, sizeof(args));
	args->nbr_philo = ph_atoi(argv[1]);
	args->time_die = ph_atoi(argv[2]);
	args->time_eat = ph_atoi(argv[3]);
	args->time_sleep = ph_atoi(argv[4]);
	if (argv[5])
		args->nbr_meal = ph_atoi(argv[5]);
	else
		args->nbr_meal = -1;
	if (args->nbr_philo < 1 || args->nbr_philo > 200 || args->time_die < 1 \
	 	|| args->time_eat < 1 || args->time_sleep < 1 \
		|| (argv[4] && args->nbr_meal < 1))
		return (error_message(INPUT_ERROR));
	if (args->nbr_philo == 1)
		return (single_philo(args));
	return (SUCCESS);
}
