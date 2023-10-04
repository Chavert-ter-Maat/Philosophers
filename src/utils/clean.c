/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   clean.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/20 11:02:14 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/10/04 15:15:54 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int32_t	thread_join(t_philo *philo)
{
	int	index;

	index = 0;
	while (index < philo->args->nbr_philo)
	{
		if (pthread_join(philo[index].thread_id, NULL) != SUCCESS)
			return (ERROR_THREAD);
		index++;
	}
	return (SUCCESS);
}

int32_t	destroy_mutex(t_shared *shared, int32_t status)
{
	if (&shared->time != NULL)
	if (pthread_mutex_destroy(&shared->time) != SUCCESS)
	{
		ph_putstr_fd(STDERR_FILENO, "mutex destruction failed");
		return (ERROR_MUTEX);
	}
	if (pthread_mutex_destroy(&shared->eating) != SUCCESS)
	{
		ph_putstr_fd(STDERR_FILENO, "mutex destruction failed");
		return (ERROR_MUTEX);
	}
	if (pthread_mutex_destroy(&shared->start) != SUCCESS)
	{
		ph_putstr_fd(STDERR_FILENO, "mutex destruction failed");
		return (ERROR_MUTEX);
	}
	return (status);
}
