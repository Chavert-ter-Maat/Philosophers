/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/23 14:36:21 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/10/09 11:51:55 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

static int	run_philo(t_shared *shared)
{
	if (create_threads(shared) != SUCCESS)
		return (ERROR_THREAD);
	check_runner(shared->philo);
	if (thread_join(shared->philo) != SUCCESS)
		return (ERROR_THREAD);
	return (SUCCESS);
}

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
	status = run_philo(&shared);
	destroy_mutex(&shared, status);
	return (status);
}
