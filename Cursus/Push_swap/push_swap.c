/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:39:35 by waziz             #+#    #+#             */
/*   Updated: 2023/12/12 13:19:11 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stacks	ab;

	if (argc > 1)
	{
		if ((argc == 2 && !argv[1][0])
		|| !ft_init_stacks(&ab, argv + 1, --argc, 0))
			return (0);
		if (ft_sorted(ab.a, ab.a_len))
		{
			ft_free(&ab, argc);
			return (0);
		}
		if (ab.a_len <= 5)
			from_two_to_five(&ab);
		else
			radix_sort(&ab);
		ft_free(&ab, argc);
	}
	return (0);
}
