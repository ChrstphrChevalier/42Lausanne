/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 14:45:47 by waziz             #+#    #+#             */
/*   Updated: 2023/09/21 15:26:52 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void last_word(char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if ((str[i] >= 0 && str[i] <= 32) && (str[i + 1] >= 33 && str[i + 1] <= 126))
		{
			j = i + 1;
		}
		i++;
	}
	while (str[j] != '\0' && (str[j] >= 33 && str[j] <= 126))
	{
		write (1, &str[j], 1);
		j++;
	}
}

int main(int argc, char **argv)
{
	if (argc == 2)
		last_word(argv[1]);
}

