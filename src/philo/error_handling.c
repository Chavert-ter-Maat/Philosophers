/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error_handling.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/06 11:03:52 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/09/11 16:12:52 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

int32_t	error_message(int32_t status)
{
	const char	*error_message[] = {
	[SUCCESS] = "",
	[ERROR_ARGUMENT] = "incorrect amount of arguments",
	[ERROR_INPUT] = "incorrect input",
	[ERROR_ALLOCATION] = "allocation failed",
	[ERROR_THREAD] = "thread create failed"
	};

	ph_putstr_fd(STDERR_FILENO, "philo: ");
	ph_putstr_fd(STDERR_FILENO, error_message[status]);
	ph_putstr_fd(STDERR_FILENO, "\n");
	ph_putstr_fd(STDERR_FILENO, "philo: run './philo help' for more info\n");
	ph_putstr_fd(STDERR_FILENO, "philo: exit\n");
	return (status);
}

static int32_t	help_message(void)
{
	ph_putstr_fd(STDOUT_FILENO, "philo: enter 4 or 5 arguments \n");
	ph_putstr_fd(STDOUT_FILENO, "philo: argument 1 = number of philosophers
		between 1 and 200 \n");
	ph_putstr_fd(STDOUT_FILENO, "philo: argument 2 = time to die\n");
	ph_putstr_fd(STDOUT_FILENO, "philo: argument 3 = time to eat\n");
	ph_putstr_fd(STDOUT_FILENO, "philo: argument 4 = time to sleep\n");
	ph_putstr_fd(STDOUT_FILENO, "philo: argument 5 = max times eat
		(optional)\n");
	ph_putstr_fd(STDERR_FILENO, "philo: exit\n");
	return (SUCCESS);
}

int32_t	input_error_handling(int argc, char **argv)
{
	if (argc == 2 && (ph_strcmp(argv[1], "help") == 0))
		return (help_message());
	if (argc < 4 || argc > 6)
		return (error_message(ERROR_ARGUMENT));
	if (!*argv[0] || !*argv[1] || !*argv[2] || !*argv[3]
		|| (argv[4] && !*argv[4]))
		return (error_message(ERROR_INPUT));
	return (SUCCESS);
}
