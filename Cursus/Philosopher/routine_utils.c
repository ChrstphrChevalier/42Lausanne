/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 12:31:31 by waziz             #+#    #+#             */
/*   Updated: 2024/02/05 00:45:56 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static void	weat(t_philosopher *p)
{
	while (p->check_grp == 0 && check_eaten(p, 1)
		&& p->check->philo_numbers > 1)
	{
		if (p->meals_eaten == p->check->max_meals - 1
			|| death_philo(p))
			break ;
		usleep(15);
	}
	while (p->check_grp == 1 && check_eaten(p, 0)
		&& p->check->philo_numbers > 1)
	{
		if (p->meals_eaten == p->check->max_meals - 1
			|| death_philo(p))
			break ;
		usleep(15);
	}
}

void	waiting_eat(t_philosopher *p)
{
	long long		ct;

	ct = timestamp() - p->check->st;
	weat(p);
	if (!death_philo(p))
	{
		pthread_mutex_lock(p->l_fork);
		pthread_mutex_lock(p->check->mut_print);
		ft_printf("%d ms, The philosopher %d has taken a l_fork\n",
			ct, p->id + 1);
		pthread_mutex_unlock(p->check->mut_print);
		pthread_mutex_lock(p->r_fork);
	}
}

void	posting_eat(t_philosopher *p)
{
	pthread_mutex_lock(p->check->mut_print);
	p->check->passed++;
	pthread_mutex_unlock(p->check->mut_print);
	while (p->check_grp == 1
		&& check_eaten(p, 1) && p->check->philo_numbers > 1)
	{
		if (check_passed_one(p))
			break ;
		else if (check_eaten(p, 0)
			|| check_max_meals(p))
			break ;
	}
	while (p->check_grp == 0
		&& check_eaten(p, 0) && p->check->philo_numbers > 1)
	{
		if (check_passed_two(p))
			break ;
		else if (check_eaten(p, 1)
			|| check_max_meals(p))
			break ;
	}
}

int	death_philo(t_philosopher *p)
{
	pthread_mutex_lock(p->check->mut_print);
	if (p->check->philo_dead == 1)
	{
		pthread_mutex_unlock(p->check->mut_print);
		return (1);
	}
	pthread_mutex_unlock(p->check->mut_print);
	return (0);
}
