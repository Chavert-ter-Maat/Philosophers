/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/23 14:36:21 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/10/13 11:58:44 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int	main(int argc, char **argv)
{
	t_shared	shared;
	t_general	general;
	t_philo		philo[200];
	int			status;

	status = error_handling(argc, argv);
	if (status != SUCCESS)
		return (status);
	status = argument_parsing(&general, argv);
	if (status != SUCCESS)
		return (error_message(status, argv[2]));
	shared.general = &general;
	status = initialization(&shared, philo);
	if (status != SUCCESS)
		return (error_message(status, argv[2]));
	shared.philo = philo;
	status = create_threads(&shared);
	if (status != SUCCESS)
		return (destroy_mutex(&shared, status));
	check_runner(philo);
	status = thread_join(philo);
	destroy_mutex(&shared, status);
	return (status);
}
