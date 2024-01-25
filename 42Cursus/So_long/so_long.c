/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:10:44 by waziz             #+#    #+#             */
/*   Updated: 2023/12/20 17:10:49 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics.h"

static int	init_args(t_game *info, char *av)
{
	int	i;

	i = 0;
	while (av[i])
		i++;
	if (av[i - 1] != 'r' || av[i - 2] != 'e'
		|| av[i - 3] != 'b' || av[i - 4] != '.')
		return (ft_gerror(4, info));
	info->fd = open(av, O_RDONLY);
	if (info->fd == -1)
		return (ft_error(1));
	info->name_map = av;
	return (1);
}

static void	init_game(t_game *info)
{
	ft_memset(info, 0, sizeof(t_game));
}

static void	draw_game(t_game *info)
{
	if (info->end_game)
		mlx_string_put(info->mlx, info->win, 100, 100, 0xFFFFFF, "WINNER :)");
	else if (info->game_over){
		if (!info->map_redrawn){
			info->enemy_visible = 1;
			info->map[info->py][info->px] = 'W';
			if (info->enemy_direction == 0)
				info->map[info->py + 1][info->px] = 'P';
			else if (info->enemy_direction == 1)
				info->map[info->py][info->px + 1] = 'P';
			else if (info->enemy_direction == 2)
				info->map[info->py - 1][info->px] = 'P';
			else if (info->enemy_direction == 3)
				info->map[info->py][info->px - 1] = 'P';
			draw_map(info);
			info->map_redrawn = 1;
		}
		mlx_string_put(info->mlx, info->win, 100, 100, 0xFFFFFF, "GAME OVER!");
	}
	else {
		display_move(info);
		draw_map(info);
	}
}

static int	draw_game_hook(void *param)
{
	t_game	*info;

	info = (t_game *)param;
	draw_game(info);
	return (0);
}

int	main(int ac, char **av)
{
	t_game	info;

	init_game(&info);
	if (ac == 2)
	{
		if (init_args(&info, av[1]) && parse_map(&info))
		{
			if (graphics_init(&info))
			{
				load_images(&info);
				info.px = info.start[1];
				info.py = info.start[0];
				mlx_key_hook(info.win, key_press_callback, &info);
				mlx_hook(info.win, 17, 0, win_close, &info);
				mlx_loop_hook(info.mlx, draw_game_hook, &info);
				mlx_loop(info.mlx);
			}
		}
	}
	else
		ft_printf("Error !\nUsage : ./so_long map.ber\n");
	return (0);
}
