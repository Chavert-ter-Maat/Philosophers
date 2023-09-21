/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_structs.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/18 14:39:05 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/09/21 14:24:40 by chavertterm   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

static int32_t init_philos(t_main *main, t_philo *philo, int32_t nbr)
{
	philo->id = nbr + 1;
	philo->thread_id = malloc(sizeof(pthread_t));
	if(!philo->thread_id)
		return(ERROR_ALLOCATION);
	philo->time_last_eat = 0;
	philo->status = EAT;
	philo->main = main;
	philo->args = main->args;
	pthread_mutex_init(&(philo->print_msg), NULL);
	return (SUCCESS);
}

static void	init_mutexes(t_main *main)
{
	int32_t	index;
	int32_t	max_philos;

	index = 0;
	max_philos = main->args->nbr_philo;
	pthread_mutex_init(&(main->start), NULL);
	while (index < max_philos)
	{
		pthread_mutex_init(&main->chops[index], NULL);
		index++;
	}
}

int32_t init_philo(t_main *main, t_philo **philo)
{
	int32_t	index;
	int32_t	max_philos;

	index = 0;
	max_philos = main->args->nbr_philo;
	main->chops = malloc(sizeof(pthread_mutex_t) * (main->args->nbr_philo));
	if (!main->chops)
		return (ERROR_ALLOCATION);
	*philo = malloc(sizeof(t_philo) * (main->args->nbr_philo));
	if (!philo)
		return (ERROR_ALLOCATION);
	init_mutexes(main);
	while (index < max_philos)
	{
		if (init_philos(main, &philo[0][index], index) != SUCCESS)
			return (ERROR_ALLOCATION);
		index++;
	}
	init_mutexes(main);
	return (SUCCESS);
}
