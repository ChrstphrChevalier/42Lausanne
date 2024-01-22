/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 12:31:04 by waziz             #+#    #+#             */
/*   Updated: 2024/01/20 12:31:07 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static int	free_philo(t_philosopher *head)
{
	t_philosopher	*tmp;

	if (head)
		head->prev->next = NULL;
	while (head != NULL){
		tmp = head;
		head = head->next;
		free(tmp);
	}
	return (0);
}

void	free_table(t_table *table, int num_philosophers)
{
	int	i;

	i = 0;
	if (table){
		if (table->philosophers)
			free_philo(table->philosophers);
		if (table->forks){
			while (i++ < num_philosophers)
				pthread_mutex_destroy(&table->forks[i]);
			free(table->forks);
		}
		free(table);
	}
}

int	ft_error(int error, pthread_t *threads)
{
	if (error == 1)
		ft_printf("Error : Allocated threads failed.\n");
	else if (error == 2){
		ft_printf("Error : Failed to create threads.\n");
		free(threads);
	}
	else if (error == 3){
		ft_printf("Error : Failed to join threads.\n");
		free(threads);
	}
	return (0);
}

long	ft_atoi(char *s)
{
	int	i;
	long	signe;
	long	resultat;

	i = 0;
	signe = 1;
	resultat = 0;
	if (s[i] == '-' || s[i] == '+'){
		if (s[i] == '-')
			signe *= -1;
		i++;
	}
	while (s[i] >= 48 && s[i] <= 57){
		resultat = (s[i] - 48) + (resultat * 10);
		i++;
	}
	return (resultat * signe);
}
