/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/23 14:40:45 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/09/06 14:19:30 by cter-maa      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

// headers
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <semaphore.h>

// defines

// enum
typedef enum e_error
{
	SUCCESS,
	ERROR_ARGUMENT,
	ERROR_INPUT,
	ERROR_ALLOCATION,
	ERROR_THREAD,
	ARGUMENT_ERROR,
	INPUT_ERROR,
	ALLOCATION_ERROR,
}	t_error;

// structures
// typedef struct s_philo
// {
	
// }	t_philo;

int32_t	ph_init(int argc, char **argv);

// error
int		handle_error(int argc, char **argv);
void	ph_putstr_fd(const int fd, const char *message);

// utils
int		ph_strcmp(const char *str1, const char *str2);
void	ph_putstr_fd(const int fd, const char *message);


#endif
