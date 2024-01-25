/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 12:31:45 by waziz             #+#    #+#             */
/*   Updated: 2024/01/20 12:31:47 by waziz            ###   ########.fr       */
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

typedef struct s_sem_grp
{
	sem_t	*even_grp;
	sem_t	*odd_grp;
	int	eaten;
	int	philo_passed;
}	t_sem_grp;

typedef struct s_philosopher
{
	int		ID;
	t_state		state;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	int		check_forks;
	int		meals_eaten;
	int		check_eaten;
	long		max_meals;
	long		death_time_limit;
	long		eat_time;
	long		sleep_time;
	int		num_philo;
	t_sem_grp	*my_grp;
	struct timeval	*start_time;
	struct	s_philosopher	*next;
	struct	s_philosopher	*prev;
}	t_philosopher;

typedef struct s_table
{
	t_philosopher	*philosophers;
	pthread_mutex_t	*forks;
	int		num_philosophers;
}	t_table;

t_table		*init_table(int num_philosophers, t_sem_grp *sem_grps, struct timeval *st,
		long t_dead, long t_eat, long t_sleep, long max_m);
void		free_table(t_table *table, int num_philosophers);
void		*routine_philosopher(void *philosophe_ptr);
int		ft_error(int error, pthread_t *threads);
long		ft_atoi(char *s);
pthread_mutex_t	*get_printer_mutex(void);
void		waiting_sem(t_philosopher *philosophe);
void		posting_sem(t_philosopher *philosophe);
void		ft_usleep(long int ms);

#endif
