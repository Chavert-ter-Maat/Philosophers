/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialization.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/18 14:39:05 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/10/03 14:12:06 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

static int32_t init_philos(t_shared *shared, t_philo *philo, int32_t nbr)
{
	philo->shared = shared;
	philo->args = shared->args;
	philo->id = nbr + 1;
	philo->right = nbr;
	philo->left = philo->id % philo->args->nbr_philo;
	// philo->thread_id = malloc(sizeof(pthread_t));
	// if(!philo->thread_id)
	// 	return(ERROR_ALLOCATION);
	philo->time_last_eat = get_time();
	philo->status = EATING;
	return (SUCCESS);
}

static int	init_shared(t_shared *shared)
{
	int32_t	index;

	index = 0;
	shared->nbr_full_philo = 0;
	if (pthread_mutex_init(&(shared->print_msg), NULL) != SUCCESS)
		{
			// ph_free(shared);
			return (ERROR_ALLOCATION);
		}
	if (pthread_mutex_init(&(shared->eating), NULL) != SUCCESS)
			{
			// ph_free(shared);
			return (ERROR_ALLOCATION);
		}
	if (pthread_mutex_init(&(shared->start), NULL) != SUCCESS)
		{
			// ph_free(shared);
			return (ERROR_ALLOCATION);
		}
	if (pthread_mutex_init(&(shared->death), NULL) != SUCCESS)
		{
			// ph_free(shared);
			return (ERROR_ALLOCATION);
		}
	while (index < shared->args->nbr_philo)
	{
		pthread_mutex_init(&shared->chops[index], NULL);
		index++;
	}
	return (SUCCESS);
}

int32_t initialization(t_shared *shared, t_philo *philo)
{
	int32_t	index;

	index = 0;
	// shared->chops = malloc(sizeof(pthread_mutex_t) * (shared->args->nbr_philo));
	// if (!shared->chops)
	// 	return (ERROR_ALLOCATION);
	// *philo = malloc(sizeof(t_philo) * (shared->args->nbr_philo));
	// if (!philo)
	// 	return (ERROR_ALLOCATION);
	init_shared(shared);
	while (index < shared->args->nbr_philo)
	{
		if (init_philos(shared, &philo[index], index) != SUCCESS)
			return (ERROR_ALLOCATION);
		index++;
	}
	return (SUCCESS);
}
