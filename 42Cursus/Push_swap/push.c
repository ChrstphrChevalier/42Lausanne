/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:42:52 by waziz             #+#    #+#             */
/*   Updated: 2023/12/12 13:18:38 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_push(int *give, int *take, int *give_len, int *take_len)
{
	int	push;

	if (*give_len > 0)
	{
		push = give[0];
		ft_rotate(give, *give_len);
		*give_len -= 1;
		give[*give_len] = 0;
		take[*take_len] = push;
		*take_len += 1;
		ft_reverse_rotate(take, *take_len);
		return (1);
	}
	return (0);
}

void	ft_pa(t_stacks *ab)
{
	if (ft_push(ab->b, ab->a, &ab->b_len, &ab->a_len))
		write (1, "pa\n", 3);
}

void	ft_pb(t_stacks *ab)
{
	if (ft_push(ab->a, ab->b, &ab->a_len, &ab->b_len))
		write (1, "pb\n", 3);
}
