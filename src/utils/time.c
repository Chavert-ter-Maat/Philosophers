/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   time.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/20 11:21:35 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/09/25 16:30:12 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int64_t	time_of_day_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void time_sleep(int64_t sleep_ms)
{
    const int64_t start = time_of_day_ms();
    int64_t elapsed_ms;

    while (1)
    {
		printf("dikke piemel");
        elapsed_ms = time_of_day_ms() - start;
        if (elapsed_ms >= sleep_ms)
            return;
        usleep(500);
    }
}