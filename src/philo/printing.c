/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_actions.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/28 11:32:51 by chavertterm   #+#    #+#                 */
/*   Updated: 2023/10/04 14:02:03 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

uint32_t	print_action(t_philo *philo, int32_t state)
{
	const uint64_t	current_time = get_time();
	
	const char	*message[] = {
	[CHOP] = "has taken chopsticks",
	[EATING] = "is eating",
	[SLEEPING] = "is sleeping",
	[THINKING] = "is thinking",
	[DIED] = "has died",
	[FULL] = "philos are full",
	};
	pthread_mutex_lock(&philo->shared->time);
	printf(FORMAT, current_time - philo->shared->start_time, philo->id, message[state]);
	pthread_mutex_unlock(&philo->shared->time);
	return (SUCCESS);
}