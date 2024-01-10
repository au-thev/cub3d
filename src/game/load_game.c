/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 08:52:38 by antheven          #+#    #+#             */
/*   Updated: 2024/01/03 20:50:55 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

enum	e_direction
{
	D_NO=270,
	D_SO=90,
	D_EA=0,
	D_WE=180
};

int	load_game(t_game *game)
{
	game->player.location = (t_point){1, 1};
	game->player.direction = D_SO; // To define N,S,E,O from player start look direction
	return (0);
}