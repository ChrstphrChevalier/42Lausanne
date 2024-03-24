/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:51:21 by waziz             #+#    #+#             */
/*   Updated: 2023/12/12 13:21:25 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	simplify_stack(t_stacks *ab, int i, int j)
{
	int	*simplify;
	int	simple;

	simplify = malloc(ab->a_len * sizeof(int));
	if (!simplify)
		return ;
	while (++i < ab->a_len)
	{
		simple = 0;
		j = -1;
		while (++j < ab->a_len)
		{
			if (ab->a[i] > ab->a[j])
				simple++;
			simplify[i] = simple;
		}
	}
	i = 0;
	while (i < ab->a_len)
	{
		ab->a[i] = simplify[i];
		i++;
	}
	free(simplify);
}

static int	bigger_bit(t_stacks *ab)
{
	int	i;
	int	j;

	i = 31;
	while (i >= 0)
	{
		j = -1;
		while (++j < ab->a_len)
			if ((ab->a[j] & 1 << i) == 1 << i)
				return (i);
		i--;
	}
	return (0);
}

void	radix_sort(t_stacks *ab)
{
	int	i;
	int	j;
	int	bb;
	int	alen;

	i = 0;
	alen = ab->a_len;
	simplify_stack(ab, -1, -1);
	bb = bigger_bit(ab);
	while (i <= bb)
	{
		j = -1;
		while (++j < alen && !ft_sorted(ab->a, ab->a_len))
		{
			if (((ab->a[0] >> i) & 1) == 1)
				ft_ra(ab);
			else
				ft_pb(ab);
		}
		while (ab->b_len)
			ft_pa(ab);
		i++;
	}
}
