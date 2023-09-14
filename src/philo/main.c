/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/23 14:36:21 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/09/14 12:57:31 by chavertterm   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int	main(int argc, char **argv)
{
	t_args		args;
	t_philo		*philo;
	int			status;
	
	status = error_handling(argc, argv);
	if (status != SUCCESS)
		return(status); 
	status = argument_parsing(&args, argv);
	if (status != SUCCESS)
		return(status); 
	//protect single philo
	status = allocate_philo_struct(&args, &philo);
	if (status != SUCCESS) 
	{
		// free *philo
		return (status);
	}
	//free allocations	
	return(status);
}