/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_structs.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/18 14:39:05 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/09/19 12:02:18 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

static int32_t init_philos(t_main *main, t_philo *philos, int32_t nbr)
{
	philos->id = nbr + 1;
	philos->thread = malloc(sizeof(pthread_t));
	if(!philos->thread)
		return(ERROR_ALLOCATION);
	philos->time_last_eat = 0;
	philos->status = EAT;
	philos->main = main;
	return (SUCCESS);
}

int32_t allocate_main(t_main *main)
{
	pthread_mutex_t	*chops;
	int32_t index;

	index = 0;
	chops = malloc(sizeof(pthread_mutex_t) * (main->args->nbr_philo));
	if (!chops)
		return (ERROR_ALLOCATION);
	main->philo = malloc(sizeof(main->philo) * (main->args->nbr_philo));
	pthread_mutex_init(&(main->start), NULL);
	if (!main->philo)
	{
		free(chops);
		return (ERROR_ALLOCATION);
	}
	while (index < main->args->nbr_philo)
	{
		pthread_mutex_init(&chops[index], NULL);
		if (init_philos(main, main->philo, index) != SUCCESS)
			return (ERROR_ALLOCATION); // free philo and chops!
		index++;
	}
	main->chops = chops;
	return (SUCCESS);
}
