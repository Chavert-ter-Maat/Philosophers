/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_threads.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/26 13:13:51 by chavertterm   #+#    #+#                 */
/*   Updated: 2023/09/28 14:14:32 by chavertterm   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int32_t create_threads(t_shared *shared)
{
	int	i;
	int	max_philos;
	int status;

	i = 0;
	max_philos = shared->args->nbr_philo;
	pthread_mutex_lock(&shared->start);
	while (i < max_philos)
	{
		status = pthread_create(shared->philo[i].thread_id, NULL, action_sequence, &shared->philo[i]);
		if (status != SUCCESS)
		{
			printf("error creating threads");
			exit(1);
			return (ERROR_THREAD);
		}
		i++;
	}
	pthread_mutex_unlock(&shared->start);
	return (SUCCESS);
}