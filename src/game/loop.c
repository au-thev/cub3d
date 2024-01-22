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

int	loop(void *param)
{
	t_game	*game;
	int		x;

	game = param;
	x = game->display.win.size[WIDTH];
		int	keycode = 65535;
	while (keycode-- > 0)
	{
		// if (game->events.keys[keycode])
		// 	printf("Key pressed: %d\n", keycode);
		if (game->events.keys[113] && keycode == 113)
		{
			game->player.direction = game->player.direction - 1;
			if (game->player.direction < 0)
				game->player.direction += 360;
			printf("Player Direction: %f\n", game->player.direction);
		}
		if (game->events.keys[101] && keycode == 101)
		{
			game->player.direction = game->player.direction + 1;
			if (game->player.direction > 360)
				game->player.direction -= 360;
			printf("Player Direction: %f\n", game->player.direction);
		}
	}
	//while (x-- > 0)
	//	v_line(&game->display.win.buffer, x,
	//		(t_line){0, game->display.win.size[HEIGHT]}, 0xFF00FF);
	operate_raycast(game);
	mlx_put_image_to_window(game->display.ptr, game->display.win.ptr,
		game->display.win.buffer.ptr, 0, 0);
	return (0);
}
