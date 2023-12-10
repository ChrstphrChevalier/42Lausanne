/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 21:34:46 by waziz             #+#    #+#             */
/*   Updated: 2023/09/18 13:14:08 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <stdio.h>

int	ft_strslen(int size, char**strs, char *sep)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = 0;
	while (i < size && strs[i])
	{
		j = 0;
		while (strs[i][j])
		{
			j++;
			len++;
		}
		if (i != size - 1)
		{
			j = 0;
			while (sep[j++])
				len++;
		}
		i++;
	}
	return (len);
}

void	ft_strscat(char **strs, char *sep, char *tab, int size)
{
	int	i;
	int	j;
	int	x;

	i = 0;
	x = 0;
	while (i < size && strs[i])
	{
		j = 0;
		while (strs[i][j])
			tab[x++] = strs[i][j++];
		if (i != size - 1 && sep)
		{
			j = 0;
			while (sep[j])
			{
				tab[x] = sep[j];
				j++;
				x++;
			}
		}
		i++;
	}
	tab[x] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*tab;
	int		total_len;

	total_len = ft_strslen(size, strs, sep);
	tab = malloc((total_len + 1) * sizeof(char));
	if (tab)
	{
		tab[0] = '\0';
		ft_strscat(strs, sep, tab, size);
	}
	return (tab);
}
