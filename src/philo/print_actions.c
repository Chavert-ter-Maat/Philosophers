/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_actions.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/28 11:32:51 by chavertterm   #+#    #+#                 */
/*   Updated: 2023/10/03 14:32:03 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

static const char	*message[] = {
[CHOP] = "has taken chopsticks",
[EATING] = "is eating",
[SLEEPING] = "is sleeping",
[THINKING] = "is thinking",
[DIED] = "has died",
[FULL] = "philos are full",
};

uint32_t	print_action(t_philo *philo, int32_t state)
{
	uint64_t	current_time = get_time();
	
	pthread_mutex_lock(&philo->shared->print_msg);
	printf(FORMAT, current_time - philo->shared->start_time, philo->id, message[state]);
	pthread_mutex_unlock(&philo->shared->print_msg);
	return (SUCCESS);
}