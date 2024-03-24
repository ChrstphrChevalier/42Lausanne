/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:57:17 by waziz             #+#    #+#             */
/*   Updated: 2023/10/26 12:29:26 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int value, size_t num)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char *) ptr;
	i = 0;
	while (i < num)
	{
		if (str[i] == (unsigned char)value)
			return (&str[i]);
		i++;
	}
	return (0);
}
