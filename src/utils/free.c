/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/20 11:02:14 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/10/02 17:16:33 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int32_t free_philos(t_philo *philo)
{
	int	index;

	index = 0;
	while (index < philo->args->nbr_philo)
	{
		if (pthread_join(*philo[index].thread_id, NULL) != SUCCESS)
			return (ERROR_THREAD);
		free(philo[index].thread_id);
		index++;
	}
	return (SUCCESS);
}

void	destroy_mutexes(t_shared *shared)
{
	if (&shared->print_msg)
		if (pthread_mutex_destroy(&shared->print_msg) != SUCCESS)
		{
			perror("mutex desruction failed");
			return ;
		}	
	if (&shared->eating)
		if (pthread_mutex_destroy(&shared->eating) != SUCCESS)
		{
			perror("mutex desruction failed");
			return ;
		}
	if (&shared->eating)
		if (pthread_mutex_destroy(&shared->eating) != SUCCESS)
		{
			perror("mutex desruction failed");
			return ;
		}	
}

void	destroy_chops(t_shared *shared)
{
	int	index;

	index = 0;
	while (index <= shared->args->nbr_philo)
	{
		phtread_mutex_destroy(&shared->chops[index]);
		index++;
	}
}

int	ph_free(t_shared *shared)
{
	destroy_mutexes(shared);
	destroy_chops(shared);
}
