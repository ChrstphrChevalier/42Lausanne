/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:25:33 by waziz             #+#    #+#             */
/*   Updated: 2024/01/31 19:48:11 by waziz            ###   ########.fr       */
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
		ft_printf("Error 5 :\nYour map is not big enough or is not rectangle.\n");
	else if (error == 6)
		ft_printf("Error 6 :\nThe border of your map can only be '1'!\n");
	else if (error == 7)
		ft_printf("Error 7 :\n'1', '0', 'E', 'W' , 'C' or 'P' only!\n");
	else if (error == 8)
		ft_printf("Error 8 :\nPlayer/exit once and atleast one coin!\n");
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

void	save_mp(t_game *info, int new_x, int new_y)
{
	if (info->map[new_y][new_x] == 'W' && !info->enemy_visible)
		info->game_over = 1;
	if (info->map[new_y][new_x] == 'E' && info->game_state == 1)
		info->end_game = 1;
	if (info->map[new_y][new_x] == 'C')
	{
		info->map[new_y][new_x] = '0';
		info->coin_count++;
	}
}

void	save_dg(t_game *info)
{
	if (info->enemy_direction == 0)
		info->map[info->py + 1][info->px] = 'P';
	else if (info->enemy_direction == 1)
		info->map[info->py][info->px + 1] = 'P';
	else if (info->enemy_direction == 2)
		info->map[info->py - 1][info->px] = 'P';
	else if (info->enemy_direction == 3)
		info->map[info->py][info->px - 1] = 'P';
}
