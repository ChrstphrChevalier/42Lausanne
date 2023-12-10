/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 19:31:06 by waziz             #+#    #+#             */
/*   Updated: 2023/09/19 19:31:14 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_alpha(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9'))
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (is_alpha(str[i]) && (!is_alpha(str[i - 1]) || i == 0))
		{
			if (str[i] >= 'a' && str[i] <= 'z')
					str[i] -= 32;
			i++;
			while (is_alpha(str[i]))
			{
				if (str[i] >= 'A' && str[i] <= 'Z')
					str[i] += 32;
				i++;
			}
		}
		else
			i++;
	}
	return (str);
}
