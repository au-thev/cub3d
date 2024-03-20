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
	game->player.location = (t_point){1, 1};
	game->player.direction = D_SO;
	return (0);
}
