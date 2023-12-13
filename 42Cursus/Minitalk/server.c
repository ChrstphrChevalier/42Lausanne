/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 16:10:04 by waziz             #+#    #+#             */
/*   Updated: 2023/12/13 14:05:28 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_list2	g_msg;

static void	set_pid(void)
{
	if (g_msg.c)
	{
		g_msg.pid *= 10;
		g_msg.pid += g_msg.c - 48;
	}
	else
		g_msg.trigger = 1;
	g_msg.c = 0;
	g_msg.bit = 0;
}

static void	receive_msg(int signum)
{
	if (signum == SIGUSR1)
		g_msg.c |= (1 << g_msg.bit++);
	else if (signum == SIGUSR2)
		g_msg.bit++;
	if (g_msg.bit == 8 && !g_msg.trigger)
		set_pid();
	else if (g_msg.bit == 8 && g_msg.trigger == 1)
	{
		if (g_msg.c)
			ft_printf("%c", g_msg.c);
		else
		{
			ft_printf("\n");
			g_msg.trigger = 0;
			usleep(200);
			kill(g_msg.pid, SIGUSR1);
			g_msg.pid = 0;
		}
		g_msg.c = 0;
		g_msg.bit = 0;
	}
}

int	main(void)
{
	g_msg.pid = 0;
	g_msg.trigger = 0;
	g_msg.bit = 0;
	ft_printf("My process ID is : %d\n", getpid());
	signal(SIGUSR1, receive_msg);
	signal(SIGUSR2, receive_msg);
	while (1)
		pause();
}
