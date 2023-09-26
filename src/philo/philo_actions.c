/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo_actions.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/20 13:21:44 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/09/26 13:09:22 by chavertterm   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

static void	check_meals_eaten(t_philo *philo)
{
	int32_t	current_meals_eaten;
	int32_t	max_meals;

	current_meals_eaten = philo->meals_eaten;
	pthread_mutex_lock(&philo->main->start);
	max_meals = philo->args->max_meals;
	if (current_meals_eaten == max_meals)
		philo->main->nbr_full_philo;
	pthread_mutex_unlock(&philo->main->start);
}

void	go_eat(t_philo *philo)
{
	int32_t start_eat;
	int32_t time_eat;
	
	start_eat = 0;
	pthread_mutex_lock(&philo->main->start);
	time_eat = philo->args->time_eat;
	pthread_mutex_unlock(&philo->main->start);
	pthread_mutex_lock(&philo->print_msg);
	printf(FORMAT, time_of_day_ms() - philo->main->start_time, philo->id, "eating");
	pthread_mutex_unlock(&philo->print_msg);
	pthread_mutex_lock(&philo->main->chops[philo->right]);
	pthread_mutex_lock(&philo->main->chops[philo->left]);
	start_eat = time_of_day_ms();
	pthread_mutex_lock(&philo->eating);
	philo->time_last_eat = start_eat;
	pthread_mutex_unlock(&philo->eating);
	sleep_function(time_eat);
	philo->meals_eaten += 1;
	pthread_mutex_unlock(&philo->main->chops[philo->left]);
	pthread_mutex_unlock(&philo->main->chops[philo->right]);
	philo->status = SLEEP;
	check_meals_eaten(philo);
}

void	go_sleep(t_philo *philo)
{
	const int32_t	start_sleep = time_of_day_ms();
	int32_t	time_sleep;
	
	pthread_mutex_lock(&philo->main->start);
	time_sleep = philo->main->start_time;
	pthread_mutex_unlock(&philo->main->start);
	pthread_mutex_lock(&philo->print_msg);
	printf(FORMAT, start_sleep - philo->main->start_time, philo->id,  "sleep");
	pthread_mutex_unlock(&philo->print_msg);
	sleep_function(time_sleep);
	philo->status = THINK;
}

void	go_think(t_philo *philo)
{
	const int32_t	start_think = time_of_day_ms();
	
	printf(FORMAT, start_think - philo->main->start_time, philo->id,  "thinking");
	philo->status = EAT;
}