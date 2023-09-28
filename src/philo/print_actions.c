/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_actions.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: chaverttermaat <chaverttermaat@student.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/28 11:32:51 by chavertterm   #+#    #+#                 */
/*   Updated: 2023/09/28 14:19:42 by chavertterm   ########   odam.nl         */
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

void	print_action(t_philo *philo, int32_t state)
{
	const int32_t	current_time = get_time();
	
	if (philo->status == DIED)
		{
			printf("philo has died");
			// join & free
			exit(EXIT_SUCCESS);
		}
	pthread_mutex_lock(&philo->shared->print_msg);
	printf(FORMAT, current_time - philo->shared->start_time, philo->id, message[state]);
	pthread_mutex_unlock(&philo->shared->print_msg);
}