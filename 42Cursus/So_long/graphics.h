/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waziz <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 18:19:05 by waziz             #+#    #+#             */
/*   Updated: 2024/01/31 19:36:15 by waziz            ###   ########.fr       */
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

int		graphics_init(t_game *info);
int		load_images(t_game *info);
void	draw_map(t_game *info);
void	clean_up(t_game *info);
int		key_press_callback(int keycode, t_game *info);
int		win_close(t_game *info);
void	display_move(t_game *info);

#endif
