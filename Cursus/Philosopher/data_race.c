/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_race.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 15:19:46 by waziz             #+#    #+#             */
/*   Updated: 2024/02/04 12:43:28 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	check_eaten(t_philosopher *p, int value)
{
	pthread_mutex_lock(p->check->mut_print);
	if (p->check->eaten == value)
	{
		pthread_mutex_unlock(p->check->mut_print);
		return (1);
	}
	else
	{
		pthread_mutex_unlock(p->check->mut_print);
		return (0);
	}
}

int	check_passed_one(t_philosopher *p)
{
	pthread_mutex_lock(p->check->mut_print);
	if (p->check->passed == p->check->philo_numbers / 2 && p->id == 1)
	{
		p->check->eaten = 0;
		p->check->passed = 0;
		pthread_mutex_unlock(p->check->mut_print);
		return (1);
	}
	else
	{
		pthread_mutex_unlock(p->check->mut_print);
		return (0);
	}
}

int	check_passed_two(t_philosopher *p)
{
	pthread_mutex_lock(p->check->mut_print);
	if (p->check->passed == (p->check->philo_numbers + 1) / 2 && p->id == 0)
	{
		p->check->eaten = 1;
		p->check->passed = 0;
		pthread_mutex_unlock(p->check->mut_print);
		return (1);
	}
	else
	{
		pthread_mutex_unlock(p->check->mut_print);
		return (0);
	}
}

int	check_finish(t_philosopher *p)
{
	pthread_mutex_lock(p->check->mut_print);
	if (p->check->philo_numbers == p->check->finish)
	{
		pthread_mutex_unlock(p->check->mut_print);
		return (1);
	}
	else
	{
		pthread_mutex_unlock(p->check->mut_print);
		return (0);
	}
}

int	check_max_meals(t_philosopher *p)
{
	pthread_mutex_lock(p->check->mut_print);
	if (p->meals_eaten == p->check->max_meals)
	{
		pthread_mutex_unlock(p->check->mut_print);
		return (1);
	}
	else
	{
		pthread_mutex_unlock(p->check->mut_print);
		return (0);
	}
}
