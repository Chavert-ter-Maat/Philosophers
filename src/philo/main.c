/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/23 14:36:21 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/10/03 14:42:50 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

static int	run_philo(t_shared *shared)
{
	if (create_threads(shared) != SUCCESS)
		return (ERROR_THREAD);
	if (check_state_philo(shared->philo) == SIM_STOP)
		return (SIM_STOP);
	if (thread_join(shared->philo) != SUCCESS)
		return (ERROR_THREAD);
	return (SUCCESS);
}

int	main(int argc, char **argv)
{
	t_shared	shared;
	t_args	args;
	t_philo	philo[200];
	int		status;
	
	status = error_handling(argc, argv);
	if (status != SUCCESS)
		return (error_message(status));
	status = argument_parsing(&args, argv);
	if (status != SUCCESS)
		return (error_message(status)); 
	shared.args = &args;
	status = initialization(&shared, philo);
	if (status != SUCCESS) 
		return (status);
	shared.philo = philo;
	status = run_philo(&shared);
	if (status != SUCCESS) 
		return (status);
	
	// //free allocations, philos, chops, join_threads??
	return(status);
}
