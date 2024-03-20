/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coltcivers <coltcivers@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 00:30:28 by coltcivers        #+#    #+#             */
/*   Updated: 2024/03/20 00:30:30 by coltcivers       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "engine.h"
#include <stdio.h> 
#include "mlx.h"
#include "utils.h"
#include <math.h>

int	operate_raycast(t_game *game)
{
	t_point	plane;
	t_point	dir_vector;
	int		curr_ray;

	curr_ray = 0;
	plane.x = -sin(deg_to_rad(game->player.direction));
	plane.y = cos(deg_to_rad(game->player.direction));
	dir_vector.x = cos(deg_to_rad(game->player.direction));
	dir_vector.y = sin(deg_to_rad(game->player.direction));
	while (curr_ray < game->display.win.size[WIDTH])
	{
		dda_ray(game, plane, dir_vector, curr_ray);
		curr_ray++;
	}
	return (0);
}
