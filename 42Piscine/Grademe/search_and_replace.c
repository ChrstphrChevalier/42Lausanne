/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 16:56:16 by waziz             #+#    #+#             */
/*   Updated: 2023/09/14 18:07:19 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void *search_and_replace(char *str, char *a, char *b)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == *a)
		{
			str[i] = *b;
		}
		i++;
	}
	return (str);
}

void *ft_putstr(char *str)
{
	int j;

	j = 0;
	while (str[j])
	{
		write (1, &str[j], 1);
		j++;
	}
	return (str);
}

int main (int argc, char **argv)
{
	if (argc != 4)
	{
		write (1, "\n", 1);
		return (0);
	}
	if (argc == 4 && argv[2][1] == '\0' && argv[3][1] == '\0')
		ft_putstr(search_and_replace(argv[1], argv[2], argv[3]));
	write (1, "\n", 1);
	return (0);
}
