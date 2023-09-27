/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   action_sequence.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/20 13:21:44 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/09/27 16:10:48 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

static void	check_meals_eaten(t_philo *philo)
{
	int32_t	current_meals_eaten;
	int32_t	max_meals;

	current_meals_eaten = philo->meals_eaten;
	pthread_mutex_lock(&philo->shared->start);
	max_meals = philo->args->max_meals;
	if (current_meals_eaten == max_meals)
		philo->shared->nbr_full_philo += 1;
	pthread_mutex_unlock(&philo->shared->start);
}

void	go_eat(t_philo *philo)
{
	// int32_t start_eat;
	
	pthread_mutex_lock(&philo->shared->chops[philo->right]);
	//has taken fork
	pthread_mutex_lock(&philo->shared->chops[philo->left]);
	//has taken fork
	pthread_mutex_lock(&philo->shared->print_msg);
	printf(FORMAT, time_of_day_ms() - philo->start_time, philo->id, "eating");
	pthread_mutex_unlock(&philo->shared->print_msg);
	sleep_function(philo->args->time_eat);
	philo->meals_eaten += 1;
	pthread_mutex_unlock(&philo->shared->chops[philo->left]);
	pthread_mutex_unlock(&philo->shared->chops[philo->right]);
	pthread_mutex_lock(&philo->shared->eating);
	philo->time_last_eat = time_of_day_ms();
	pthread_mutex_unlock(&philo->shared->eating);
	philo->status = SLEEP;
	check_meals_eaten(philo);
}

void	go_sleep(t_philo *philo)
{
	const int32_t	start_sleep = time_of_day_ms();

	pthread_mutex_lock(&philo->shared->print_msg);
	printf(FORMAT, start_sleep - philo->start_time, philo->id,  "sleep");
	pthread_mutex_unlock(&philo->shared->print_msg);
	sleep_function(philo->args->time_sleep);
	philo->status = THINK;
}

void	go_think(t_philo *philo)
{
	const int32_t	start_think = time_of_day_ms();
	
	pthread_mutex_lock(&philo->shared->print_msg);
	printf(FORMAT, start_think - philo->start_time, philo->id,  "thinking");
	pthread_mutex_unlock(&philo->shared->print_msg);
	philo->status = EAT;
}
