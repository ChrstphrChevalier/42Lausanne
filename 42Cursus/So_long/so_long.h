/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:11:09 by waziz             #+#    #+#             */
/*   Updated: 2023/12/20 15:11:18 by waziz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>

# include "Libft/libft.h"
# include "Printf/ft_printf.h"
# include "GetNextLine/get_next_line.h"

typedef struct gaming
{
	char	**map;
	char	**map_copy;
	char	*name_map;
	int	fd;
	int	x;
	int	y;
	int	coin;
	int	max_coin;
	int	start[2];
	int	end[2];
	void	*mlx;
	void	*win;
	int	height;
	int	width;
	void	*wall;
	void	*floor;
	void	*player;
	void	*piece;
	void	*wicked;
	void	*exit;
	int	game_state;
	int	move_count;
	int	coin_count;
	int	px;
	int	py;
	int	game_over;
	int	enemy_visible;
	int	map_redrawn;
	int	enemy_direction;
	int	end_game;
}	t_game;

int	parse_map(t_game *info);
int	ft_error(int error);
int	ft_gerror(int gerror, t_game *info);
int	ft_free_maps(t_game *info);

#endif
