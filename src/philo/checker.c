/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 13:58:59 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/10/03 14:52:54 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

uint32_t	check_state_philo(t_philo *philo)
{
	int		index;
	uint64_t	time_difference;

	index = 0;
	while (1)
	{
		pthread_mutex_lock(&philo->shared->eating);
		time_difference = get_time() - philo[index].time_last_eat;
		pthread_mutex_unlock(&philo->shared->eating);
		if (time_difference > philo->args->time_die)
		{
			philo->status = DIED;
			pthread_mutex_lock(&philo->shared->death);
			philo->shared->status = DIED;
			pthread_mutex_unlock(&philo->shared->death);
			print_action(philo, DIED);
			return (SIM_STOP);
			}
		// lock
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
	uint64_t	time_difference;
	
	pthread_mutex_lock(&philo->shared->eating);
		time_difference = get_time() - philo->time_last_eat;
	pthread_mutex_unlock(&philo->shared->eating);
	if (time_difference > philo->args->time_die)
	{
			print_action(philo, DIED);
			return (SIM_STOP);
	}
	pthread_mutex_lock(&philo->shared->death);
	if (philo->shared->status == DIED)
	{
		print_action(philo, DIED);
		return (DIED);
	}
	pthread_mutex_unlock(&philo->shared->death);
	return (SUCCESS);
}