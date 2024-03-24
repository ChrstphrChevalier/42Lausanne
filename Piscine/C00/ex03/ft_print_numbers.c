/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 20:29:04 by waziz             #+#    #+#             */
/*   Updated: 2023/09/03 13:23:06 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_numbers(void)
{
	int		chiffre;

	chiffre = 48;
	while (chiffre <= 57)
	{
		write (1, &chiffre, 1);
		chiffre++;
	}
}
/*
int main()
{
	ft_print_numbers(); // idem ex02
	return(0);
}
*/
