/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   run_philo.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/18 15:06:10 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/09/19 14:25:39 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int32_t	set_time(t_philo *philo, int32_t *start_time)
{
	gettimeofday(&philo->time_start, NULL);
	pthread_mutex_lock(&philo->main->start);
	
	pthread_mutex_unlock(&philo->main->start);
}

void	*action_sequence(void *arg)
{
	t_philo		*philo;
	int32_t		*start_time;
	
	philo = (t_philo*) arg;
	
	if (set_time(philo, &start_time) != SUCCESS)
		return (NULL);
	pthread_mutex_lock(&philo->main->start);
	pthread_mutex_unlock(&philo->main->start);
	if ((philo->id % UNEVEN) == 0)
	while (1)
	{
		
	}
	return (NULL);
}

int32_t create_threads(t_main *main)
{
	int	i;
	int	max_philos;
	int status;

	i = 0;
	max_philos = main->args->nbr_philo;
	pthread_mutex_lock(&main->start);
	while (i < max_philos)
	{
		status = pthread_create(main->philo[i].thread, NULL, action_sequence, &main->philo[i]);
		if (status != SUCCESS)
		{
			// free
			return (error_message(ERROR_THREAD));
		}
		i++;
	}
	pthread_mutex_unlock(&main->start);
	return (SUCCESS);
}