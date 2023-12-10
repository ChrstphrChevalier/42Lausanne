/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 19:59:44 by waziz             #+#    #+#             */
/*   Updated: 2023/09/14 20:19:37 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void *rev_print(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	i--;
	while (i >= 0)
	{
		write (1, &str[i], 1);
		i--;
	}
	return (str);
}

int main (int argc, char **argv)
{
	if (argc != 2)
	{
		write (1, "\n", 1);
		return (0);
	}

	rev_print(argv[1]);
	write (1, "\n", 1);
	return (0);
}
