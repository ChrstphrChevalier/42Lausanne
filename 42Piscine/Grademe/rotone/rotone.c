/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:17:12 by waziz             #+#    #+#             */
/*   Updated: 2023/09/20 15:03:02 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void ft_rotone(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= 'a' && str[i] <= 'y') || (str[i] >= 'A' && str[i] <= 'Y'))
		{
			str[i] += 1;
			write (1, &str[i], 1);
		}
		else if (str[i] == 'z')
		{
			str[i] = 'a';
			write (1, &str[i], 1);
		}
		else if (str[i] == 'Z')
		{
			str[i] = 'A';
			write (1, &str[i], 1);
		}
		else
			write (1, &str[i], 1);
		i++;
	}
}

int main(int argc, char **argv)
{
	int i;

	if ( argc != 2)
	{
		write (1, "\n", 1);
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		ft_rotone(argv[i]);
		write (1, "\n", 1);
		i++;
	}
	return (0);
}
