/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 12:31:55 by waziz             #+#    #+#             */
/*   Updated: 2024/02/05 00:45:02 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static int	check_state(t_philosopher *p)
{
	if (p->check->finish == p->check->philo_numbers
		|| p->check->philo_dead == 1)
		return (1);
	return (0);
}

static int	check_args(char **av)
{
	if (ft_atoi(av[1]) < 1)
		return (0);
	if (ft_atoi(av[2]) < 1)
		return (0);
	if (ft_atoi(av[3]) < 0)
		return (0);
	if (ft_atoi(av[4]) < 0)
		return (0);
	if (av[5])
	{
		if (ft_atoi(av[5]) < 1)
			return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	long long	start_time;
	t_table		*table;
	t_check_up	checks;
	long		num_philosophers;

	start_time = timestamp();
	if (ac < 5 || ac > 6)
	{
		ft_printf("Error Usage : ./Exe Nbr_philo T_dead T_eat T_sleep.\n");
		return (0);
	}
	num_philosophers = ft_atoi(av[1]);
	if (!check_args(av))
	{
		ft_printf("Error : One or more arguments are invalid!\n");
		return (0);
	}
	if (!init_checkup(&checks, start_time, av))
		return (0);
	table = init_table(num_philosophers, &checks);
	if (philosopher_by_thread(table) != 1 || check_state(table->philosophers))
		return (free_table(table, num_philosophers));
	return (0);
}
