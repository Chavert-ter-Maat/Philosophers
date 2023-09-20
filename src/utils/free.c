/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/20 11:02:14 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/09/20 14:33:29 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int32_t philo_thread_join(t_philo *philo)
{
	int	index;

	index = 0;
	while (index < philo->args->nbr_philo)
	{
		if (pthread_join(*philo[index].thread_id, NULL) != SUCCESS)
			return (ERROR_THREAD);
		index++;
	}
	return (SUCCESS);
}