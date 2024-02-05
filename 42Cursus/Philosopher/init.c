/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 12:32:15 by waziz             #+#    #+#             */
/*   Updated: 2024/02/04 13:10:31 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static t_philosopher	*create_new_philosopher(int i,
		t_philosopher *current, t_check_up *checks)
{
	t_philosopher	*new_philosopher;

	new_philosopher = malloc(sizeof(t_philosopher));
	if (!new_philosopher)
		return (NULL);
	new_philosopher->id = i;
	if (i % 2 == 0)
		new_philosopher->check_grp = 0;
	else
		new_philosopher->check_grp = 1;
	new_philosopher->state = THINKING;
	new_philosopher->meals_eaten = 0;
	new_philosopher->check = checks;
	new_philosopher->a = 0;
	new_philosopher->l_fork = NULL;
	new_philosopher->r_fork = NULL;
	new_philosopher->next = NULL;
	new_philosopher->prev = current;
	return (new_philosopher);
}

static t_philosopher	*init_philosophers(int np, t_check_up *checks)
{
	t_philosopher	*head;
	t_philosopher	*current;
	t_philosopher	*new_philosopher;
	int				i;

	i = 0;
	while (i < np)
	{
		new_philosopher = create_new_philosopher(i, current, checks);
		if (!new_philosopher)
			return (NULL);
		if (current)
			current->next = new_philosopher;
		else
			head = new_philosopher;
		current = new_philosopher;
		i++;
	}
	if (current)
	{
		current->next = head;
		head->prev = current;
	}
	return (head);
}

static void	assign_forks(t_table *table)
{
	t_philosopher	*current;
	int				i;

	i = 0;
	current = table->philosophers;
	while (i < table->num_philosophers)
	{
		current->l_fork = &table->forks[i];
		current->r_fork = &table->forks[(i + 1) % table->num_philosophers];
		current = current->next;
		i++;
	}
}

t_table	*init_table(int np, t_check_up *checks)
{
	t_table	*table;
	int		i;

	i = 0;
	table = malloc(sizeof(t_table));
	if (!table)
		return (NULL);
	table->num_philosophers = np;
	table->philosophers = init_philosophers(np, checks);
	table->forks = malloc(sizeof(pthread_mutex_t) * np);
	if (!table->philosophers || !table->forks)
	{
		free_table(table, np);
		return (NULL);
	}
	while (i < np)
		pthread_mutex_init(&table->forks[i++], NULL);
	assign_forks(table);
	return (table);
}

int	init_checkup(t_check_up *checks, long long start, char **av)
{
	pthread_mutex_t	*printer;

	printer = get_printer_mutex();
	checks->philo_numbers = ft_atoi(av[1]);
	checks->death_time_limit = ft_atoi(av[2]);
	checks->eat_time = ft_atoi(av[3]);
	checks->sleep_time = ft_atoi(av[4]);
	checks->max_meals = ft_atoi(av[5]);
	checks->eaten = 0;
	checks->philo_dead = 0;
	checks->finish = 0;
	checks->st = start;
	checks->mut_print = printer;
	return (1);
}
