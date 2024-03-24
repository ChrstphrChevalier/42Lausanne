/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   games.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:18:22 by waziz             #+#    #+#             */
/*   Updated: 2024/01/31 19:34:34 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

static int	check_wall_collision(t_game *info, int x, int y)
{
	if (x < 0 || x >= info->width || y < 0 || y >= info->height)
		return (1);
	if (info->map[y][x] == '1')
		return (1);
	return (0);
}

static void	move_player(t_game *info, int mx, int my)
{
	int	new_x;
	int	new_y;

	new_x = info->px + mx;
	new_y = info->py + my;
	if (!check_wall_collision(info, new_x, new_y))
	{
		info->map[info->py][info->px] = '0';
		save_mp(info, new_x, new_y);
		info->px = new_x;
		info->py = new_y;
		info->map[info->py][info->px] = 'P';
		if (info->coin_count == info->max_coin)
			info->game_state = 1;
		info->move_count++;
		info->enemy_visible = !info->enemy_visible;
		ft_printf("Move count : %d\n", info->move_count);
	}
}

int	key_press_callback(int keycode, t_game *info)
{
	if (keycode == KEY_A || keycode == KEY_LEFT)
	{
		move_player(info, -1, 0);
		info->enemy_direction = 0;
	}
	if (keycode == KEY_W || keycode == KEY_UP)
	{
		move_player(info, 0, -1);
		info->enemy_direction = 1;
	}
	if (keycode == KEY_D || keycode == KEY_RIGHT)
	{
		move_player(info, 1, 0);
		info->enemy_direction = 2;
	}
	if (keycode == KEY_S || keycode == KEY_DOWN)
	{
		move_player(info, 0, 1);
		info->enemy_direction = 3;
	}
	if (keycode == KEY_ESC)
		win_close(info);
	if (info->end_game)
		return (0);
	return (0);
}

int	win_close(t_game *info)
{
	mlx_destroy_window(info->mlx, info->win);
	exit(0);
}

void	display_move(t_game *info)
{
	char	*move_str;

	move_str = ft_itoa(info->move_count);
	if (move_str)
	{
		mlx_string_put(info->mlx, info->win, 10, 10, 0xFFFFFF, move_str);
		free(move_str);
	}
}
