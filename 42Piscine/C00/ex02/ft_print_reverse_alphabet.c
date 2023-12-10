/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 17:29:57 by waziz             #+#    #+#             */
/*   Updated: 2023/09/03 13:18:15 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_reverse_alphabet(void)
{
	char	lettre;

	lettre = 'z';
	while (lettre >= 'a')
	{
		write (1, &lettre, 1);
	lettre--;
	}
}

/*
int main ()
{
	ft_print_reverse_alphabet(); // idem ex01
	return (0);
}
*/
