/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_threads.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: chaverttermaat <chaverttermaat@student.      +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/26 13:13:51 by chavertterm   #+#    #+#                 */
/*   Updated: 2023/09/26 13:16:01 by chavertterm   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	set_time(t_philo *philo)
{
	pthread_mutex_lock(&philo->eating);
	philo->time_last_eat = philo->main->start_time;
	pthread_mutex_unlock(&philo->eating);
}

void	*action_sequence(void *arg)
{
	t_philo		*philo;
	
	philo = (t_philo*) arg;
	pthread_mutex_lock(&philo->main->start);
	pthread_mutex_unlock(&philo->main->start);
	set_time(philo);
	if ((philo->id % 2) == 1)
	{
		go_think(philo);
		sleep_function(philo->args->time_eat / 2);
	}
	while (1)
	{
		go_eat(philo);
		go_sleep(philo);
		go_think(philo);
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
		status = pthread_create(main->philo[i].thread_id, NULL, action_sequence, &main->philo[i]);
		if (status != SUCCESS)
		{
			printf("error creating threads");
			exit(1);
			return (ERROR_THREAD);
		}
		i++;
	}
	main->start_time = time_of_day_ms();
	pthread_mutex_unlock(&main->start);
	return (SUCCESS);
}