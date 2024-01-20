/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 12:31:31 by waziz             #+#    #+#             */
/*   Updated: 2024/01/20 12:31:33 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

pthread_mutex_t	*get_printer_mutex(void)
{
	static pthread_mutex_t	printer = PTHREAD_MUTEX_INITIALIZER;

	return (&printer);
}

void	waiting_sem(t_philosopher *philosophe)
{
	if (philosophe->ID % 2 == 0 && philosophe->my_grp->eaten == 0){
		if (sem_wait(philosophe->my_grp->even_grp) == -1)
			ft_printf("Error : sem_wait->even_grp.\n");
	}
	if (philosophe->my_grp->eaten == 1){
		if (sem_wait(philosophe->my_grp->odd_grp) == -1)
			ft_printf("Error : sem_wait->odd_grp.\n");
	}
}

void	posting_sem(t_philosopher *philosophe)
{
	if (philosophe->my_grp->eaten == 0){
		if (philosophe->ID == philosophe->num_philo -1
			|| philosophe->ID == philosophe->num_philo - 2){
			philosophe->my_grp->eaten = 1;
			sem_post(philosophe->my_grp->even_grp);
		}
	}
	else{
		if (philosophe->ID == philosophe->num_philo - 1
			|| philosophe->ID == philosophe->num_philo - 2){
			philosophe->my_grp->eaten = 0;
			sem_post(philosophe->my_grp->odd_grp);
		}
	}
}
