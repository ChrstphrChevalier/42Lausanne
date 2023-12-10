/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 03:04:51 by waziz             #+#    #+#             */
/*   Updated: 2023/09/21 17:37:52 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void ft_swap(int *a, int *b)
{
	int swap;

	swap = *a;
	*a = *b;
	*b = swap;
}

int	max(int* tab, unsigned int len)
{
	int i;
	int a;

	if (tab[i] == '\0')
		return (0);

	i = 0;
	while (i < len)
	{
		if (tab[i] - tab[i + 1] > 0)
		{
			ft_swap(&tab[i], &tab[i+1]);
			i = 0;
		}
		else
			i++;
	}
	i--;
	a = tab[i];
	return (a);
}
