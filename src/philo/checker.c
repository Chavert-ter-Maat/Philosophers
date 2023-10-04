/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 13:58:59 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/10/04 13:08:40 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

uint32_t	check_state_philo(t_philo *philo)
{
	int			index;
	uint64_t	time_difference;

	index = 0;
	while (1)
	{
		pthread_mutex_lock(&philo->shared->time);
		time_difference = get_time() - philo[index].time_last_eat;
		pthread_mutex_unlock(&philo->shared->time);
		if (time_difference > philo->args->time_die)
		{

			pthread_mutex_lock(&philo->shared->status_mutex);
			philo->shared->status = DIED;
			pthread_mutex_unlock(&philo->shared->status_mutex);
			print_action(&philo[index], DIED);
			return (SIM_STOP);
		}
		if (philo->shared->nbr_full_philo == philo->args->nbr_philo)
		{
			print_action(philo, FULL);
			return (SIM_STOP);
		}
		index++;
		if (index == philo->args->nbr_philo - 1)
			index = 0;
	}
}

uint32_t	check_death(t_philo *philo)
{
	pthread_mutex_lock(&philo->shared->status_mutex);
	if (philo->shared->status == DIED)
		return (DIED);
	pthread_mutex_unlock(&philo->shared->status_mutex);
	return (SUCCESS);
}