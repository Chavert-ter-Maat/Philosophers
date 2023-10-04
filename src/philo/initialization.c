/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialization.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/18 14:39:05 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/10/04 15:48:10 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

static void	init_philos(t_shared *shared, t_philo *philo, int32_t nbr)
{
	philo->shared = shared;
	philo->args = shared->args;
	philo->id = nbr + 1;
	philo->right = nbr;
	philo->left = philo->id % philo->args->nbr_philo;
	philo->time_last_eat = get_time();
	philo->status = EATING;
}

static int	init_shared(t_shared *shared)
{
	if (pthread_mutex_init(&(shared->time), NULL) != SUCCESS)
		return (ERROR_ALLOCATION);
	if (pthread_mutex_init(&(shared->start), NULL) != SUCCESS)
	{
		pthread_mutex_destroy(&(shared->time));
		return (ERROR_ALLOCATION);
	}
	if (pthread_mutex_init(&(shared->status_mutex), NULL) != SUCCESS)
	{
		pthread_mutex_destroy(&(shared->time));
		pthread_mutex_destroy(&(shared->start));
		return (ERROR_ALLOCATION);
	}
	return (SUCCESS);
}

int32_t	initialization(t_shared *shared, t_philo *philo)
{
	int32_t	index;

	index = 0;
	if (init_shared(shared) != SUCCESS)
		return (ERROR_ALLOCATION);
	while (index < shared->args->nbr_philo)
	{
		init_philos(shared, &philo[index], index);
		index++;
	}
	return (SUCCESS);
}
