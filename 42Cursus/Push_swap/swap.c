/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:08:22 by waziz             #+#    #+#             */
/*   Updated: 2023/12/12 13:23:25 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_swap(int *stack, int stack_len)
{
	int	swap;

	if (stack_len > 1)
	{
		swap = stack[0];
		stack[0] = stack[1];
		stack[1] = swap;
		return (1);
	}
	return (0);
}

void	ft_sa(t_stacks *ab)
{
	if (ft_swap(ab->a, ab->a_len))
		write (1, "sa\n", 3);
}

void	ft_sb(t_stacks *ab)
{
	if (ft_swap(ab->b, ab->b_len))
		write (1, "sb\n", 3);
}

void	ft_ss(t_stacks *ab)
{
	if (ft_swap(ab->a, ab->a_len) || ft_swap(ab->b, ab->b_len))
		write (1, "ss\n", 3);
}
