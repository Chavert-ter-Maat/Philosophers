/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   time.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/20 11:21:35 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/09/28 14:07:56 by chavertterm   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int32_t	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void sleep_function(int32_t sleep_ms)
{
    const int32_t start = get_time();
    int32_t elapsed_ms;

    while (1)
    {
        elapsed_ms = get_time() - start;
        if (elapsed_ms >= sleep_ms)
            return;
        usleep(500);
    }
}