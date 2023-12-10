/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 15:16:26 by waziz             #+#    #+#             */
/*   Updated: 2023/09/18 15:16:49 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <unistd.h>

int	*ft_range(int min, int max)
{
	int	*tableau;
	int	i;

	i = 0;
	if (min >= max)
		return (0);
	tableau = malloc((max - min) * sizeof(int));
	if (tableau == NULL)
		return (0);
	while (min < max)
	{
			tableau[i] = min;
			min++;
			i++;
	}
	return (tableau);
}
