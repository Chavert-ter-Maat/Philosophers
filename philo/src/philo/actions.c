/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   actions.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/20 13:21:44 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/10/13 12:17:27 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

static void	put_down_chops(t_philo *philo, int amount_chops)
{
	if (amount_chops == 1)
		pthread_mutex_unlock(&philo->shared->chops[philo->left]);
	if (amount_chops == 2)
	{
		pthread_mutex_unlock(&philo->shared->chops[philo->right]);
		pthread_mutex_unlock(&philo->shared->chops[philo->left]);
	}
}

static int32_t	chop_and_down(t_philo *philo)
{
	pthread_mutex_lock(&philo->shared->chops[philo->left]);
	if (print_action(philo, CHOP) == SIM_STOP)
	{
		put_down_chops(philo, 1);
		return (SIM_STOP);
	}
	pthread_mutex_lock(&philo->shared->chops[philo->right]);
	if (print_action(philo, CHOP) == SIM_STOP)
	{
		put_down_chops(philo, 2);
		return (SIM_STOP);
	}
	if (print_action(philo, EATING) == SIM_STOP)
	{
		put_down_chops(philo, 2);
		return (SIM_STOP);
	}
	return (SUCCESS);
}

uint32_t	go_eat(t_philo *philo)
{
	
	if (chop_and_down(philo) == SIM_STOP)
		return (SIM_STOP);
	if (sleep_function(philo, philo->general->time_eat) \
		== SIM_STOP)
		{
			put_down_chops(philo, 2);
			return (SIM_STOP);
		}
	pthread_mutex_lock(&philo->shared->observer);
	philo->time_last_eat = get_time();
	pthread_mutex_unlock(&philo->shared->observer);
	philo->meals_eaten += 1;
	put_down_chops(philo, 2);
	if (philo->status != FULL)
		philo->status = SLEEPING;
	check_full(philo);
	return (SUCCESS);
}

uint32_t	go_sleep(t_philo *philo)
{
	if (print_action(philo, SLEEPING) == SIM_STOP)
		return (SIM_STOP);
	if (sleep_function(philo, philo->general->time_sleep) \
		== SIM_STOP)
			return (SIM_STOP);
	if (philo->status != FULL)
		philo->status = THINKING;
	return (SUCCESS);
}

uint32_t	go_think(t_philo *philo)
{
	if (print_action(philo, THINKING) == SIM_STOP)
		return (SIM_STOP);
	if (philo->status != FULL)
		philo->status = EATING;
	return (SUCCESS);
}
