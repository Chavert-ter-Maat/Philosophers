/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   run.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/26 13:13:51 by chavertterm   #+#    #+#                 */
/*   Updated: 2023/10/13 11:48:36 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

static void	*action_sequence(void *arg)
{
	t_philo		*philo;

	philo = (t_philo *) arg;
	pthread_mutex_lock(&philo->shared->start);
	philo->shared->start_time = get_time();
	pthread_mutex_unlock(&philo->shared->start);
	pthread_mutex_lock(&philo->shared->observer);
	philo->time_last_eat = get_time();
	pthread_mutex_unlock(&philo->shared->observer);
	if ((philo->id % 2) == 1)
	{
		if (go_think(philo) == SIM_STOP)
			return (NULL);
		sleep_function(philo, philo->general->time_eat / 2);
	}
	while (1)
	{
		if (go_eat(philo) == SIM_STOP)
			return NULL;
		if (go_sleep(philo) == SIM_STOP)
			return NULL;
		if (go_think(philo) == SIM_STOP)
			return NULL;
	}
	return (NULL);
}

int32_t	create_threads(t_shared *shared)
{
	int	index;
	int	status;

	index = 0;
	pthread_mutex_lock(&shared->start);
	while (index < shared->general->nbr_philo)
	{
		status = pthread_create(&(shared->philo[index].thread_id), NULL, \
		action_sequence, &shared->philo[index]);
		if (status != SUCCESS)
			return (ERROR_THREAD);
		index++;
		shared->general->inited_threads = index;
	}
	pthread_mutex_unlock(&shared->start);
	return (SUCCESS);
}
