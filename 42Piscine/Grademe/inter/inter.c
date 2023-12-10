/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:04:56 by waziz             #+#    #+#             */
/*   Updated: 2023/09/20 16:00:30 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_inter(char *s1, char *s2)
{
	int tab[256] = {0};
	int i;

	i = 0;
	while (s2[i])
	{
		if (tab[(int)s2[i]] == 0)
		{
			tab[(int)s2[i]] = 1;
		}
		i++;
	}
	i = 0;
	while(s1[i])
	{
		if (tab[(int)s1[i]] == 1)
		{
			tab[(int)s1[i]] = 2;
			write (1, &s1[i], 1);
		}
		i++;
	}
}

int main(int argc, char **argv)
{
	if (argc != 3)
	{
		write (1, "\n", 1);
		return (0);
	}
	ft_inter(argv[1], argv[2]);
	write (1, "\n", 1);
	return (0);
}
