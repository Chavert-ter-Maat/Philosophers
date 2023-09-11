/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/23 14:36:21 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/09/11 15:12:59 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int	main(int argc, char **argv)
{
	t_data	data;
	int		status;
	
	status = input_error_handling(argc, argv);
	if (status != SUCCESS)
		return(status); // change to free & exit
	status = input_parsing(&data, argv);
	if (status != SUCCESS)
		return(status); // change to free & exit
	status = setup_threads(data);
	if (status != SUCCESS) 
		return (status); // change to free & exit
	//free allocations	
	return(status);
}