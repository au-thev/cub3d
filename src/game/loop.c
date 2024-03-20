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
#include <stdlib.h>
#include <math.h>
#include "utils.h"

int	loop(void *param)
{
	t_game	*game;
	int		x;

	game = param;
	x = game->display.win.size[WIDTH];
	int	keycode = 65535;
	while (keycode-- > 0)
	{
		if (game->events.keys[keycode])
			printf("Key pressed: %d\n", keycode);

}
		if (game->events.keys[113])
		{
			game->player.direction = game->player.direction - 1;
			if (game->player.direction < 0)
				game->player.direction += 360;
			// printf("Player Direction: %f\n", game->player.direction);
		}
		if (game->events.keys[101])
		{
			game->player.direction = game->player.direction + 1;
			if (game->player.direction > 360)
				game->player.direction -= 360;
			// printf("Player Direction: %f\n", game->player.direction);qq
		}
		if (game->events.keys[65362] || game->events.keys[119])
		{
			if (game->display.level.map[(int)game->player.location.y][(int)(game->player.location.x + cos(deg_to_rad(game->player.direction)))] == '0')
				game->player.location.x += cos(deg_to_rad(game->player.direction)) / 40.0;
			if (game->display.level.map[(int)(game->player.location.y + sin(deg_to_rad(game->player.direction)))][(int)game->player.location.x] == '0')
				game->player.location.y += sin(deg_to_rad(game->player.direction)) / 40.0;
		}
		if (game->events.keys[65363] || game->events.keys[100])
		{
			if (game->display.level.map[(int)game->player.location.y][(int)(game->player.location.x + cos(deg_to_rad(game->player.direction)))] == '0')
				game->player.location.x += -sin(deg_to_rad(game->player.direction)) / 40.0;
			if (game->display.level.map[(int)(game->player.location.y + sin(deg_to_rad(game->player.direction)))][(int)game->player.location.x] == '0')
				game->player.location.y += cos(deg_to_rad(game->player.direction)) / 40.0;
		}
		if (game->events.keys[65364] || game->events.keys[115])
		{
			if (game->display.level.map[(int)game->player.location.y][(int)(game->player.location.x - cos(deg_to_rad(game->player.direction)))] == '0')
				game->player.location.x -= cos(deg_to_rad(game->player.direction)) / 40.0;
			if (game->display.level.map[(int)(game->player.location.y - sin(deg_to_rad(game->player.direction)))][(int)game->player.location.x] == '0')
				game->player.location.y -= sin(deg_to_rad(game->player.direction)) / 40.0;
		}
		if (game->events.keys[65361] || game->events.keys[97])
		{
			if (game->display.level.map[(int)game->player.location.y][(int)(game->player.location.x + cos(deg_to_rad(game->player.direction)))] == '0')
				game->player.location.x -= -sin(deg_to_rad(game->player.direction)) / 40.0;
			if (game->display.level.map[(int)(game->player.location.y + sin(deg_to_rad(game->player.direction)))][(int)game->player.location.x] == '0')
				game->player.location.y -= cos(deg_to_rad(game->player.direction)) / 40.0;
		}
		if (game->events.keys[65307])
		{
			unload_game(&game->display);
			exit(1);
		}
	// }
	//while (x-- > 0)
	//	v_line(&game->display.win.buffer, x,
	//		(t_line){0, game->display.win.size[HEIGHT]}, 0xFF00FF);
	operate_raycast(game);
	mlx_put_image_to_window(game->display.ptr, game->display.win.ptr,
		game->display.win.buffer.ptr, 0, 0);
	return (0);
}
