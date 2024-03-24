/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 15:16:49 by waziz             #+#    #+#             */
/*   Updated: 2023/11/02 15:16:53 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_p(uintptr_t adress)
{
	int	count;

	count = 0;
	count += ft_print_s("0x");
	if (count < 0)
		return (-1);
	count += ft_conv_adress(adress);
	if (count < 0)
		return (-1);
	return (count);
}
