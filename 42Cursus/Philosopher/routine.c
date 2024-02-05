/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 12:31:17 by waziz             #+#    #+#             */
/*   Updated: 2024/02/04 12:59:01 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static int	to_think(t_philosopher *p)
{
	long long		ct;

	ct = timestamp() - p->check->st;
	pthread_mutex_lock(p->check->mut_print);
	ft_printf("%d ms, The philosophers %d is thinking.\n", ct, p->id + 1);
	p->state = THINKING;
	pthread_mutex_unlock(p->check->mut_print);
	pthread_mutex_lock(p->check->mut_print);
	if (p->check->philo_numbers == 1)
	{
		pthread_mutex_unlock(p->check->mut_print);
		return (1);
	}
	pthread_mutex_unlock(p->check->mut_print);
	return (0);
}

static void	to_eat(t_philosopher *p)
{
	long long		ct;

	ct = timestamp() - p->check->st;
	pthread_mutex_lock(p->check->mut_print);
	ft_printf("%d ms, The philosopher %d has taken a r_fork\n", ct, p->id + 1);
	pthread_mutex_unlock(p->check->mut_print);
	pthread_mutex_lock(p->check->mut_print);
	p->state = EATING;
	p->a = timestamp();
	p->meals_eaten++;
	ft_printf("%d ms, The philosophers %d is eating.\n", ct, p->id + 1);
	pthread_mutex_unlock(p->check->mut_print);
	ft_usleep(p->check->eat_time);
	pthread_mutex_unlock(p->l_fork);
	pthread_mutex_unlock(p->r_fork);
}

static void	to_sleep(t_philosopher *p)
{
	long long			ct;

	ct = timestamp() - p->check->st;
	pthread_mutex_lock(p->check->mut_print);
	ft_printf("%d ms, The philosophers %d is sleeping.\n", ct, p->id + 1);
	p->state = SLEEPING;
	pthread_mutex_unlock(p->check->mut_print);
	ft_usleep(p->check->sleep_time);
	pthread_mutex_lock(p->check->mut_print);
	if (p->meals_eaten == p->check->max_meals)
		p->check->finish++;
	pthread_mutex_unlock(p->check->mut_print);
}

void	*routine_philosopher(void *philosophe_ptr)
{
	t_philosopher	*p;

	p = (t_philosopher *)philosophe_ptr;
	if (p->check_grp == 1)
		usleep(1500);
	while (p->meals_eaten < p->check->max_meals)
	{
		if (death_philo(p))
			break ;
		if (to_think(p))
			break ;
		if (death_philo(p))
			break ;
		waiting_eat(p);
		if (death_philo(p))
			break ;
		to_eat(p);
		if (death_philo(p))
			break ;
		posting_eat(p);
		if (death_philo(p))
			break ;
		to_sleep(p);
	}
	return (NULL);
}
