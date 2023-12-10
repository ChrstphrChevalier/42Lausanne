/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_adress.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 22:08:57 by waziz             #+#    #+#             */
/*   Updated: 2023/11/08 22:09:00 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conv_adress(uintptr_t n)
{
	int	count;
	char	*hex;

	count = 0;
	hex = "0123456789abcdef";
	if (n >= 16)
	{
		count += ft_conv_adress(n / 16);
		count += ft_conv_adress(n % 16);
	}
	else
		count += ft_print_c(hex[n]);
	if (count < 0)
		return (-1);
	return (count);
}
