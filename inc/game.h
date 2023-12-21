/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 10:07:55 by antheven          #+#    #+#             */
/*   Updated: 2023/12/21 10:12:28 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "display.h"

typedef struct s_game	t_game;

struct s_game
{
	t_display	display;
};

int	loop(void *param);

#endif