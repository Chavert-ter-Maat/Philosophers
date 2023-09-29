/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialization.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/18 14:39:05 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/09/29 13:52:26 by cter-maa      ########   odam.nl         */
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
	philo->thread_id = malloc(sizeof(pthread_t));
	if(!philo->thread_id)
		return(ERROR_ALLOCATION);
	philo->time_last_eat = get_time();
	philo->status = EATING;
	return (SUCCESS);
}

static void	init_shared(t_shared *shared)
{
	int32_t	index;
	int32_t	max_philos;

	index = 0;
	max_philos = shared->args->nbr_philo;
	shared->nbr_full_philo = 0;
	shared->start_time = get_time();
	pthread_mutex_init(&(shared->print_msg), NULL);
	pthread_mutex_init(&(shared->eating), NULL);
	pthread_mutex_init(&(shared->start), NULL);
	while (index < max_philos)
	{
		pthread_mutex_init(&shared->chops[index], NULL);
		index++;
	}
}

int32_t initialization(t_shared *shared, t_philo **philo)
{
	int32_t	index;
	int32_t	max_philos;

	index = 0;
	max_philos = shared->args->nbr_philo;
	shared->chops = malloc(sizeof(pthread_mutex_t) * (shared->args->nbr_philo));
	if (!shared->chops)
		return (ERROR_ALLOCATION);
	*philo = malloc(sizeof(t_philo) * (shared->args->nbr_philo));
	if (!philo)
		return (ERROR_ALLOCATION);
	init_shared(shared);
	while (index < max_philos)
	{
		if (init_philos(shared, &philo[0][index], index) != SUCCESS)
			return (ERROR_ALLOCATION);
		index++;
	}
	return (SUCCESS);
}
