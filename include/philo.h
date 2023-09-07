/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/23 14:40:45 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/09/07 16:31:33 by cter-maa      ########   odam.nl         */
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
# include <limits.h>

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
typedef struct s_philo
{
	int32_t	nbr_philo;
	int32_t	time_die;
	int32_t	time_eat;
	int32_t	time_sleep;
	int32_t	nbr_meal;
}	t_philo;

// input_parsing
int32_t			input_parsing(t_philo *ph, char **argv);
long long int	ph_atoi(const char *str);

// input_handling
int32_t	input_error_handling(int32_t argc, char **argv);
int32_t	check_digits_only(char **argv);
int32_t	error_message(int32_t status);

// utils
int32_t	ph_strcmp(const char *str1, const char *str2);
void	ph_putstr_fd(const int fd, const char *message);
void	ph_bzero(void *s, size_t amount);

#endif
