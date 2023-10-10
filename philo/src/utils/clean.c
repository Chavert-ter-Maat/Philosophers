/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   clean.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/20 11:02:14 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/10/09 10:54:47 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int32_t	thread_join(t_philo *philo)
{
	int	index;

	index = 0;
	while (index < philo->general->inited_threads)
	{
		if (pthread_join(philo[index].thread_id, NULL) != SUCCESS)
		{
			ph_putstr_fd(STDERR_FILENO, "thread join failed");
			return (ERROR_THREAD);
		}
		index++;
	}
	return (SUCCESS);
}

int32_t	destroy_chops(t_shared *shared)
{
	int32_t	index;

	index = 0;
	while (index < shared->general->inited_chops)
	{
		if (pthread_mutex_destroy(&shared->chops[index]) != SUCCESS)
		{
			ph_putstr_fd(STDERR_FILENO, "'chop' mutex destruction failed");
			return (ERROR_MUTEX);
		}
		index++;
	}
	return (SUCCESS);
}

int32_t	destroy_mutex(t_shared *shared, int32_t status)
{
	if (destroy_chops(shared) != SUCCESS)
		return (ERROR_MUTEX);
	if (pthread_mutex_destroy(&shared->observer) != SUCCESS)
	{
		ph_putstr_fd(STDERR_FILENO, "'time' mutex destruction failed");
		return (ERROR_MUTEX);
	}
	if (pthread_mutex_destroy(&shared->start) != SUCCESS)
	{
		ph_putstr_fd(STDERR_FILENO, "'start' mutex destruction failed");
		return (ERROR_MUTEX);
	}
	if (pthread_mutex_destroy(&shared->print) != SUCCESS)
	{
		ph_putstr_fd(STDERR_FILENO, "'print' mutex destruction failed");
		return (ERROR_MUTEX);
	}
	return (status);
}
