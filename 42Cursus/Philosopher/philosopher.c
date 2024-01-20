/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 12:31:55 by waziz             #+#    #+#             */
/*   Updated: 2024/01/20 12:31:57 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static int	philosopher_by_thread(t_table *table)
{
	pthread_t	*threads;
	t_philosopher	*current_philosopher;
	int		i;

	threads = malloc(sizeof(pthread_t) * table->num_philosophers);
	if (!threads)
		return (ft_error(1, threads));
	current_philosopher = table->philosophers;
	i = 0;
	while (i++ < table->num_philosophers){
		if (pthread_create(&threads[i], NULL,
			&routine_philosopher, (void *)current_philosopher) != 0)
			return (ft_error(2, threads));
		current_philosopher = current_philosopher->next;
	}
	i = 0;
	while (i++ < table->num_philosophers){
		if (pthread_join(threads[i], NULL) != 0)
			return (ft_error(3, threads));
	}
	free(threads);
	return (1);
}

static int	check_state(t_table *table)
{
	t_philosopher	*current_phil;

	current_phil = table->philosophers;
	while (current_phil != NULL
		&& (current_phil->meals_eaten < current_phil->max_meals)){
		if (current_phil->state == DEAD
			|| current_phil->meals_eaten == current_phil->max_meals)
			return (1);
		current_phil = current_phil->next;
		usleep (1000);
	}
	return (0);
}

static int	init_sem(t_sem_grp *sem_grps, int num_philosophers)
{
	int	size_grp;

	size_grp = (num_philosophers / 2) + (num_philosophers % 2);
	sem_grps->even_grp = sem_open("/even_sem", O_CREAT, 0644, size_grp);
	if (sem_grps->even_grp == SEM_FAILED){
		ft_printf("Failed to initialized even semaphore.\n");
		return (0);
	}
	sem_grps->odd_grp = sem_open("/odd_sem", O_CREAT, 0644, size_grp);
	if (sem_grps->odd_grp == SEM_FAILED){
		ft_printf("Failed to initialized odd semaphore.\n");
		sem_close(sem_grps->even_grp);
		sem_unlink("/even_sem");
		return (0);
	}
	sem_grps->eaten = 0;
	return (1);
}

static void	destroy_sem(t_sem_grp *sem_grps)
{
	sem_close(sem_grps->even_grp);
	sem_close(sem_grps->odd_grp);
	sem_unlink("/even_sem");
	sem_unlink("/odd_sem");
}

int	main(int ac, char **av)
{
	t_table		*table;
	t_sem_grp	sem_grps;
	int		num_philosophers;

	if (ac != 2){
		ft_printf("Error Usage : <Exe> <Numbers_of_philosophe> !\n");
		return (0);
	}
	num_philosophers = ft_atoi(av[1]);
	if (num_philosophers < 1){
		ft_printf("Error : <Numbers_of_philosophe> is not valid!\n");
		return (0);
	}
	if (!init_sem(&sem_grps, num_philosophers))
		return (0);
	table = init_table(num_philosophers, &sem_grps);
	if (philosopher_by_thread(table) != 1 || check_state(table))
		free_table(table, num_philosophers);
	destroy_sem(&sem_grps);
	return (0);
}
