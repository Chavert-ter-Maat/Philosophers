/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/03 13:58:59 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/10/13 12:18:08 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

static int32_t	check_all_full(t_philo *philo)
{
	int	nbr_full_philo;

	pthread_mutex_lock(&philo->shared->observer);
	nbr_full_philo = philo->shared->nbr_full_philo;
	pthread_mutex_unlock(&philo->shared->observer);
	if (nbr_full_philo == philo->general->nbr_philo)
	{
		pthread_mutex_lock(&philo->shared->observer);
		philo->shared->status = FULL;
		pthread_mutex_unlock(&philo->shared->observer);
		return (FULL);
	}
	return (0);
}

static void	print_died(t_philo *philo, int32_t index)
{
	usleep(4000);
	pthread_mutex_lock(&philo->shared->print);
	printf(FORMAT, get_time() - philo->shared->start_time, \
		philo[index].id, "has died");
	pthread_mutex_unlock(&philo->shared->print);
}

uint32_t	check_runner(t_philo *philo)
{
	int32_t		index;
	uint64_t	time_difference;

	index = 0;
	while (1)
	{
		pthread_mutex_lock(&philo->shared->observer);
		time_difference = get_time() - philo[index].time_last_eat;
		pthread_mutex_unlock(&philo->shared->observer);
		if (time_difference > philo->general->time_die)
		{
			pthread_mutex_lock(&philo->shared->observer);
			philo->shared->status = DIED;
			pthread_mutex_unlock(&philo->shared->observer);
			print_died(philo, index);
			return (SIM_STOP);
		}
		if (check_all_full(philo) == FULL)
			return (SIM_STOP);
		index++;
		if (index == philo->general->nbr_philo - 1)
			index = 0;
	}
}

void	check_full(t_philo *philo)
{
	pthread_mutex_lock(&philo->shared->observer);
	if (philo->meals_eaten == philo->general->max_meals \
		&& philo->status != FULL)
	{
		philo->shared->nbr_full_philo += 1;
		philo->status = FULL;
	}
	pthread_mutex_unlock(&philo->shared->observer);
}

uint32_t	check_state(t_philo *philo)
{
	uint32_t	status;

	pthread_mutex_lock(&philo->shared->observer);
	status = philo->shared->status;
	pthread_mutex_unlock(&philo->shared->observer);
	if (status == DIED || status == FULL)
		return (SIM_STOP);
	return (SUCCESS);
}
