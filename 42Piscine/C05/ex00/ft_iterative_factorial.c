/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 10:58:43 by waziz             #+#    #+#             */
/*   Updated: 2023/09/06 19:25:53 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	ft_iterative_factorial(int nb)
{
	int	resultat;
	int	i;

	resultat = 1;
	i = 1;
	if (nb < 0)
		return (0);
	while (i <= nb)
	{
		resultat *= i;
		i++;
	}
	return (resultat);
}
