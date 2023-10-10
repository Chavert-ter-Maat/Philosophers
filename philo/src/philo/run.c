/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   run.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/26 13:13:51 by chavertterm   #+#    #+#                 */
/*   Updated: 2023/10/09 11:41:03 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

static void	function_because_norminette(t_philo *philo)
{
	while (1)
	{
		if (go_eat(philo) == SIM_STOP)
			return ;
		if (go_sleep(philo) == SIM_STOP)
			return ;
		if (go_think(philo) == SIM_STOP)
			return ;
	}
	return ;
}

static void	*action_sequence(void *arg)
{
	uint64_t	start_time;
	t_philo		*philo;

	philo = (t_philo *) arg;
	pthread_mutex_lock(&philo->shared->start);
	start_time = philo->shared->start_time;
	pthread_mutex_unlock(&philo->shared->start);
	pthread_mutex_lock(&philo->shared->observer);
	philo->time_last_eat = start_time;
	pthread_mutex_unlock(&philo->shared->observer);
	if ((philo->id % 2) == 1)
	{
		if (go_think(philo) == SIM_STOP)
			return (NULL);
		sleep_function(philo->general->time_eat / 2);
	}
	function_because_norminette(philo);
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
	shared->start_time = get_time();
	pthread_mutex_unlock(&shared->start);
	return (SUCCESS);
}
