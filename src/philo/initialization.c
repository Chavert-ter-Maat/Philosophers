/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialization.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/18 14:39:05 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/10/06 14:15:18 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

static void	init_philos(t_shared *shared, t_philo *philo, int32_t nbr)
{
	shared->philo = philo;
	philo->shared = shared;
	philo->args = shared->args;
	philo->id = nbr + 1;
	philo->right = nbr;
	philo->left = philo->id % philo->args->nbr_philo;
	philo->time_last_eat = get_time();
	philo->status = EATING;
}

int32_t	initialization(t_shared *shared, t_philo *philo)
{
	int32_t	index;

	index = 0;
	while (index < shared->args->nbr_philo)
	{
		init_philos(shared, &philo[index], index);
		index++;
	}
	return (SUCCESS);
}
