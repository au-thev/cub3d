/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 07:19:43 by antheven          #+#    #+#             */
/*   Updated: 2024/01/19 16:15:20 by antheven         ###   ########.fr       */
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
	printf("Key pressed: %d\n", keycode);
	return (0);
}

int	kb_up(int keycode, t_game *game)
{
	game->events.keys[keycode] = 0;
	printf("Key released: %d\n", keycode);
	return (0);
}