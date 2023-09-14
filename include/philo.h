/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/23 14:40:45 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/09/14 13:56:37 by chavertterm   ########   odam.nl         */
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
# include <sys/time.h>

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
typedef enum e_state
{
	CHOPS,
	EAT,
	SLEEP,
	THINK,
	DIE,
	END,
	ERROR
}	t_state;

typedef struct s_args
{
	int32_t				nbr_philo;
	int32_t				time_die;
	int32_t				time_eat;
	int32_t				time_sleep;
	int32_t				nbr_meal;
	
}	t_args;

typedef struct s_philo
{
	int32_t				id;
	pthread_t			*thread;
	int32_t				time_last_eat;
	int32_t				meals_eaten;
	int32_t				status;
	pthread_mutex_t		eating;
	pthread_mutex_t		*chops_r;
	pthread_mutex_t		*chops_l;
	t_args				*args;
}	t_philo;

// error_handling
int32_t			error_handling(int argc, char **argv);
int32_t			error_message(int32_t status);

// input_parsing
int32_t			argument_parsing(t_args *args, char **argv);
int32_t 		allocate_philo_struct(t_args *args, t_philo **philos);

// utils
int32_t			ph_strcmp(const char *str1, const char *str2);
long long int	ph_atoi(const char *str);
void			ph_putstr_fd(const int fd, const char *message);
void			ph_bzero(void *s, size_t amount);

#endif
