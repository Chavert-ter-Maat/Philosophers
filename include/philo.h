/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/23 14:40:45 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/09/19 13:52:48 by cter-maa      ########   odam.nl         */
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

// defines
# define	UNEVEN	2
# define 	FORMAT	"%d %d %s\n"

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
	int32_t				time_start;
	int32_t				time_last_eat;
	int32_t				meals_eaten;
	int32_t				status;
	pthread_mutex_t		eating;
	struct s_main		*main;
}	t_philo;

typedef struct s_main
{
	pthread_mutex_t		*chops;
	pthread_mutex_t		start;
	t_args				*args;
	t_philo				*philo;
}	t_main;

// error_handling
int32_t			error_handling(int argc, char **argv);
int32_t			error_message(int32_t status);

// input_parsing
int32_t			argument_parsing(t_args *args, char **argv);

// allocate_structs
int32_t 		allocate_main(t_main *main);

// run_philo
int32_t 		create_threads(t_main *main);

// utils
int32_t			ph_strcmp(const char *str1, const char *str2);
long long int	ph_atoi(const char *str);
void			ph_putstr_fd(const int fd, const char *message);
void			ph_bzero(void *s, size_t amount);

#endif
