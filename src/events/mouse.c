/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 07:19:38 by antheven          #+#    #+#             */
/*   Updated: 2023/12/27 07:53:57 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	mouse_init(t_game *game)
{
	game->events.mouse_btn = 0;
	game->events.click_pos = (t_location){0, 0};
	game->events.move_pos = (t_location){0, 0};
}

int	mouse_down(int button, int x,int y, t_game *game)
{
	game->events.mouse_btn = button;
	game->events.click_pos = (t_location){y, x};
}

int	mouse_up(int button, int x,int y, t_game *game)
{
	game->events.mouse_btn = button;
	game->events.click_pos = (t_location){y, x};
}

int	mouse_move(int x,int y, t_game *game)
{
	game->events.move_pos = (t_location){y, x};
}
