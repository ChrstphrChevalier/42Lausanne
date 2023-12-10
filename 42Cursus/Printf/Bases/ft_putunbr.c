/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:20:28 by waziz             #+#    #+#             */
/*   Updated: 2023/11/02 13:20:30 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunbr(unsigned int un)
{
	int	count;

	count = 0;
	if (un >= 10)
	{
		count += ft_putunbr(un / 10);
		count += ft_putunbr(un % 10);
	}
	else
		count += ft_print_c(un + 48);
	if (count < 0)
		return (-1);
	return (count);
}
