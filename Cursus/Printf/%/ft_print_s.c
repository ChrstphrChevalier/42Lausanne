/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:09:46 by waziz             #+#    #+#             */
/*   Updated: 2023/12/13 18:26:17 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_s(char *s)
{
	int		count;
	char	*null;

	count = 0;
	if (!s)
	{
		null = "(null)";
		while (null[count])
		{
			if (ft_print_c(null[count]) == -1)
				return (-1);
			count++;
		}
	}
	else
	{
		while (s[count])
		{
			if (ft_print_c(s[count]) == -1)
				return (-1);
			count++;
		}
	}
	return (count);
}
