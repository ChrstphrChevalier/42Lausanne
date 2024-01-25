/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:25:33 by waziz             #+#    #+#             */
/*   Updated: 2023/12/20 15:25:36 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

int	ft_free_maps(t_game *info)
{
	int	i;

	i = 0;
	while (i < info->y)
	{
		free(info->map[i]);
		free(info->map_copy[i]);
		i++;
	}
	if (info->map)
	{
		free(info->map);
		free(info->map_copy);
	}
	return (0);
}

int	ft_error(int error)
{
	if (error == 1)
		ft_printf("Error 1 :\nCould not open the map!\n");
	else if (error == 2)
		ft_printf("Error 2 :\nMap is incorrect!\n");
	else if (error == 3)
		ft_printf("Error 3 :\nThere is no path available!\n");
	else if (error == 4)
		ft_printf("Error 4 :\nYour map is not rectangle!\n");
	else if (error == 5)
		ft_printf("Error 5 :\nYour map is not big enough!\n");
	else if (error == 6)
		ft_printf("Error 6 :\nThe border of your map can only be '1'!\n");
	else if (error == 7){
		ft_printf("Error 7 :\nYour map can only contain");
		ft_printf("'1', '0', 'E', 'W' , 'C' or 'P'!\n");
	}
	else if (error == 8){
		ft_printf("Error 8 :\nYou can only have one");
		ft_printf("player/exit and atleast one coin!\n");
	}
	else if (error == 9)
		ft_printf("Error 9 :\nMalloc Failed!\n");
	else if (error == 10)
		ft_printf("Error 10 :\nNot all pieces were taken!\n");
	return (0);
}

int	ft_gerror(int gerror, t_game *info)
{
	if (gerror == 1)
		ft_printf("Gerror 1 :\nInitializing MLX !\n");
	else if (gerror == 2)
		ft_printf("Gerror 2 :\nInitializing MLX Window !\n");
	else if (gerror == 3)
		ft_printf("Gerror 3 :\nLoading images !\n");
	else if (gerror == 4)
	{
		ft_printf("Gerror 4 :\nYour map has a wrong extension");
		return (0);
	}
	clean_up(info);
	return (0);
}
