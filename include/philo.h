/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/23 14:40:45 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/10/02 17:10:11 by cter-maa      ########   odam.nl         */
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
# include <stdint.h>

// defines
# define	UNEVEN	% 2
# define	LEFT	1
# define	RIGHT	0
# define 	FORMAT	"%li %d %s\n"

// enum
typedef enum e_error
{
	SUCCESS,
	ERROR_ARGUMENT,
	ERROR_INPUT,
	ERROR_ALLOCATION,
	ERROR_THREAD,
}	t_error;

// structures
typedef enum e_state
{
	CHOP,
	EATING,
	SLEEPING,
	THINKING,
	DIED,
	FULL,
	ERROR
}	t_state;

typedef struct s_args
{
	int32_t				nbr_philo;
	uint64_t				time_die;
	uint64_t				time_eat;
	uint64_t				time_sleep;
	int32_t				max_meals;
}	t_args;

typedef struct s_philo
{
	int32_t				id;
	pthread_t			*thread_id;
	uint64_t			time_last_eat;
	uint64_t			start_time;
	int32_t				meals_eaten;
	int32_t				status;
	int32_t				right;
	int32_t				left;
	struct s_shared		*shared;
	struct s_args		*args;
}	t_philo;

typedef struct s_shared
{
	pthread_mutex_t		print_msg;
	pthread_mutex_t		eating;
	pthread_mutex_t		*chops;
	pthread_mutex_t		start;
	int32_t				nbr_full_philo;
	uint64_t			start_time;
	t_args				*args;
	t_philo				*philo;
}	t_shared;

// philo_actions
void			go_eat(t_philo *philo);
void			go_sleep(t_philo *philo);
void			go_think(t_philo *philo);
void			print_action(t_philo *philo, int32_t state);

int32_t			 create_threads(t_shared *main);
void			*action_sequence(void *arg);

// error_handling
int32_t			error_handling(int argc, char **argv);
int32_t			error_message(int32_t status);

// input_parsing
int32_t			argument_parsing(t_args *args, char **argv);

// allocate_structs
int32_t 		initialization(t_shared *main, t_philo **philo);

// run_philo
int32_t			run_philo(t_shared *main);

// utils
int32_t			ph_strcmp(const char *str1, const char *str2);
long long int	ph_atoi(const char *str);
void			ph_putstr_fd(const int fd, const char *message);
void			ph_bzero(void *s, size_t amount);

// utils_time
uint64_t		get_time(void);
void			sleep_function(uint64_t sleep_ms);

// utils_free
int32_t			free_philos(t_philo *philo);

#endif
