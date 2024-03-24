/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:02:40 by waziz             #+#    #+#             */
/*   Updated: 2023/12/12 13:22:39 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_rotate(int *stack, int stack_len)
{
	int	rotate;
	int	i;

	i = 0;
	if (stack_len > 1)
	{
		rotate = stack[0];
		while (i + 1 < stack_len)
		{
			stack[i] = stack[i + 1];
			i++;
		}
		stack[i] = rotate;
		return (1);
	}
	return (0);
}

void	ft_ra(t_stacks *ab)
{
	if (ft_rotate(ab->a, ab->a_len))
		write (1, "ra\n", 3);
}

void	ft_rb(t_stacks *ab)
{
	if (ft_rotate(ab->b, ab->b_len))
		write (1, "rb\n", 3);
}

void	ft_rr(t_stacks *ab)
{
	if (ft_rotate(ab->a, ab->a_len) || ft_rotate(ab->b, ab->b_len))
		write (1, "rr\n", 3);
}
