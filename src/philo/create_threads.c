/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_threads.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/26 13:13:51 by chavertterm   #+#    #+#                 */
/*   Updated: 2023/09/27 16:12:26 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

// void	check_state_philo(t_philo *philo)
// {
		
// }

static void	set_time(t_philo *philo)
{
	pthread_mutex_lock(&philo->shared->eating);
	philo->time_last_eat = philo->shared->start_time;
	pthread_mutex_unlock(&philo->shared->eating);
}

static void	*action_sequence(void *arg)
{
	t_philo		*philo;
	
	philo = (t_philo*) arg;
	pthread_mutex_lock(&philo->shared->start);
	pthread_mutex_unlock(&philo->shared->start);
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

int32_t create_threads(t_shared *shared)
{
	int	i;
	int	max_philos;
	int status;

	i = 0;
	max_philos = shared->args->nbr_philo;
	pthread_mutex_lock(&shared->start);
	while (i < max_philos)
	{
		status = pthread_create(shared->philo[i].thread_id, NULL, action_sequence, &shared->philo[i]);
		if (status != SUCCESS)
		{
			printf("error creating threads");
			exit(1);
			return (ERROR_THREAD);
		}
		i++;
	}
	shared->start_time = time_of_day_ms();
	pthread_mutex_unlock(&shared->start);
	return (SUCCESS);
}