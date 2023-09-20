/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_structs.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/18 14:39:05 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/09/20 16:04:24 by cter-maa      ########   odam.nl         */
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

int32_t allocate_main(t_main *main)
{
	int32_t index;

	index = 0;
	pthread_mutex_init(&(main->start), NULL);
	main->chops = malloc(sizeof(pthread_mutex_t) * (main->args->nbr_philo));
	if (!main->chops)
		return (ERROR_ALLOCATION);
	main->philo = malloc(sizeof(t_philo) * (main->args->nbr_philo));
	if (!main->philo)
		return (ERROR_ALLOCATION);
	while (index < main->args->nbr_philo)
	{
		pthread_mutex_init(&main->chops[index], NULL);
		if (init_philos(main, main->philo, index) != SUCCESS)
			return (ERROR_ALLOCATION); // free philo and chops!
		index++;
	}
	return (SUCCESS);
}
