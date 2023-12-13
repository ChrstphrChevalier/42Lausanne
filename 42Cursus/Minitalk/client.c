/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:32:36 by waziz             #+#    #+#             */
/*   Updated: 2023/12/13 14:12:53 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send_pid(char *c_pid, int s_pid)
{
	size_t	i;
	int		bit;

	i = -1;
	while (++i <= ft_strlen(c_pid))
	{
		bit = 0;
		while (bit < 8)
		{
			if (((c_pid[i] >> bit & 1)) == 0)
				kill(s_pid, SIGUSR2);
			else if (((c_pid[i] >> bit) & 1) == 1)
				kill(s_pid, SIGUSR1);
			bit++;
			usleep(80);
		}
	}
}

static void	send_msg(char *c_pid, int s_pid, char *message)
{
	size_t	i;
	int		bit;

	send_pid(c_pid, s_pid);
	i = -1;
	while (++i <= ft_strlen(message))
	{
		bit = 0;
		while (bit < 8)
		{
			if (((message[i] >> bit & 1)) == 0)
				kill(s_pid, SIGUSR2);
			else if (((message[i] >> bit) & 1) == 1)
				kill(s_pid, SIGUSR1);
			bit++;
			usleep(80);
		}
	}
}

static void	receive_confirmation(int signum)
{
	if (signum == SIGUSR1)
		ft_printf("Message received !\n");
	exit(0);
}

int	main(int ac, char **av)
{
	pid_t	pid;
	char	*str;

	if (ac == 3 && av[1][0] && av[2][0])
	{
		str = ft_itoa(getpid());
		pid = atoi(av[1]);
		if (pid < 0)
		{
			ft_printf("Error !\nProcess ID is invalid.\n");
			return (0);
		}
		send_msg(str, pid, av[2]);
		signal(SIGUSR1, receive_confirmation);
		while (1)
			pause();
	}
	else
		ft_printf("Error !\nUsage : ./client process_id message.\n");
	return (0);
}
