/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 13:16:46 by waziz             #+#    #+#             */
/*   Updated: 2023/12/14 13:22:39 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_sigbits	mt;

static void	set_pid(void)
{
	if (mt.c)
	{
		mt.pid *= 10;
		mt.pid += mt.c - 48;
	}
	else
		mt.received_pid = 1;
	mt.c = 0;
	mt.bit = 0;
}

static void	receive_msg(int signum)
{
	if (signum == SIGUSR1)
		mt.c |= (1 << mt.bit++);
	else if (signum == SIGUSR2)
		mt.bit++;
	if (mt.bit == 8 && !mt.received_pid)
		set_pid();
	else if (mt.bit == 8 && mt.received_pid == 1)
	{
		if (mt.c)
			ft_printf("%c", mt.c);
		else
		{
			ft_printf("\n");
			mt.received_pid = 0;
			usleep(200);
			kill(mt.pid, SIGUSR1);
			mt.pid = 0;
		}
		mt.c = 0;
		mt.bit = 0;
	}
}

int	main(void)
{
	mt.pid = 0;
	mt.received_pid = 0;
	mt.bit = 0;
	ft_printf("My process ID is : %d\n", getpid());
	signal(SIGUSR1, receive_msg);
	signal(SIGUSR2, receive_msg);
	while (1)
		pause();
}
