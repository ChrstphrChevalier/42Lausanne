/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 12:31:17 by waziz             #+#    #+#             */
/*   Updated: 2024/01/20 12:31:20 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static void	to_think(t_philosopher *philosophe, pthread_mutex_t *p)
{
	pthread_mutex_lock(p);
	ft_printf("The philosophers %d thinks.\n", philosophe->ID);
	pthread_mutex_unlock(p);
	philosophe->state = THINKING;
	usleep (2000);
}

static void	to_eat(t_philosopher *philosophe, pthread_mutex_t *p)
{
	pthread_mutex_lock(p);
	ft_printf("The philosophers %d begins to eat.\n", philosophe->ID);
	pthread_mutex_unlock(p);
	philosophe->state = EATING;
	philosophe->meals_eaten++;
	usleep (3000);
}

static void	to_sleep(t_philosopher *philosophe, pthread_mutex_t *p)
{
	pthread_mutex_lock(p);
	ft_printf("The philosophers %d sleeps.\n", philosophe->ID);
	pthread_mutex_unlock(p);
	philosophe->state = SLEEPING;
	usleep (1000);
}

static int	check_death(t_philosopher *ph, struct timeval *a,
		struct timeval *c, pthread_mutex_t *p)
{
	long	time;

	time = (c->tv_sec * 1000000L + c->tv_usec)
		- (a->tv_sec * 1000000L + a->tv_usec);
	if (time > ph->death_time_limit * 1000000L)
	{
		pthread_mutex_lock(p);
		ft_printf("The philosophers %d is dead.\n", ph->ID);
		pthread_mutex_unlock(p);
		ph->state = DEAD;
		return (1);
	}
	return (0);
}

void	*routine_philosopher(void *philosophe_ptr)
{
	struct timeval	current_time;
	struct timeval	after_eaten;
	t_philosopher	*philosophe;
	pthread_mutex_t	*printer;

	philosophe = (t_philosopher *)philosophe_ptr;
	printer = get_printer_mutex();
	while (philosophe->meals_eaten <= philosophe->max_meals){
		to_think(philosophe, printer);
		gettimeofday(&current_time, NULL);
		if (philosophe->meals_eaten > 0 &&
			check_death(philosophe, &after_eaten, &current_time, printer))
			break ;
		waiting_sem(philosophe);
		pthread_mutex_lock(philosophe->l_fork);
		pthread_mutex_lock(philosophe->r_fork);
		to_eat(philosophe, printer);
		gettimeofday(&after_eaten, NULL);
		pthread_mutex_unlock(philosophe->l_fork);
		pthread_mutex_unlock(philosophe->r_fork);
		posting_sem(philosophe);
		to_sleep(philosophe, printer);
	}
	return (NULL);
}
