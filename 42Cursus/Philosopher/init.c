/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 12:32:15 by waziz             #+#    #+#             */
/*   Updated: 2024/01/20 12:32:17 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static t_philosopher	*create_new_philosopher(int i,
		t_philosopher *current, t_sem_grp *sem_grps)
{
	t_philosopher	*new_philosopher;

	new_philosopher = malloc(sizeof(t_philosopher));
	if (!new_philosopher)
		return (NULL);
	new_philosopher->ID = i;
	if (i % 2 == 0)
		new_philosopher->check_forks = 0;
	else
		new_philosopher->check_forks = 1;
	new_philosopher->state = THINKING;
	new_philosopher->meals_eaten = 0;
	new_philosopher->max_meals = 10;
	new_philosopher->death_time_limit = 10000000;
	new_philosopher->my_grp = sem_grps;
	new_philosopher->l_fork = NULL;
	new_philosopher->r_fork = NULL;
	new_philosopher->next = NULL;
	new_philosopher->prev = current;
	return (new_philosopher);
}

static t_philosopher	*init_philosophers(int num_philosophers, t_sem_grp *sem_grps)
{
	t_philosopher	*head;
	t_philosopher	*current;
	t_philosopher	*new_philosopher;
	int		i;

	head = NULL;
	current = NULL;
	i = 0;
	while (i < num_philosophers){
		new_philosopher = create_new_philosopher(i, current, sem_grps);
		if (!new_philosopher)
			return (NULL);
		new_philosopher->num_philo = num_philosophers;
		if (current)
			current->next = new_philosopher;
		else
			head = new_philosopher;
		current = new_philosopher;
		i++;
	}
	if (current){
		current->next = head;
		head->prev = current;
	}
	return (head);
}

static void	assign_forks(t_table *table)
{
	t_philosopher	*current;
	int		i;

	i = 0;
	current = table->philosophers;
	while (i < table->num_philosophers){
		current->l_fork = &table->forks[i];
		current->r_fork = &table->forks[(i + 1) % table->num_philosophers];
		current = current->next;
		i++;
	}
}

t_table	*init_table(int num_philosophers, t_sem_grp *sem_grps)
{
	t_table	*table;
	int	i;

	i = 0;
	table = malloc(sizeof(t_table));
	if (!table)
		return (NULL);
	table->num_philosophers = num_philosophers;
	table->philosophers = init_philosophers(num_philosophers, sem_grps);
	table->forks = malloc(sizeof(pthread_mutex_t) * num_philosophers);
	if (!table->philosophers || !table->forks){
		free_table(table, num_philosophers);
		return (NULL);
	}
	while (i < num_philosophers)
		pthread_mutex_init(&table->forks[i++], NULL);
	assign_forks(table);
	return (table);
}
