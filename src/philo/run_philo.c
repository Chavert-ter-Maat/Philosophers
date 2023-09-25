/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   run_philo.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/18 15:06:10 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/09/25 14:58:26 by cter-maa      ########   odam.nl         */
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
	// set_time(philo);
	if ((philo->id % 2) != 0)
	{
		go_think(philo);
		usleep(500);
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

int32_t	run_philo(t_main *main)
{
	main->start_time = time_of_day_ms();
	if (create_threads(main) != SUCCESS)
		return (ERROR_THREAD);
	if (philo_thread_join(main->philo) != SUCCESS)
		return (ERROR_THREAD);
	return (SUCCESS);
}

// main thread checken of philo genoeg te eten heeft
// sleep functie maken om een groep te laten wachten dan zijn ze aan het denken
// mutex printf-en
// oneven eerst eten
// bij simulatie starten time last meal start setten


