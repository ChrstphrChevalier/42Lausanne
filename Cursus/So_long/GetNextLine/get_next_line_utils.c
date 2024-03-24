/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:09:55 by waziz             #+#    #+#             */
/*   Updated: 2023/12/08 19:03:20 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (0);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*dynam;
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(s);
	dynam = (char *)malloc((j + 1) * sizeof(char));
	while (i < j)
	{
		dynam[i] = s[i];
		i++;
	}
	dynam[i] = '\0';
	return (dynam);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*sc;
	size_t	i;
	size_t	j;

	sc = (char *)malloc((len + 1) * sizeof(*s));
	if (sc == 0)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			sc[j] = s[i];
			j++;
		}
		i++;
	}
	sc[j] = '\0';
	return (sc);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ms;
	int		i;
	int		j;

	i = 0;
	j = 0;
	ms = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!ms)
		return (NULL);
	while (s1[j])
	{
		ms[i++] = s1[j++];
	}
	j = 0;
	while (s2[j])
	{
		ms[i++] = s2[j++];
	}
	ms[i] = '\0';
	return (ms);
}
