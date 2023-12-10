/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 12:35:38 by waziz             #+#    #+#             */
/*   Updated: 2023/09/19 22:33:46 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	testsize;

	i = 0;
	j = 0;
	testsize = 0;
	while (dest[i])
		i++;
	if (size <= i)
		testsize = 1;
	if (!testsize)
	{
		size -= i;
		while ((src[j] != '\0') && (j < size - 1))
			dest[i++] = src[j++];
		dest[i] = '\0';
	}
	while (src[j])
		j++;
	return (i + j);
}
