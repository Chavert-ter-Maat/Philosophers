/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_actions.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/20 13:21:44 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/09/22 15:36:02 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	go_eat(t_philo *philo)
{
	int32_t start_eat;

	start_eat = time_of_day_ms();
	pthread_mutex_lock(&philo->print_msg);
	printf(FORMAT, start_eat,philo->id,  "eating");
	pthread_mutex_unlock(&philo->print_msg);
	philo->status = SLEEP;
}

void	go_sleep(t_philo *philo)
{
	int32_t	start_sleep;
	
	start_sleep = time_of_day_ms();
	pthread_mutex_lock(&philo->print_msg);
	printf(FORMAT, philo->id, start_sleep, "sleep");
	pthread_mutex_unlock(&philo->print_msg);
	philo->status = THINK;
}

void	go_think(t_philo *philo)
{
	int32_t start_think = time_of_day_ms();
	
	printf(FORMAT, philo->id, start_think, "thinking");
	philo->status = EAT;
}