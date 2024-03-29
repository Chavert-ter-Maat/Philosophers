/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   time.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/20 11:21:35 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/10/13 12:02:06 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

uint64_t	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

int32_t	sleep_function(t_philo *philo, uint64_t sleep_ms)
{
	const uint64_t	start = get_time();
	uint64_t		elapsed_ms;

	(void) *philo;
	while (1)
	{
		elapsed_ms = get_time() - start;
		if (elapsed_ms >= sleep_ms)
			return (SUCCESS);
		usleep(500);
		if (elapsed_ms > philo->general->time_die)
			return (SIM_STOP);
	}
	return (SUCCESS);
}
