/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 10:12:48 by antheven          #+#    #+#             */
/*   Updated: 2023/12/21 10:22:35 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "mlx.h"

int	loop(void *param)
{
	t_game	*game;
	int		x;

	game = param;
	x = game->display.win.size[WIDTH];
	while (x-- > 0)
		v_line(&game->display.win.buffer, x,
			(t_line){0, game->display.win.size[HEIGHT]}, 0xFF00FF);
	mlx_put_image_to_window(game->display.ptr, game->display.win.ptr,
		game->display.win.buffer.ptr, 0, 0);
	return (0);
}
