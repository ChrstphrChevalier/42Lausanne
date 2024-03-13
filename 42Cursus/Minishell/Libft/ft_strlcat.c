/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 16:14:43 by jhadji            #+#    #+#             */
/*   Updated: 2023/10/26 12:01:55 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int		i;
	int		j;
	size_t	len_dest;
	size_t	len_src;

	i = 0;
	j = 0;
	while (dst[i] != '\0')
		i++;
	len_dest = i;
	len_src = ft_strlen(src);
	if (size <= len_dest || size == 0)
		return (len_src + size);
	size -= len_dest;
	while ((src[j] != '\0') && ((size_t)j < size - 1))
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (len_dest + len_src);
}
