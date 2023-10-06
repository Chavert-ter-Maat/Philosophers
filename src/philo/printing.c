/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printing.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/28 11:32:51 by chavertterm   #+#    #+#                 */
/*   Updated: 2023/10/06 13:32:15 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

uint32_t	print_action(t_philo *philo, int32_t state)
{
	const uint64_t	time = get_time();
	const char	*msg[] = {
	[CHOP] = "has taken chopsticks",
	[EATING] = "is eating",
	[SLEEPING] = "is sleeping",
	[THINKING] = "is thinking",
	[DIED] = "has died",
	[FULL] = "philos are full",
	};

	pthread_mutex_lock(&philo->shared->print);
	printf(FORMAT, time - philo->shared->start_time, philo->id, msg[state]);
	pthread_mutex_unlock(&philo->shared->print);
	return (SUCCESS);
}
