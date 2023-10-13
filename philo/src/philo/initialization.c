/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialization.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/18 14:39:05 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/10/13 12:08:12 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

static void	init_philos(t_shared *shared, t_philo *philo, int32_t nbr)
{
	ph_bzero(philo, sizeof(philo));
	shared->philo = philo;
	philo->shared = shared;
	philo->meals_eaten = 0;
	philo->general = shared->general;
	philo->id = nbr + 1;
	philo->right = nbr;
	philo->left = philo->id % philo->general->nbr_philo;
	philo->time_last_eat = get_time();
	philo->status = EATING;
}

static int32_t	init_chops(t_shared *shared)
{
	while (shared->general->inited_chops < shared->general->nbr_philo)
	{
		if (pthread_mutex_init(&shared->chops[shared->general->inited_chops], \
			NULL) != SUCCESS)
		{
			ph_putstr_fd(STDERR_FILENO, "'chops' mutex init failed");
			destroy_mutex(shared, ERROR_ALLOCATION);
			return (ERROR_ALLOCATION);
		}
		shared->general->inited_chops++;
	}
	return (SUCCESS);
}

static int32_t	init_mutexes(t_shared *shared)
{
	ph_bzero(shared, sizeof(shared));
	if (pthread_mutex_init(&(shared->observer), NULL) != SUCCESS)
		return (ERROR_ALLOCATION);
	if (pthread_mutex_init(&(shared->start), NULL) != SUCCESS)
	{
		ph_putstr_fd(STDERR_FILENO, "'start' mutex init failed");
		pthread_mutex_destroy(&(shared->observer));
		return (ERROR_ALLOCATION);
	}
	if (pthread_mutex_init(&(shared->print), NULL) != SUCCESS)
	{
		ph_putstr_fd(STDERR_FILENO, "'print' mutex init failed");
		pthread_mutex_destroy(&(shared->observer));
		pthread_mutex_destroy(&(shared->start));
		return (ERROR_ALLOCATION);
	}
	if (init_chops(shared) != SUCCESS)
		return (ERROR_ALLOCATION);
	return (SUCCESS);
}

int32_t	initialization(t_shared *shared, t_philo *philo)
{
	int32_t	index;

	index = 0;
	if (init_mutexes(shared) != SUCCESS)
		return (ERROR_ALLOCATION);
	while (index < shared->general->nbr_philo)
	{
		init_philos(shared, &philo[index], index);
		index++;
	}
	return (SUCCESS);
}
