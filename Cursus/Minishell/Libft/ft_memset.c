/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 00:02:04 by waziz             #+#    #+#             */
/*   Updated: 2023/12/13 18:24:01 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	int				i;
	unsigned char	*str;

	str = (unsigned char *) s;
	i = 0;
	while (n)
	{
		str[i] = (unsigned char) c;
		i++;
		n--;
	}
	return (s);
}
