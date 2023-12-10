/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 13:13:32 by waziz             #+#    #+#             */
/*   Updated: 2023/09/20 20:12:00 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	i;
	int	signe;
	int	resultat;

	i = 0;
	signe = 1;
	resultat = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		{
			signe *= -1;
		}
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		resultat = (str[i] - 48) + (resultat * 10);
		i++;
	}
	return (resultat * signe);
}
