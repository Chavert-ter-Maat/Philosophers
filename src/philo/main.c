/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/23 14:36:21 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/09/27 10:23:46 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int	main(int argc, char **argv)
{
	t_main		main;
	t_args		args;
	t_philo		*philo;
	int			status;
	
	philo = NULL;
	status = error_handling(argc, argv);
	if (status != SUCCESS)
		return (error_message(status));
	status = argument_parsing(&args, argv);
	if (status != SUCCESS)
		return (error_message(status)); 
	main.args = &args;
	status = init_philo(&main, &philo);
	if (status != SUCCESS) 
	{
		// free *philo
		//free  chops
		return (status);
	} 
	main.philo = philo;
	status = run_philo(&main);
	if (status != SUCCESS) 
	{
		// free *philo
		//free  chops
		return (status);
	}
	
	// //free allocations, philos, chops, join_threads??
	return(status);
}
