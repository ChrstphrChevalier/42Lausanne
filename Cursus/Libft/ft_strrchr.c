/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 15:37:16 by waziz             #+#    #+#             */
/*   Updated: 2023/10/26 01:53:25 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*s;
	char	occurence;
	int		i;

	occurence = (char)c;
	i = ft_strlen(str);
	s = (char *)str;
	while (i > 0)
	{
		if (s[i] == occurence)
			return (s + i);
		i--;
	}
	if (s[i] == occurence)
		return (s);
	return (0);
}
