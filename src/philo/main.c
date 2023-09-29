/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/23 14:36:21 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/09/29 14:16:15 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

void	check_state_philo(t_philo *philo)
{
	int	index;
	int	time_difference;
	int current_time = get_time();

	index = 0;
	while (1)
	{
		// pthread_mutex_lock(&philo->shared->eating);
		time_difference = current_time - philo[index].time_last_eat;
		printf("%i = time_last_eat\n", philo[index].time_last_eat);
		printf("%i = current_time\n", current_time);
		printf("%i = time_diff\n", time_difference);
		// pthread_mutex_unlock(&philo->shared->eating);
		if (time_difference > philo->args->time_die)
		{
			print_action(philo, DIED);
			exit(EXIT_SUCCESS);
		}
		if (philo->shared->nbr_full_philo == philo->args->nbr_philo)
		{
			print_action(philo, FULL);
			exit(EXIT_FAILURE);
		}
		if (index == philo->args->nbr_philo)
			index = 0;
		index++;
	}
}

int	run_philo(t_shared *shared)
{
	if (create_threads(shared) != SUCCESS)
		return (ERROR_THREAD);
	check_state_philo(shared->philo);
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
