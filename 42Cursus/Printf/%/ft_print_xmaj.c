/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_xmaj.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 22:27:52 by waziz             #+#    #+#             */
/*   Updated: 2023/11/02 22:27:55 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_xmaj(unsigned int n)
{
	int	count;

	count = 0;
	count += ft_conv_hexmaj(n);
	if (count < 0)
		return (-1);
	return (count);
}
