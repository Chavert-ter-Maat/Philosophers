/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/23 14:36:21 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/10/02 16:40:01 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

static int	check_state_philo(t_philo *philo)
{
	int	index;
	uint64_t	time_difference;

	index = 0;
	while (1)
	{
		pthread_mutex_lock(&philo->shared->eating);
		time_difference = get_time() - philo[index].time_last_eat;
		pthread_mutex_unlock(&philo->shared->eating);
		if (time_difference > philo->args->time_die)
		{
			print_action(philo, DIED);
			return (SUCCESS);
			}
		if (philo->shared->nbr_full_philo == philo->args->nbr_philo)
		{
			print_action(philo, FULL);
			return (SUCCESS);
		}
		index++;
		if (index == philo->args->nbr_philo - 1)
			index = 0;
	}
}

int	run_philo(t_shared *shared)
{
	if (create_threads(shared) != SUCCESS)
		return (ERROR_THREAD);
	if (check_state_philo(shared->philo) == SUCCESS);
		{
			// free
			// philo_thread_join(shared->philo);
			// return ()
		}
	if (philo_thread_join(shared->philo) != SUCCESS)
		return (ERROR_THREAD);
	return (SUCCESS);
}

int	main(int argc, char **argv)
{
	t_shared	shared;
	t_args	args;
	t_philo	*philo;
	int		status;
	
	philo = NULL;
	status = error_handling(argc, argv);
	if (status != SUCCESS)
		return (error_message(status));
	status = argument_parsing(&args, argv);
	if (status != SUCCESS)
		return (error_message(status)); 
	shared.args = &args;
	status = initialization(&shared, &philo);
	if (status != SUCCESS) 
	{
		// free *philo
		//free  chops
		return (status);
	} 
	shared.philo = philo;
	status = run_philo(&shared);
	if (status != SUCCESS) 
	{
		// free *philo
		//free  chops
		return (status);
	}
	
	// //free allocations, philos, chops, join_threads??
	return(status);
}
