/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:46:05 by waziz             #+#    #+#             */
/*   Updated: 2023/12/12 13:22:06 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_reverse_rotate(int *stack, int stack_len)
{
	int	rr;
	int	i;

	if (stack_len > 1)
	{
		i = stack_len;
		rr = stack[i - 1];
		while (--i > 0)
			stack[i] = stack[i - 1];
		stack[0] = rr;
		return (1);
	}
	return (0);
}

void	ft_rra(t_stacks *ab)
{
	if (ft_reverse_rotate(ab->a, ab->a_len))
		write (1, "rra\n", 4);
}

void	ft_rrb(t_stacks *ab)
{
	if (ft_reverse_rotate(ab->b, ab->b_len))
		write (1, "rrb\n", 4);
}

void	ft_rrr(t_stacks *ab)
{
	if (ft_reverse_rotate(ab->a, ab->a_len)
		|| ft_reverse_rotate(ab->b, ab->b_len))
		write (1, "rrr\n", 4);
}
