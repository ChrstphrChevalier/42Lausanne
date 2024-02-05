/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 12:31:04 by waziz             #+#    #+#             */
/*   Updated: 2024/02/04 13:08:13 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

pthread_mutex_t	*get_printer_mutex(void)
{
	static pthread_mutex_t	printer = PTHREAD_MUTEX_INITIALIZER;

	return (&printer);
}

static int	free_philo(t_philosopher *head)
{
	t_philosopher	*tmp;

	if (head)
		head->prev->next = NULL;
	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	return (0);
}

int	free_table(t_table *table, int num_philosophers)
{
	int	i;

	i = -1;
	if (table)
	{
		if (table->philosophers)
			free_philo(table->philosophers);
		if (table->forks)
		{
			while (++i < num_philosophers)
				pthread_mutex_destroy(&table->forks[i]);
			free(table->forks);
		}
		free(table);
	}
	return (0);
}

int	ft_error(int error, pthread_t *threads, pthread_t *thread, t_philosopher *p)
{
	pthread_mutex_lock(p->check->mut_print);
	if (error == 1)
		ft_printf("Error : Allocated threads failed.\n");
	else if (error == 2)
		ft_printf("Error : Failed to create threads.\n");
	else if (error == 3)
		ft_printf("Error : Failed to create thread.\n");
	pthread_mutex_unlock(p->check->mut_print);
	if (threads)
		free(threads);
	if (thread)
		free(thread);
	return (0);
}

long	ft_atoi(char *s)
{
	int		i;
	long	resultat;

	i = 0;
	resultat = 0;
	if (!s)
		return (1000000);
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (-1);
		i++;
	}
	i = 0;
	while (s[i] >= '0' && s[i] <= '9')
		resultat = (s[i++] - '0') + (resultat * 10);
	return (resultat);
}
