/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 15:15:59 by waziz             #+#    #+#             */
/*   Updated: 2023/09/13 15:57:20 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	swap;

	swap = *a;
	*a = *b;
	*b = swap;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;

	i = 0;
	size --;
	while (i < size)
	{
		if (tab[i] > tab[i + 1])
		{
			ft_swap (&tab[i], &tab[i + 1]);
			i = 0;
		}
		else
		i++;
	}
}	
