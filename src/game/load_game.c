/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coltcivers <coltcivers@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 08:52:38 by antheven          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/02/14 01:58:54 by antheven         ###   ########.fr       */
=======
/*   Updated: 2024/03/26 12:42:34 by coltcivers       ###   ########.fr       */
>>>>>>> fe4e90744c580730d02de461f29e710e44a66d72
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	load_game(t_game *game)
{
	game->player.location = (t_point){game->display.level.player_start.y, game->display.level.player_start.x};
	// game->player.direction = D_SO; // To define N,S,E,O from player start look direction
	return (0);
}
