/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   register_events.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 19:17:15 by antheven          #+#    #+#             */
/*   Updated: 2023/12/27 07:49:58 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "events.h"
#include "mlx.h"

int register_events(t_game *game)
{
	kb_init(game);
	mlx_hook(game->display.win.ptr, ON_KEYDOWN, 0, kb_down, game);
	mlx_hook(game->display.win.ptr, ON_KEYUP, 0, kb_up, game);
	mouse_init(game);
	mlx_hook(game->display.win.ptr, ON_MOUSEDOWN, 0, mouse_down, game);
	mlx_hook(game->display.win.ptr, ON_MOUSEUP, 0, mouse_up, game);
	mlx_hook(game->display.win.ptr, ON_MOUSEMOVE, 0, mouse_move, game);
}
