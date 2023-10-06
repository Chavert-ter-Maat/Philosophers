/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   clean.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/20 11:02:14 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/10/06 14:14:46 by cter-maa      ########   odam.nl         */
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

