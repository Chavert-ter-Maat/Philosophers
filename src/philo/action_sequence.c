/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   action_sequence.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/20 13:21:44 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/09/28 14:24:06 by chavertterm   ########   odam.nl         */
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
	pthread_mutex_lock(&philo->shared->chops[philo->right]);
	pthread_mutex_lock(&philo->shared->chops[philo->left]);
	print_action(philo, CHOP);
	print_action(philo, EATING);
	sleep_function(philo->args->time_eat);
	philo->meals_eaten += 1;
	pthread_mutex_unlock(&philo->shared->chops[philo->left]);
	pthread_mutex_unlock(&philo->shared->chops[philo->right]);
	pthread_mutex_lock(&philo->shared->eating);
	philo->time_last_eat = get_time(); // moet dit in mutex?
	pthread_mutex_unlock(&philo->shared->eating);
	philo->status = SLEEPING;
	check_meals_eaten(philo);
}

void	go_sleep(t_philo *philo)
{
	print_action(philo, SLEEPING);
	sleep_function(philo->args->time_sleep);
	philo->status = THINKING;
}

void	go_think(t_philo *philo)
{
	print_action(philo, THINKING);
	philo->status = EATING;
}

void	*action_sequence(void *arg)
{
	t_philo		*philo;
	
	philo = (t_philo*) arg;
	pthread_mutex_lock(&philo->shared->start);
	philo->shared->start_time = get_time();
	pthread_mutex_unlock(&philo->shared->start);
	pthread_mutex_lock(&philo->shared->eating);
	philo->time_last_eat = philo->shared->start_time;
	pthread_mutex_unlock(&philo->shared->eating);
	if ((philo->id % 2) == 1)
	{
		go_think(philo);
		sleep_function(philo->args->time_eat / 2);
	}
	while (1)
	{
		go_eat(philo);
		go_sleep(philo);
		go_think(philo);
	}
	return (NULL);
}
