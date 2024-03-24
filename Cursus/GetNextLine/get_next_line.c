/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:14:58 by waziz             #+#    #+#             */
/*   Updated: 2023/12/08 22:17:18 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE (42)
#endif

static char	*extract(char *line)
{
	size_t	index;
	char	*sc;

	index = 0;
	while (line[index] != '\n' && line[index] != '\0')
		index++;
	if (line[index] == '\0' || line[1] == '\0')
		return (0);
	sc = ft_substr(line, index + 1, ft_strlen(line) - index);
	if (sc[0] == '\0')
	{
		free(sc);
		sc = NULL;
	}
	line[index + 1] = '\0';
	return (sc);
}

static char	*join_extract(int fd, char *buffer, char *sc)
{
	int		isread;
	char	*temp;

	isread = 1;
	while (isread != '\0')
	{
		isread = read(fd, buffer, BUFFER_SIZE);
		if (isread == -1)
			return (0);
		else if (isread == 0)
			break ;
		buffer[isread] = '\0';
		if (!sc)
			sc = ft_strdup("");
		temp = sc;
		sc = ft_strjoin(temp, buffer);
		free(temp);
		temp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (sc);
}

static char	*ft_free(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*sc;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, sc, 0) == -1)
		return (ft_free(&sc));
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
	{
		free(sc);
		sc = NULL;
		return (0);
	}
	line = join_extract(fd, buffer, sc);
	if (!line)
		return (ft_free(&sc), ft_free(&buffer));
	free(buffer);
	buffer = NULL;
	sc = extract(line);
	return (line);
}
