/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 10:10:24 by waziz             #+#    #+#             */
/*   Updated: 2023/11/04 10:10:26 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdint.h>

int	ft_printf(const char *input, ...);
int	ft_conv_hexmaj(unsigned int n);
int	ft_conv_hexmin(unsigned int n);
int	ft_conv_adress(uintptr_t n);
int	ft_putnbr(long n);
int	ft_putunbr(unsigned int un);

int	ft_print_c(char c);
int	ft_print_d(long n);
int	ft_print_p(uintptr_t adress);
int	ft_print_s(char *s);
int	ft_print_u(unsigned int n);
int	ft_print_xmaj(unsigned int n);
int	ft_print_xmin(unsigned int n);

#endif
