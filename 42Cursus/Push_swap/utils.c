/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:33:20 by waziz             #+#    #+#             */
/*   Updated: 2023/11/24 14:33:22 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_tablen(char **stab)
{
	size_t	i;

	i = 0;
	while (stab[i])
		i++;
	return (i);
}

int	ft_error(void)
{
	write (2, "Error\n", 6);
	return (0);
}

int	ft_free(stacks *ab, int args)
{
	int	i;

	i = 0;
	if (ab->a_len > 0 || ab->b_len > 0)
	{
		free(ab->a);
		free(ab->b);
	}
	if (args == 1)
	{
		while (ab->stab[i])
			free(ab->stab[i++]);
		if (ab->stab)
			free(ab->stab);
	}
	return (0);
}

int	ft_sorted(const int *a, const int a_len)
{
	int	i;

	i = 0;
	while (i + 1 < a_len)
	{
		if (a[i] > a[i + 1])
			return (0);
		i++;
	}
	return (1);
}
