/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   from_two_to_five.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:47:35 by waziz             #+#    #+#             */
/*   Updated: 2023/12/12 13:17:59 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_max(int compare, t_stacks *ab)
{
	int	i;

	i = 0;
	while (i < ab->a_len)
	{
		if (compare < ab->a[i])
			return (0);
		i++;
	}
	return (1);
}

static void	sort_three(t_stacks *ab)
{
	if (!ft_sorted(ab->a, ab->a_len) && is_max(ab->a[2], ab))
		ft_sa(ab);
	else if (!ft_sorted(ab->a, ab->a_len) && is_max(ab->a[0], ab))
	{
		ft_ra(ab);
		if (!ft_sorted(ab->a, ab->a_len))
			ft_sa(ab);
	}
	else if (!ft_sorted(ab->a, ab->a_len) && is_max(ab->a[1], ab))
	{
		ft_rra(ab);
		if (!ft_sorted(ab->a, ab->a_len))
			ft_sa(ab);
	}
}

static void	sort_four(t_stacks *ab)
{
	if (is_max(ab->a[3], ab))
		ft_rra(ab);
	else if (is_max(ab->a[1], ab) || is_max(ab->a[2], ab))
	{
		if (is_max(ab->a[2], ab))
			ft_ra(ab);
		ft_ra(ab);
	}
	ft_pb(ab);
	sort_three(ab);
	ft_pa(ab);
	ft_ra(ab);
}

static void	sort_five(t_stacks *ab)
{
	if (is_max(ab->a[3], ab) || is_max(ab->a[4], ab))
	{
		if (is_max(ab->a[3], ab))
			ft_rra(ab);
		ft_rra(ab);
	}
	else if (is_max(ab->a[1], ab) || is_max(ab->a[2], ab))
	{
		if (is_max(ab->a[2], ab))
			ft_ra(ab);
		ft_ra(ab);
	}
	ft_pb(ab);
	sort_four(ab);
	ft_pa(ab);
	ft_ra(ab);
}

void	from_two_to_five(t_stacks *ab)
{
	if (ab->a_len == 2)
		ft_sa(ab);
	else if (ab->a_len == 3)
		sort_three(ab);
	else if (ab->a_len == 4)
		sort_four(ab);
	else
		sort_five(ab);
}
