/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_handling.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/06 11:03:52 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/10/09 11:37:48 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int32_t	error_message(int32_t status, char *time_to_die)
{
	const char	*error_message[] = {
	[SUCCESS] = "",
	[ERROR_INPUT] = "incorrect input",
	[ERROR_ALLOCATION] = "allocation failed",
	[ERROR_THREAD] = "thread create failed"
	};

	if (status == SINGLE_PHILO)
	{
		ph_putstr_fd(STDOUT_FILENO, time_to_die);
		ph_putstr_fd(STDOUT_FILENO, " 1 ");
		ph_putstr_fd(STDOUT_FILENO, "has died\n");
		return (SUCCESS);
	}
	ph_putstr_fd(STDERR_FILENO, "philo: ");
	ph_putstr_fd(STDERR_FILENO, error_message[status]);
	ph_putstr_fd(STDERR_FILENO, "\n");
	ph_putstr_fd(STDERR_FILENO, "philo: './philo help' for more info\n");
	ph_putstr_fd(STDERR_FILENO, "exit\n");
	return (status);
}

static int32_t	help_message(void)
{
	ph_putstr_fd(STDOUT_FILENO, "philo: enter 4 or 5 arguments\n");
	ph_putstr_fd(STDOUT_FILENO, "philo: arg 1 = nbr philos > 1 & <= 200\n");
	ph_putstr_fd(STDOUT_FILENO, "philo: arg 2 = time to die\n");
	ph_putstr_fd(STDOUT_FILENO, "philo: arg 3 = time to eat\n");
	ph_putstr_fd(STDOUT_FILENO, "philo: arg 4 = time to sleep\n");
	ph_putstr_fd(STDOUT_FILENO, "philo: arg 5 = max times eat (optional)\n");
	ph_putstr_fd(STDERR_FILENO, "exit\n");
	return (1);
}

int32_t	error_handling(int argc, char **argv)
{
	if (argc == 2 && (ph_strcmp(argv[1], "help") == 0))
		return (help_message());
	if (argc < 5 || argc > 6)
		return (error_message(ERROR_INPUT, argv[2]));
	if (!*argv[0] || !*argv[1] || !*argv[2] || !*argv[3]
		|| (argv[4] && !*argv[4]))
		return (error_message(ERROR_INPUT, argv[2]));
	return (SUCCESS);
}
