/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 22:37:26 by waziz             #+#    #+#             */
/*   Updated: 2023/12/13 16:29:00 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check_args(const char *str, va_list a, int i)
{
	int	count;

	count = 0;
	if (str[i] == 'c')
		count += ft_print_c((char) va_arg(a, int));
	else if (str[i] == 's')
		count += ft_print_s((char *) va_arg(a, char *));
	else if (str[i] == 'p')
		count += ft_print_p((uintptr_t) va_arg(a, uintptr_t));
	else if (str[i] == 'd' || str[i] == 'i')
		count += ft_print_d((int) va_arg(a, int));
	else if (str[i] == 'u')
		count += ft_print_u((unsigned int) va_arg(a, unsigned int));
	else if (str[i] == 'x')
		count += ft_conv_hexmin((unsigned int) va_arg(a, unsigned int));
	else if (str[i] == 'X')
		count += ft_conv_hexmaj((unsigned int) va_arg(a, unsigned int));
	else if (str[i] == '%')
		count += ft_print_c('%');
	return (count);
}

int	ft_printf(const char *input, ...)
{
	va_list	args;
	int		i;
	int		count;

	va_start(args, input);
	i = 0;
	count = 0;
	while (input[i])
	{
		if (input[i] == '%')
		{
			count += ft_check_args(input, args, ++i);
			if (count < 0)
				return (-1);
		}
		else
		{
			count += ft_print_c(input[i]);
			if (count < 0)
				return (-1);
		}
		i++;
	}
	va_end(args);
	return (count);
}
