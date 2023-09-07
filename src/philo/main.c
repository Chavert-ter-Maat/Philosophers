/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/23 14:36:21 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/09/07 16:15:16 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int	main(int argc, char **argv)
{
	int	status;
	t_philo	ph;
	
	status = input_error_handling(argc, argv);
	if (status != SUCCESS)
		return(status);
	status = input_parsing(&ph, argv);
	if (status != SUCCESS)
		return(status);

	//free allocations	
	return(status);
}