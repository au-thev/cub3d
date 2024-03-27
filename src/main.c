/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coltcivers <coltcivers@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 08:19:10 by antheven          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/02/14 01:59:19 by antheven         ###   ########.fr       */
=======
/*   Updated: 2024/03/26 12:43:02 by coltcivers       ###   ########.fr       */
>>>>>>> fe4e90744c580730d02de461f29e710e44a66d72
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "level.h"
#include "display.h"
#include "mlx.h"
#include "engine.h"
#include "events.h"
#include <stdio.h>
#include <stdlib.h>

// static void	close_game(t_game game)
// {
// 	printf("pressed destroy \n");
// 	unload_game(&game.display);
// 	exit(0);
// }

int	main(int argc, char **argv)
{
	t_game		game;

	if (argc != 2)
		return (1);
	game.display.ptr = mlx_init();
	if (!game.display.ptr)
		return (1);
	new_window(&game.display);
	mlx_string_put(game.display.ptr, game.display.win.ptr, 106, 106, 0x0,
		"Loading game...");
	if (feed_level(&game.display, argv[1]))
	{
		unload_game(&game.display);
		return (1);
	}
	printf("initial dir : %d \n", game.display.level.initial_direction);
	game.player.direction = game.display.level.initial_direction;
	register_events(&game);
	load_game(&game);
	// game.display.level.player_start.x = 26;
	// game.display.level.player_start.y = 3;
	mlx_clear_window(game.display.ptr, game.display.win.ptr);
	mlx_loop_hook(game.display.ptr, loop, &game);
	load_game(&game);
	// mlx_hook(&game.display.win, 17, 0, close_game, &game);
	mlx_loop(game.display.ptr);
	unload_game(&game.display);
	return (0);
}
