/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:02:28 by waziz             #+#    #+#             */
/*   Updated: 2023/11/02 13:02:30 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
		count += ft_print_s("-2147483648");
	else if (n < 0)
	{
		count += ft_print_c('-');
		n *= -1;
		count += ft_putnbr(n);
	}
	else
	{
		if (n >= 10)
		{
			count += ft_putnbr(n / 10);
			count += ft_putnbr(n % 10);
		}
		else
			count += ft_print_c(n + 48);
	}
	if (count < 0)
		return (-1);
	return (count);
}
