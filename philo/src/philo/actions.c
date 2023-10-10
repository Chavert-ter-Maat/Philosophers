/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   actions.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/20 13:21:44 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/10/10 13:59:27 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

static void	check_meals_eaten(t_philo *philo)
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

uint32_t	go_eat(t_philo *philo)
{
	if (check_state(philo) == SIM_STOP)
		return (SIM_STOP);
	pthread_mutex_lock(&philo->shared->chops[philo->left]);
	pthread_mutex_lock(&philo->shared->chops[philo->right]);
	if (check_state(philo) == SIM_STOP)
	{
		pthread_mutex_unlock(&philo->shared->chops[philo->left]);
		pthread_mutex_unlock(&philo->shared->chops[philo->right]);
		return (SIM_STOP);
	}
	print_action(philo, CHOP);
	print_action(philo, CHOP);
	print_action(philo, EATING);
	pthread_mutex_lock(&philo->shared->observer);
	philo->time_last_eat = get_time();
	pthread_mutex_unlock(&philo->shared->observer);
	sleep_function(philo->general->time_eat);
	philo->meals_eaten += 1;
	pthread_mutex_unlock(&philo->shared->chops[philo->left]);
	pthread_mutex_unlock(&philo->shared->chops[philo->right]);
	if (philo->status != FULL)
		philo->status = SLEEPING;
	check_meals_eaten(philo);
	return (SUCCESS);
}

uint32_t	go_sleep(t_philo *philo)
{
	if (check_state(philo) == SIM_STOP)
		return (SIM_STOP);
	print_action(philo, SLEEPING);
	sleep_function(philo->general->time_sleep);
	if (philo->status != FULL)
		philo->status = THINKING;
	return (SUCCESS);
}

uint32_t	go_think(t_philo *philo)
{
	if (check_state(philo) == SIM_STOP)
		return (SIM_STOP);
	print_action(philo, THINKING);
	if (philo->status != FULL)
		philo->status = EATING;
	return (SUCCESS);
}
