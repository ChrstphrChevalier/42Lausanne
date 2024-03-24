/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 10:37:01 by waziz             #+#    #+#             */
/*   Updated: 2023/12/12 13:09:06 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	count_word(const char *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

static size_t	word_lenght(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

static char	*set_word(const char *s, char c)
{
	char	*dynam;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	dynam = malloc(sizeof(*dynam) * (word_lenght(s, c) + 1));
	if (!dynam)
		return (NULL);
	while (s[j] != c && s[j])
		dynam[i++] = s[j++];
	dynam[i] = '\0';
	return (dynam);
}

static char	**ft_freed(char **tab, int t)
{
	while (--t >= 0)
		free(tab[t]);
	free(tab);
	return (NULL);
}

char	**ft_split(const char *s, char c)
{
	char	**split;
	size_t	t;
	size_t	count;

	if (!s)
		return (NULL);
	count = count_word(s, c);
	split = malloc(sizeof(*split) * (count + 1));
	if (!split)
		return (NULL);
	t = 0;
	while (t < count)
	{
		while (*s == c && *s)
			s++;
		split[t++] = set_word(s, c);
		if (!split[t - 1])
			return (ft_freed(split, t));
		while (*s != c && *s)
			s++;
	}
	split[t] = NULL;
	return (split);
}
