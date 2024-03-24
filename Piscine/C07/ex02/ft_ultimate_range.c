/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 18:11:10 by waziz             #+#    #+#             */
/*   Updated: 2023/09/11 19:56:27 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <unistd.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	*tableau;

	i = 0;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	tableau = malloc(sizeof(int) * (max - min));
	if (range == NULL)
		return (-1);
	while (min < max)
	{
		tableau[i] = min;
		min++;
		i++;
	}
	*range = tableau;
	return (i);
}
