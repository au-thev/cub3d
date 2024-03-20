/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 08:52:38 by antheven          #+#    #+#             */
/*   Updated: 2024/01/10 16:17:31 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	load_game(t_game *game)
{
	game->player.location = (t_point){game->display.level.player_start.y, game->display.level.player_start.x};
	game->player.direction = D_SO; // To define N,S,E,O from player start look direction
	return (0);
}
