/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_hexmaj.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:08:32 by waziz             #+#    #+#             */
/*   Updated: 2023/11/02 14:08:35 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conv_hexmaj(unsigned int n)
{
	int	count;
	char	*hexmaj;

	count = 0;
	hexmaj = "0123456789ABCDEF";
	if (n >= 16)
	{
		count += ft_conv_hexmaj(n / 16);
		count += ft_conv_hexmaj(n % 16);
	}
	else
		count += ft_print_c(hexmaj[n]);
	if (count < 0)
		return (-1);
	return (count);
}
