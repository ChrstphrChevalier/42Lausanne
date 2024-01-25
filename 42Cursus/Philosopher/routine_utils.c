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
	if (philosophe->ID % 2 == 0 && philosophe->my_grp->eaten == 1
		&& philosophe->num_philo > 1){
		if (sem_wait(philosophe->my_grp->even_grp) == -1)
			ft_printf("Error : sem_wait->even_grp.\n");
	}
	if (philosophe->ID % 2 != 0 && philosophe->my_grp->eaten == 0
		&& philosophe->num_philo > 1){
		if (sem_wait(philosophe->my_grp->odd_grp) == -1)
			ft_printf("Error : sem_wait->odd_grp.\n");
	}
}

void	posting_sem(t_philosopher *philosophe)
{
	philosophe->my_grp->philo_passed++;
	while (philosophe->my_grp->eaten == 1 && philosophe->num_philo > 1){
		if (philosophe->my_grp->philo_passed == (philosophe->num_philo + 1) / 2){
			philosophe->my_grp->eaten = 0;
			philosophe->my_grp->philo_passed = 0;
			sem_post(philosophe->my_grp->even_grp);
		}
		else if (philosophe->my_grp->eaten == 0
				|| philosophe->meals_eaten == philosophe->max_meals)
			break ;
	}
	while (philosophe->my_grp->eaten == 0 && philosophe->num_philo > 1){
		if (philosophe->my_grp->philo_passed == (philosophe->num_philo) / 2){
			philosophe->my_grp->eaten = 1;
			philosophe->my_grp->philo_passed = 0;
			sem_post(philosophe->my_grp->odd_grp);
		}
		else if (philosophe->my_grp->eaten == 1
				|| philosophe->meals_eaten == philosophe->max_meals)
			break ;
	}
}

static long long	timestamp(void)
{
	struct timeval    tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	ft_usleep(long int ms)
{
	long int	t;
	t = timestamp();
	while (1)
	{
		if (timestamp() - t >= ms)
			break ;
		usleep(50);
	}
}
