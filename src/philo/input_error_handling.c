/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_error_handling.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/09/06 11:03:52 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/09/07 16:03:59 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

static const char	*g_error_message[] = {
[SUCCESS] = "",
[ERROR_ARGUMENT] = "incorrect amount of arguments",
[ERROR_INPUT] = "incorrect input",
[ERROR_ALLOCATION] = "allocation failed",
[ERROR_THREAD] = "thread create failed"
};

int32_t	error_message(int32_t status)
{
	ph_putstr_fd(STDERR_FILENO, "philo: ");
	ph_putstr_fd(STDERR_FILENO, g_error_message[status]);
	ph_putstr_fd(STDERR_FILENO, "\n");
	ph_putstr_fd(STDERR_FILENO, "philo: run './philo help' for additional info \n");
	ph_putstr_fd(STDERR_FILENO, "philo: exit\n");
	return (status);
}

static int32_t	help_message()
{
	ph_putstr_fd(STDOUT_FILENO, "philo: enter 4 or 5 arguments \n");
	ph_putstr_fd(STDOUT_FILENO, "philo: argument 1 = \n");
	ph_putstr_fd(STDOUT_FILENO, "philo: argument 2 = \n");
	ph_putstr_fd(STDERR_FILENO, "philo: exit\n");
	return (SUCCESS);
}

int32_t	input_error_handling(int argc, char **argv)
{
	if (argc == 2 && (ph_strcmp(argv[1], "help") == 0))
		return (help_message());
	if (argc < 4 || argc > 6)
		return (error_message(ERROR_ARGUMENT));
	if (!*argv[0] || !*argv[1] || !*argv[2] || !*argv[3] || 
		(argv[4] && !*argv[4]))
		return (error_message(ERROR_INPUT));
	// if (check_digits_only(argv) != SUCCESS)
	// 	return(error_message(ERROR_INPUT));
	return(SUCCESS);
}
