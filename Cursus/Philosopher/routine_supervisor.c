/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_supervisor.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 11:04:44 by waziz             #+#    #+#             */
/*   Updated: 2024/02/04 12:48:01 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static int	check_time(t_philosopher *p)
{
	long long		time;

	time = 0;
	usleep(1000);
	pthread_mutex_lock(p->check->mut_print);
	if (p->meals_eaten > 0)
		time = timestamp() - p->a;
	if (p->meals_eaten == 0)
		time = timestamp() - p->check->st;
	pthread_mutex_unlock(p->check->mut_print);
	if (time > p->check->death_time_limit && !check_max_meals(p))
	{
		time = timestamp() - p->check->st;
		usleep(1000);
		pthread_mutex_lock(p->check->mut_print);
		ft_printf("%d ms, The Philosopher %d died.\n", time, p->id + 1);
		p->state = DEAD;
		p->check->philo_dead = 1;
		pthread_mutex_unlock(p->check->mut_print);
		return (1);
	}
	return (0);
}

void	*check_death(void *arg)
{
	t_philosopher	*p;

	p = (t_philosopher *)arg;
	while (!p->check->philo_dead)
	{
		while (p)
		{
			if (check_finish(p))
				break ;
			if (p && check_time(p))
				break ;
			usleep(1000);
			p = p->next;
		}
		if (check_finish(p))
			break ;
	}
	if (!p->check->philo_dead)
		ft_printf("Each philosopher has eaten %d times\n", p->meals_eaten);
	return (NULL);
}
