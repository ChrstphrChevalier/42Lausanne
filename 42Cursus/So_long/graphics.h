/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 10:52:53 by waziz             #+#    #+#             */
/*   Updated: 2024/01/08 14:17:12 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_H
# define GRAPHICS_H

# include "MLX/mlx.h"
# include "so_long.h"

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_UP 126
# define KEY_LEFT 123
# define KEY_DOWN 125
# define KEY_RIGHT 124
# define KEY_ESC 53

int	graphics_init(t_game *info);
int	load_images(t_game *info);
void	draw_map(t_game *info);
void	clean_up(t_game *info);
int	key_press_callback(int keycode, t_game *info);
int	win_close(t_game *info);
void	display_move(t_game *info);

#endif
