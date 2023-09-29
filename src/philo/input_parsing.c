/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_parsing.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/06 11:03:57 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/09/29 13:14:36 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int32_t single_philo(t_args *args)
{
    (void)* args;
    
    printf("philo has died\n"); //adjust
    exit(EXIT_FAILURE); // check exit!!
}

void	print_args(t_args *args)
{
	printf("%i = nbr_philo\n", args->nbr_philo);
	printf("%i = time_die\n", args->time_die);
	printf("%i = time_eat\n", args->time_eat);
	printf("%i = time_sleep\n", args->time_sleep);
	printf("%i = max_meals\n", args->max_meals);
}

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
	if (args->nbr_philo < 1 || args->nbr_philo > 200 || args->time_die < 1 \
	 	|| args->time_eat < 1 || args->time_sleep < 1)
			return (ERROR_INPUT);
	if (args->nbr_philo == 1)
		return (single_philo(args));
	print_args(args);
	return (SUCCESS);
}
