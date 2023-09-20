/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_actions.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/20 13:21:44 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/09/20 14:05:49 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	go_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->print_msg);
	philo->status = EAT;
	printf("status = EAT \n");
	pthread_mutex_unlock(&philo->print_msg);
}

void	go_sleep(t_philo *philo)
{
	pthread_mutex_lock(&philo->print_msg);
	philo->status = SLEEP;
	printf("status = THINK \n");
	pthread_mutex_unlock(&philo->print_msg);
}

void	go_think(t_philo *philo)
{
	pthread_mutex_lock(&philo->print_msg);
	philo->status = THINK;
	printf("status = THINK \n");
	pthread_mutex_unlock(&philo->print_msg);
}