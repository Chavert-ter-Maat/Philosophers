/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   run_philo.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/18 15:06:10 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/09/27 10:18:39 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"


int32_t	run_philo(t_main *main)
{
	main->start_time = time_of_day_ms();
	if (create_threads(main) != SUCCESS)
		return (ERROR_THREAD);
	if (philo_thread_join(main->philo) != SUCCESS)
		return (ERROR_THREAD);
	// check_state_philo(main->philo);
	return (SUCCESS);
}
