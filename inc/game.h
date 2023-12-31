/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 10:07:55 by antheven          #+#    #+#             */
/*   Updated: 2024/01/01 09:01:08 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "display.h"
# include "events.h"
# include "entity.h"

typedef struct s_game	t_game;

struct s_game
{
	t_display	display;
	t_events	events;
	t_entity	player;
};

int	loop(void *param);
int	load_game(t_game *game);

#endif