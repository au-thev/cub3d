/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 08:19:10 by antheven          #+#    #+#             */
/*   Updated: 2024/01/01 09:00:20 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "level.h"
#include "display.h"
#include "mlx.h"
#include "engine.h"
#include <stdio.h>


int	main(int argc, char **argv)
{
	t_game		game;

	if (argc != 2)
		return (1);
	game.display.ptr = mlx_init();
	game.display.fov = 60; // TEMP
	new_window(&game.display);
	mlx_string_put(game.display.ptr, game.display.win.ptr, 106, 106, 0x0,
		"Loading game...");
	if (feed_level(&game.display, argv[1]))
	{
		unload_game(&game.display);
		return (1);
	}
	load_game(&game);
	mlx_clear_window(game.display.ptr, game.display.win.ptr);
	// mlx_loop_hook(game.display.ptr, loop, &game);
	printf("Entering raycast :\n");
	// mlx_loop_hook(game.display.ptr, operate_raycast, &game);
	operate_raycast(&game);
	printf("Quit raycast :\n");
	mlx_loop(game.display.ptr);
	unload_game(&game.display);
	return (0);
}
