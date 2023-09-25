/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_actions.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/20 13:21:44 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/09/25 16:22:03 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	go_eat(t_philo *philo)
{
	int32_t start_eat;

	start_eat = time_of_day_ms();
	pthread_mutex_lock(&philo->print_msg);
	printf(FORMAT, start_eat - philo->main->start_time, philo->id, "eating");
	pthread_mutex_unlock(&philo->print_msg);
	pthread_mutex_lock(&philo->main->chops[philo->left]);
	pthread_mutex_lock(&philo->main->chops[philo->right]);
	time_sleep(philo->args->time_eat);
	philo->time_last_eat = start_eat;
	philo->meals_eaten += 1;
	// usleep(philo->args->time_eat);
	// usleep(philo->args->time_eat);
	pthread_mutex_unlock(&philo->main->chops[philo->left]);
	pthread_mutex_unlock(&philo->main->chops[philo->right]);
	philo->status = SLEEP;
}

// void	go_eat(t_philo *philo)
// {
// 	int32_t start_eat;

// 	start_eat = time_of_day_ms();
// 	pthread_mutex_lock(&philo->print_msg);
// 	printf(FORMAT, start_eat - philo->main->start_time, philo->id,  "eating");
// 	pthread_mutex_unlock(&philo->print_msg);
// 	philo->status = SLEEP;
// }

void	go_sleep(t_philo *philo)
{
	int32_t	start_sleep;
	
	start_sleep = time_of_day_ms();
	pthread_mutex_lock(&philo->print_msg);
	printf(FORMAT, start_sleep - philo->main->start_time, philo->id,  "sleep");
	pthread_mutex_unlock(&philo->print_msg);
	philo->status = THINK;
}



void	go_think(t_philo *philo)
{
	int32_t start_think = time_of_day_ms();
	
	printf(FORMAT, start_think - philo->main->start_time, philo->id,  "thinking");
	philo->status = EAT;
}