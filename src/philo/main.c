/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/23 14:36:21 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/09/18 16:26:08 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int	main(int argc, char **argv)
{
	t_main		main;
	int			status;
	
	status = error_handling(argc, argv);
	if (status != SUCCESS)
		return(status); 
	status = argument_parsing(main.args, argv);
	if (status != SUCCESS)
		return(status); 
	status = allocate_main(&main);
	if (status != SUCCESS) 
	{
		// free *philo
		//free  main
		return (status);
	}
	status = create_threads(&main);
	
	//free allocations	
	return(status);
}