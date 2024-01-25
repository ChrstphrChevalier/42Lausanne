/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_xmin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:02:21 by waziz             #+#    #+#             */
/*   Updated: 2023/11/02 16:02:23 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_xmin(unsigned int n)
{
	int	count;

	count = 0;
	count += ft_conv_hexmin(n);
	if (count < 0)
		return (-1);
	return (count);
}
