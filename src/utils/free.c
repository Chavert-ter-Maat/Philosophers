/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/20 11:02:14 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/10/03 11:09:24 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int32_t thread_join(t_philo *philo)
{
	int	index;

	index = 0;
	while (index < philo->args->nbr_philo)
	{
		if (pthread_join(*philo[index].thread_id, NULL) != SUCCESS)
			return (ERROR_THREAD);
		index++;
	}
	return (SUCCESS);
}

void	free_philos(t_philo *philo)
{
	int	index;

	index = philo->args->nbr_philo;

	while(index != 0)
	{
		free(&philo[index].thread_id);
		free(&philo[index]);
		index--;
	}
	
}

void	destroy_mutexes(t_shared *shared)
{
	if (&shared->print_msg)
		pthread_mutex_destroy(&shared->print_msg);
	if (&shared->eating)
		pthread_mutex_destroy(&shared->eating);
	if (&shared->eating)
		pthread_mutex_destroy(&shared->eating);
}

void	destroy_chops(t_shared *shared)
{
	int	index;

	index = 0;
	while (index < shared->args->nbr_philo)
	{
		pthread_mutex_destroy(&shared->chops[index]);
		index++;
	}
}

void	free_and_destroy(t_shared *shared)
{
	destroy_mutexes(shared);
	destroy_chops(shared);
	free_philos(shared->philo);
}
