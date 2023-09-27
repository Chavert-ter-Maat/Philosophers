/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/23 14:36:21 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/09/27 15:52:22 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int32_t	run_philo(t_shared *shared)
{
	if (create_threads(shared) != SUCCESS)
		return (ERROR_THREAD);
	if (philo_thread_join(shared->philo) != SUCCESS)
		return (ERROR_THREAD);
	// check_state_philo(main->philo);
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
	status = init_philo(&shared, &philo);
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
