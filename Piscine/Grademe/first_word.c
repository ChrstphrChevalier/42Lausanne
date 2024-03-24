/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:07:54 by waziz             #+#    #+#             */
/*   Updated: 2023/09/14 19:55:55 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

char *first_word(char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (str[i] == '\0')
	{
		write (1, "\n", 1);
		return (0);
	}

	while(str[i])
	{
		if (str[i] >= 0 && str[i] <= 32 || str[i] == 127)
	             i++;
		if  (str[i] >= 33 && str[i] <= 126)
		{
			write (1, &str[j], 1);
			i++;
			j++;
		}
		if (str[j] >= 0 && str[j] <= 32 
				|| str[j] == 127)
			return (str);
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

	first_word(argv[1]);
	write (1, "\n", 1);
	return (0);
}


