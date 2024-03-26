/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coltcivers <coltcivers@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 07:19:43 by antheven          #+#    #+#             */
/*   Updated: 2024/03/21 17:04:50 by coltcivers       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "events.h"

int	kb_init(t_game *game)
{
	int	keycode;

	keycode = 65535;
	while (keycode-- > 0)
		game->events.keys[keycode] = 0;
	return (0);
}

int	kb_down(int keycode, t_game *game)
{
	game->events.keys[keycode] = 1;
	return (0);
}

int	kb_up(int keycode, t_game *game)
{
	
	game->events.keys[keycode] = 0;
	return (0);
}
