/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 17:35:24 by waziz             #+#    #+#             */
/*   Updated: 2023/09/12 11:44:07 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str [i])
	{
		i++;
	}
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	j;

	j = 0;
	while (src[j])
	{
	dest[j] = src[j];
	j++;
	}
	dest[j] = '\0';
	return (dest);
}

char	*ft_strdup(char *src)
{
	char	*dynam;

	if (!src)
		return (0);
	dynam = malloc((ft_strlen(src)) * sizeof(char));
	if (dynam)
		return (ft_strcpy(dynam, src));
	else
		return (0);
}
