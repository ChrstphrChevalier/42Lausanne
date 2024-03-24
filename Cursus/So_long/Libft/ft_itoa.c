/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 18:23:10 by waziz             #+#    #+#             */
/*   Updated: 2023/10/26 11:41:21 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_nbc(int n)
{
	size_t	i;

	i = 1;
	while (n / 10 != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*strnum;
	size_t		nbc;
	long int	num;

	num = n;
	nbc = ft_nbc(n);
	if (n < 0)
	{
		num *= -1;
		nbc++;
	}
	strnum = malloc((nbc + 1) * sizeof(char));
	if (!strnum)
		return (0);
	*(strnum + nbc) = '\0';
	while (nbc--)
	{
		*(strnum + nbc) = (num % 10) + 48;
		num = num / 10;
	}
	if (n < 0)
		strnum[0] = '-';
	return (strnum);
}
