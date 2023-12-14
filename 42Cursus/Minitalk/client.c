/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 13:09:10 by waziz             #+#    #+#             */
/*   Updated: 2023/12/14 13:25:36 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send_pid(char *client, int server)
{
	size_t	i;
	int		bit;

	i = -1;
	while (++i <= ft_strlen(client))
	{
		bit = 0;
		while (bit < 8)
		{
			if (((client[i] >> bit & 1)) == 0)
				kill(server, SIGUSR2);
			else if (((client[i] >> bit) & 1) == 1)
				kill(server, SIGUSR1);
			bit++;
			usleep(80);
		}
	}
}

static void	send_msg(char *client, int server, char *msg)
{
	size_t	i;
	int		bit;

	send_pid(client, server);
	i = -1;
	while (++i <= ft_strlen(msg))
	{
		bit = 0;
		while (bit < 8)
		{
			if (((msg[i] >> bit & 1)) == 0)
				kill(server, SIGUSR2);
			else if (((msg[i] >> bit) & 1) == 1)
				kill(server, SIGUSR1);
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

int	main(int argc, char **argv)
{
	pid_t	server;
	char	*client;

	if (argc == 3 && argv[1][0] && argv[2][0])
	{
		client = ft_itoa(getpid());
		server = atoi(argv[1]);
		if (server < 0)
		{
			ft_printf("Error !\nProcess ID is invalid.\n");
			return (0);
		}
		send_msg(client, server, argv[2]);
		signal(SIGUSR1, receive_confirmation);
		while (1)
			pause();
	}
	else
		ft_printf("Error Usage : ./client PID Message.\n");
	return (0);
}
