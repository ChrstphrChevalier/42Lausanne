/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 12:31:45 by waziz             #+#    #+#             */
/*   Updated: 2024/02/04 13:11:00 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <pthread.h>
# include <semaphore.h>
# include <stdbool.h>
# include <sys/time.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# include "Printf/ft_printf.h"

typedef enum s_state
{
	THINKING,
	EATING,
	SLEEPING,
	DEAD
}	t_state;

typedef struct s_check_up
{
	int						eaten;
	int						philo_dead;
	long					max_meals;
	long					death_time_limit;
	long					eat_time;
	long					sleep_time;
	int						philo_numbers;
	int						finish;
	int						passed;
	long long				st;
	pthread_mutex_t			*mut_print;
}	t_check_up;

typedef struct s_philosopher
{
	int						id;
	t_state					state;
	pthread_mutex_t			*l_fork;
	pthread_mutex_t			*r_fork;
	int						check_grp;
	int						meals_eaten;
	t_check_up				*check;
	struct s_philosopher	*next;
	struct s_philosopher	*prev;
	long long				a;
}	t_philosopher;

typedef struct s_table
{
	t_philosopher	*philosophers;
	pthread_mutex_t	*forks;
	int				num_philosophers;
}	t_table;

t_table			*init_table(int num_philosophers, t_check_up *checks);
int				free_table(t_table *table, int num_philosophers);
void			*routine_philosopher(void *philosophe_ptr);
int				ft_error(int error, pthread_t *threads,
					pthread_t *thread, t_philosopher *p);
long			ft_atoi(char *s);
pthread_mutex_t	*get_printer_mutex(void);
void			waiting_eat(t_philosopher *p);
void			posting_eat(t_philosopher *p);
void			*check_death(void *arg);
int				init_checkup(t_check_up *checks, long long start, char **av);
int				philosopher_by_thread(t_table *table);
void			ft_usleep(long int ms);
long long		timestamp(void);
int				death_philo(t_philosopher *p);
int				check_eaten(t_philosopher *p, int value);
int				check_passed_one(t_philosopher *p);
int				check_passed_two(t_philosopher *p);
int				check_finish(t_philosopher *p);
int				check_max_meals(t_philosopher *p);

#endif
