/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 10:57:31 by waziz             #+#    #+#             */
/*   Updated: 2023/12/21 10:57:33 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

int	graphics_init(t_game *info)
{
	info->mlx = mlx_init();
	if (!info->mlx)
		return (ft_gerror(1, info));
	info->width = info->x * 80;
	info->height = info->y * 80;
	info->win = mlx_new_window(info->mlx, info->width,
			info->height + 30, "SoLong");
	if (!info->win)
		return (ft_gerror(2, info));
	return (1);
}

int	load_images(t_game *info)
{
	info->wall = mlx_xpm_file_to_image(info->mlx, "Xpm/wall.xpm",
			&info->width, &info->height);
	info->floor = mlx_xpm_file_to_image(info->mlx, "Xpm/floor.xpm",
			&info->width, &info->height);
	info->player = mlx_xpm_file_to_image(info->mlx, "Xpm/player.xpm",
			&info->width, &info->height);
	info->piece = mlx_xpm_file_to_image(info->mlx, "Xpm/piece.xpm",
			&info->width, &info->height);
	info->wicked = mlx_xpm_file_to_image(info->mlx, "Xpm/wicked.xpm",
			&info->width, &info->height);
	info->exit = mlx_xpm_file_to_image(info->mlx, "Xpm/exit.xpm",
			&info->width, &info->height);
	if (!info->wall || !info->floor || !info->player
		|| !info->coin || !info->wicked || !info->exit)
		return (ft_gerror(3, info));
	return (1);
}

static void	*get_image(t_game *info, char map_xy)
{
	if (map_xy == '1')
		return (info->wall);
	if (map_xy == '0')
		return (info->floor);
	if (map_xy == 'P')
		return (info->player);
	if (map_xy == 'W')
	{
		if (info->enemy_visible)
			return (info->wicked);
		else
			return (info->floor);
	}
	if (map_xy == 'C')
		return (info->piece);
	if (map_xy == 'E')
	{
		if (info->game_state == 1)
			return (info->exit);
		else
			return (info->floor);
	}
	return (NULL);
}

void	draw_map(t_game *info)
{
	int	y;
	int	x;
	void	*img_to_draw;

	y = 0;
	while (y < info->y)
	{
		x = 0;
		while (x < info->x)
		{
			img_to_draw = get_image(info, info->map[y][x]);
			if (img_to_draw)
				mlx_put_image_to_window(info->mlx, info->win, img_to_draw,
					x * 80, (y * 80) + 30);
			x++;
		}
		y++;
	}
}

void	clean_up(t_game *info)
{
	if (info->wall)
		mlx_destroy_image(info->mlx, info->wall);
	if (info->floor)
		mlx_destroy_image(info->mlx, info->floor);
	if (info->player)
		mlx_destroy_image(info->mlx, info->player);
	if (info->piece)
		mlx_destroy_image(info->mlx, info->piece);
	if (info->wicked)
		mlx_destroy_image(info->mlx, info->wicked);
	if (info->exit)
		mlx_destroy_image(info->mlx, info->exit);
	if (info->win)
		mlx_destroy_window(info->mlx, info->win);
}
