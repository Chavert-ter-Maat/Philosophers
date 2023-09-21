/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   run_philo.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/18 15:06:10 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/09/21 11:44:29 by chavertterm   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

// int32_t	set_time(t_philo *philo, int32_t *start_time)
// {
	
// 	pthread_mutex_lock(&philo->main->start);
	
// 	pthread_mutex_unlock(&philo->main->start);
// 	pthread_mutex_lock(&philo->eating);
	
// 	pthread_mutex_unlock(&philo->eating);	
// }

void	*action_sequence(void *arg)
{
	t_philo		*philo;
	// int32_t		*start_time;
	
	philo = (t_philo*) arg;
		
	printf(" ie ie voor de lock?\n");
	pthread_mutex_lock(&philo->main->start);
	pthread_mutex_unlock(&philo->main->start);
	if ((philo->id % 2) != 0)
	{
	printf("na de lock\n");
		usleep(500);
		go_think(philo);
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
		status = pthread_create(&main->philo[i].thread_id, NULL, action_sequence, &main->philo[i]);
		if (status != SUCCESS)
		{
			printf("error creating threads");
			exit(1);
			return (ERROR_THREAD);
		}
		i++;
	}
	pthread_mutex_unlock(&main->start);
	return (SUCCESS);
}

int32_t	run_philo(t_main *main)
{
	main->philo->time_start = time_of_day_ms();
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


