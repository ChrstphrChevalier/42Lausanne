/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_analyze.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:29:16 by waziz             #+#    #+#             */
/*   Updated: 2023/12/12 13:16:56 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static long int	ft_atoi(char *argv)
{
	long int	resultat;
	int			signe;

	resultat = 0;
	signe = 1;
	if (*argv == '-')
	{
		signe = -1;
		argv++;
	}
	while (*argv && *argv >= '0' && *argv <= '9')
	{
		resultat *= 10;
		resultat += (*argv++ - 48);
	}
	return (resultat * signe);
}

static int	check_args(int args, char **argv, int i, int j)
{
	while (argv[i])
	{
		while (argv[i][j])
		{
			if (args > 1 && argv[i][j] && ((argv[i][j] == '-' && j == 0
				&& ft_isdigit(argv[i][j + 1])) || ft_isdigit(argv[i][j])))
				j++;
			else if (args == 1 && argv[i][j] && (ft_isdigit(argv[i][j])
				|| (argv[i][j] == ' ' && j != 0 && j + 1 != ft_strlen(argv[i])
				&& argv[i][j - 1] != ' ' && argv[i][j + 1] != ' ')
				|| (argv[i][j] == '-' && ft_isdigit(argv[i][j + 1])
				&& (j == 0 || argv[i][j - 1] == ' '))))
				j++;
			else
				return (0);
		}
		if (j == 0)
			return (0);
		j = 0;
		i++;
	}
	return (1);
}

static int	no_double(int *a, int args)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < args)
	{
		while (j < args)
		{
			if (a[i] == a[j])
				return (0);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (1);
}

int	ft_init_stacks(t_stacks *ab, char **argv, int args, long int resultat)
{
	int		nb_args;

	if (!check_args(args, argv, 0, 0))
		return (ft_error());
	if (args == 1)
		ab->stab = ft_split(argv[0], ' ');
	else
		ab->stab = argv;
	ab->b_len = 0;
	ab->a_len = ft_tablen(ab->stab);
	nb_args = ab->a_len;
	ab->a = malloc(sizeof(int) * nb_args);
	ab->b = malloc(sizeof(int) * nb_args);
	if (!ab->a || !ab->b)
		return (ft_free(ab, args) + ft_error());
	while (--nb_args >= 0)
	{
		resultat = ft_atoi(ab->stab[nb_args]);
		if (resultat > 2147483647 || resultat < -2147483648)
			return (ft_free(ab, args) + ft_error());
		ab->a[nb_args] = (int)resultat;
	}
	if (!no_double(ab->a, ab->a_len))
		return (ft_free(ab, args) + ft_error());
	return (1);
}
