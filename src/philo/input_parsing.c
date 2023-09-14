/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_parsing.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/06 11:03:57 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/09/14 14:03:26 by chavertterm   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

static int32_t allocate_node(t_philo *philo, t_args *args, \
pthread_mutex_t *chops, int32_t nbr)
{
	philo->id = nbr + 1;
	philo->thread = malloc(sizeof(pthread_t));
	if(!philo->thread)
		return(ERROR_ALLOCATION);
	philo->time_last_eat = get_time_ms();
	
	philo->status = EAT;
	pthread_mutex_init(&philo->eating, NULL);
	philo->chops_r = &chops[nbr];
	pthread_mutex_init(&chops[nbr], NULL);
	philo->chops_l = &chops[nbr + 1];
	philo->args = args;
	return (SUCCESS);
}

int32_t join_thread()
{
	
}

int32_t allocate_philo_struct(t_args *args, t_philo **philo)
{
	pthread_mutex_t	*chops;
	int32_t index;
	
	index = 0;
	chops = malloc(sizeof(pthread_mutex_t) * args->nbr_philo);
	if (!chops)
		return (ERROR_ALLOCATION);
	philo = malloc(sizeof(t_philo) * (args->nbr_philo));
	if (!philo)
	{
		free(chops);
		return (ERROR_ALLOCATION);
	}
	while (index < args->nbr_philo)
	{
		if (allocate_node(&philo[index], args, chops, index) != SUCCESS);
			return(ERROR_ALLOCATION); // free philo and chops!
		index++;
	}
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
		return (INPUT_ERROR);
	return (SUCCESS);
}
