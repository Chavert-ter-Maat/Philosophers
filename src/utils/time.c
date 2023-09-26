/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   time.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/20 11:21:35 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/09/26 12:04:04 by chavertterm   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int32_t	time_of_day_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void sleep_function(int32_t sleep_ms)
{
    const int32_t start = time_of_day_ms();
    int32_t elapsed_ms;

    while (1)
    {
        elapsed_ms = time_of_day_ms() - start;
        if (elapsed_ms >= sleep_ms)
            return;
        usleep(500);
    }
}