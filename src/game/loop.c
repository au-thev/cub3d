/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 10:12:48 by antheven          #+#    #+#             */
/*   Updated: 2024/01/22 17:49:01 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "engine.h"
#include "mlx.h"
#include <stdio.h>
#include <math.h>
#include "utils.h"

static void	handle_forward(t_game *game)
{
	if (game->display.level.map
		[(int)(game->display.level.player_start.y
			+ sin(deg_to_rad(game->player.direction)))]
		[(int)(game->display.level.player_start.x
			+ cos(deg_to_rad(game->player.direction)))] == '1')
		return ;
	game->display.level.player_start.x
		+= cos(deg_to_rad(game->player.direction)) / 40;
	game->display.level.player_start.y
		+= sin(deg_to_rad(game->player.direction)) / 40;
}

static void	handle_right(t_game *game)
{
	game->player.direction = game->player.direction + 1;
	if (game->player.direction > 360)
		game->player.direction -= 360;
}

static void	handle_left(t_game *game)
{
	game->player.direction = game->player.direction - 1;
	if (game->player.direction < 0)
		game->player.direction += 360;
}

int	loop(void *param)
{
	t_game	*game;
	int		keycode;

	game = param;
	keycode = 65535;
	while (keycode-- > 0)
	{
		if (game->events.keys[113] && keycode == 113)
			handle_left(game);
		if (game->events.keys[101] && keycode == 101)
			handle_right(game);
		if (game->events.keys[65362] && keycode == 65362)
			handle_forward(game);
	}
	operate_raycast(game);
	mlx_put_image_to_window(game->display.ptr, game->display.win.ptr,
		game->display.win.buffer.ptr, 0, 0);
	return (0);
}
