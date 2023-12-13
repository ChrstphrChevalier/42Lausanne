/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:27:43 by waziz             #+#    #+#             */
/*   Updated: 2023/10/26 12:30:34 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*dynam;
	int		i;

	i = 0;
	dynam = malloc((ft_strlen(str) + 1) * sizeof(char));
	if (dynam)
	{
		while (str[i])
		{
			dynam[i] = (char)str[i];
			i++;
		}
		dynam[i] = '\0';
		return (dynam);
	}
	else
		return (0);
}
