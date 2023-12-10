/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:38:04 by CC                #+#    #+#             */
/*   Updated: 2023/10/26 12:11:09 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;
	int			i;

	if (!dest && !src)
		return (0);
	d = dest;
	s = src;
	i = 0;
	while (n)
	{
		d[i] = s[i];
		i++;
		n--;
	}
	return (dest);
}
