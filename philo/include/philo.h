/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cter-maa <cter-maa@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/23 14:40:45 by cter-maa      #+#    #+#                 */
/*   Updated: 2023/10/13 12:10:42 by cter-maa      ########   odam.nl         */
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
# define LEFT	1
# define RIGHT	0
# define FORMAT	"%li %d %s\n"

// enum
typedef enum e_error
{
	SUCCESS,
	ERROR_ARGUMENT,
	ERROR_INPUT,
	ERROR_ALLOCATION,
	ERROR_THREAD,
	ERROR_MUTEX
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
	ERROR,
	SIM_STOP,
	PRINTED,
	SINGLE_PHILO
}	t_state;

typedef struct s_general
{
	int32_t				nbr_philo;
	uint64_t			time_die;
	uint64_t			time_eat;
	uint64_t			time_sleep;
	int32_t				max_meals;
	int32_t				inited_chops;
	int32_t				inited_threads;
}	t_general;

typedef struct s_philo
{
	int32_t				id;
	pthread_t			thread_id;
	uint64_t			time_last_eat;
	int32_t				meals_eaten;
	int32_t				status;
	int32_t				right;
	int32_t				left;
	struct s_shared		*shared;
	struct s_general	*general;
}	t_philo;

typedef struct s_shared
{
	pthread_mutex_t		observer;
	pthread_mutex_t		start;
	pthread_mutex_t		print;
	pthread_mutex_t		chops[200];
	int32_t				nbr_full_philo;
	int32_t				status;
	uint64_t			start_time;
	t_general			*general;
	t_philo				*philo;
}	t_shared;

// philo
uint32_t		go_eat(t_philo *philo);
uint32_t		go_sleep(t_philo *philo);
uint32_t		go_think(t_philo *philo);
uint32_t		print_action(t_philo *philo, int32_t state);
uint32_t		check_state(t_philo *philo);
uint32_t		check_runner(t_philo *philo);
int32_t			create_threads(t_shared *main);
int32_t			error_handling(int argc, char **argv);
int32_t			error_message(int32_t status, char *time_to_die);
int32_t			argument_parsing(t_general *general, char **argv);
int32_t			initialization(t_shared *shared, t_philo *philo);
void			check_full(t_philo *philo);

// utils
long long int	ph_atoi(const char *str);
void			ph_putstr_fd(const int fd, const char *message);
void			ph_bzero(void *s, size_t amount);
int32_t			sleep_function(t_philo *philo, uint64_t sleep_ms);
uint64_t		get_time(void);
int32_t			destroy_chops(t_shared *shared);
int32_t			ph_strcmp(const char *str1, const char *str2);
int32_t			thread_join(t_philo *philo);
int32_t			destroy_mutex(t_shared *shared, int32_t status);

#endif
