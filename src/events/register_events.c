/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   register_events.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 19:17:15 by antheven          #+#    #+#             */
/*   Updated: 2024/02/14 01:47:26 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "events.h"
#include "mlx.h"

int	register_events(t_game *game)
{
	kb_init(game);
	mlx_hook(game->display.win.ptr, ON_KEYDOWN, (1L << 0), kb_down, game);
	mlx_hook(game->display.win.ptr, ON_KEYUP, (1L << 1), kb_up, game);
	mouse_init(game);
	mlx_hook(game->display.win.ptr, ON_MOUSEDOWN, (1L<<2), mouse_down, game);
	mlx_hook(game->display.win.ptr, ON_MOUSEUP, (1L<<3), mouse_up, game);
	mlx_hook(game->display.win.ptr, ON_MOUSEMOVE, (1L<<6), mouse_move, game);
	return (0);
}
