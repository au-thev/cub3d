/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coltcivers <coltcivers@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 10:12:48 by antheven          #+#    #+#             */
/*   Updated: 2024/03/22 15:35:39 by coltcivers       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "engine.h"
#include "mlx.h"
#include <stdio.h>
#include <math.h>
#include "utils.h"

static void	handle_w(t_game *game)
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

static void	handle_a(t_game *game)
{
	if (game->display.level.map
		[(int)(game->display.level.player_start.y
			- cos(deg_to_rad(game->player.direction)))]
		[(int)(game->display.level.player_start.x
			+ sin(deg_to_rad(game->player.direction)))] == '1')
		return ;
	game->display.level.player_start.x
		+= sin(deg_to_rad(game->player.direction)) / 40;
	game->display.level.player_start.y
		-= cos(deg_to_rad(game->player.direction)) / 40;
}

static void	handle_s(t_game *game)
{
	if (game->display.level.map
		[(int)(game->display.level.player_start.y
			- sin(deg_to_rad(game->player.direction)))]
		[(int)(game->display.level.player_start.x
			- cos(deg_to_rad(game->player.direction)))] == '1')
		return ;
	game->display.level.player_start.x
		-= cos(deg_to_rad(game->player.direction)) / 40;
	game->display.level.player_start.y
		-= sin(deg_to_rad(game->player.direction)) / 40;
}

static void	handle_d(t_game *game)
{
	if (game->display.level.map
		[(int)(game->display.level.player_start.y
			+ cos(deg_to_rad(game->player.direction)))]
		[(int)(game->display.level.player_start.x
			- sin(deg_to_rad(game->player.direction)))] == '1')
		return ;
	game->display.level.player_start.x
		-= sin(deg_to_rad(game->player.direction)) / 40;
	game->display.level.player_start.y
		+= cos(deg_to_rad(game->player.direction)) / 40;
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
		if (game->events.keys[119] && keycode == 119)
			handle_w(game);
		if (game->events.keys[97] && keycode == 97)
			handle_a(game);
		if (game->events.keys[115] && keycode == 115)
			handle_s(game);
		if (game->events.keys[100] && keycode == 100)
			handle_d(game);
		if (game->events.keys[65361] && keycode == 65361)
			handle_left(game);
		if (game->events.keys[65363] && keycode == 65363)
			handle_right(game);
	}
	operate_raycast(game);
	mlx_put_image_to_window(game->display.ptr, game->display.win.ptr,
		game->display.win.buffer.ptr, 0, 0);
	return (0);
}
