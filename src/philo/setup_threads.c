/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   setup_threads.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/11 13:42:13 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/09/11 16:15:05 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

static int32_t init_philos(t_philo *philosophers, t_data *data, int32_t index)
{
	ph_bzero(philosophers, sizeof(philosophers));
	philosopher>id = index;
	philosopher->data = data;
	philosopher->last_eat = get_time_ms();
}

int32_t join_thread()
{
	
}

int32_t setup_thread(t_data *data)
{
	pthread_t	*threads;
	t_philo		*philos;
	int32_t index;
	
	index = 0;
	threads = malloc(sizeof(pthread_t) * data->nbr_philo);
	if (!threads)
		return (ERROR_ALLOCATION);
	philos = malloc(size_t(t_hilo) * data->nbr_philo)
	if (!threads)
	{
		//free threads;
		return (ERROR_ALLOCATION);
	}
	while (index < data->nbr_philo)
	{
		init_philos(&philos[index], data, index);
		if ()
		index++;
	}
	return (SUCCESS);
}

