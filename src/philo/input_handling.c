/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   handle_error.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/06 11:03:52 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/09/06 14:45:54 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

static const char	*g_error_message[] = {
[SUCCESS] = "",
[ERROR_ARGUMENT] = "Incorrect amount of arguments",
[ERROR_INPUT] = "Incorrect input",
[ERROR_ALLOCATION] = "Allocation failed",
[ERROR_THREAD] = "Thread create failed"
};

static int	error_message(int32_t status)
{
	ph_putstr_fd(STDERR_FILENO, "Philo: ");
	ph_putstr_fd(STDERR_FILENO, g_error_message[status]);
	ph_putstr_fd(STDERR_FILENO, "\n");
	ph_putstr_fd(STDERR_FILENO, "Philo: ");
	ph_putstr_fd(STDERR_FILENO, "run './philo help' for additional info \n");
	return (status);
}

static int	help_message()
{
	ph_putstr_fd(STDOUT_FILENO, "enter 4 or 5 arguments \n");
	ph_putstr_fd(STDOUT_FILENO, "argument 1 = \n");
	ph_putstr_fd(STDOUT_FILENO, "argument 2 = \n");
	return (SUCCESS);
}

int	handle_error(int argc, char **argv)
{
	if (argc == 2 && (ph_strcmp(argv[1], "help") == 0))
		return (help_message());
	if (argc < 4 || argc > 5)
		return (error_message(ERROR_ARGUMENT));
	if (!*argv[0] || !*argv[1] || !*argv[2] || !*argv[3] || 
		(argv[4] && !*argv[4]))
		return (error_message(ERROR_INPUT));
	return(SUCCESS);
}
