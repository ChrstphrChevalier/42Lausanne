/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:09:28 by waziz             #+#    #+#             */
/*   Updated: 2023/09/18 18:01:55 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_alphabet(void)
{	
	char	lettre;

lettre = 'a';
	while (lettre <= 'z')
	{
		write (1, &lettre, 1);
		lettre++;
	}	
}
