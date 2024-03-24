/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_hexmin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 22:12:23 by waziz             #+#    #+#             */
/*   Updated: 2023/12/13 18:27:28 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conv_hexmin(unsigned int n)
{
	int		count;
	char	*hexmin;

	count = 0;
	hexmin = "0123456789abcdef";
	if (n >= 16)
	{
		count += ft_conv_hexmin(n / 16);
		count += ft_conv_hexmin(n % 16);
	}
	else
		count += ft_print_c(hexmin[n]);
	if (count < 0)
		return (-1);
	return (count);
}
