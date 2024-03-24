/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 11:18:06 by waziz             #+#    #+#             */
/*   Updated: 2024/02/04 13:05:14 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static int	thread_join(pthread_t *ts, pthread_t *t, t_philosopher *p)
{
	int	i;

	i = 0;
	if (pthread_join(*t, NULL) != 0)
		return (ft_error(0, ts, t, p));
	while (i < p->check->philo_numbers)
	{
		if (pthread_join(ts[i], NULL) != 0)
			return (ft_error(0, ts, t, p));
		i++;
	}
	free(ts);
	free(t);
	return (1);
}

int	philosopher_by_thread(t_table *table)
{
	pthread_t		*threads;
	pthread_t		*thread;
	t_philosopher	*cp;
	int				i;

	threads = malloc(sizeof(pthread_t) * table->num_philosophers);
	thread = malloc(sizeof(pthread_t) * 1);
	if (!threads || !thread)
		return (ft_error(1, threads, thread, table->philosophers));
	cp = table->philosophers;
	i = 0;
	while (i < table->num_philosophers)
	{
		if (pthread_create(&threads[i], NULL,
				&routine_philosopher, (void *)cp) != 0)
			return (ft_error(2, threads, thread, cp));
		cp = cp->next;
		i++;
	}
	if (pthread_create(thread, NULL, check_death, (void *)cp) != 0)
		return (ft_error(3, threads, thread, cp));
	if (thread_join(threads, thread, cp) != 1)
		return (0);
	return (1);
}
