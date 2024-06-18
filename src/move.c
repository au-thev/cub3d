/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: autheven <autheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 10:58:42 by autheven          #+#    #+#             */
/*   Updated: 2024/06/02 12:15:55 by autheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "cub3d.h"

static void	move_forwards(t_cub3d *cub3d)
{
	double	x;
	double	y;

	x = (cub3d->camera.x + MOVE_RATIO * cos(cub3d->camera.yaw * M_PI / 180));
	y = (cub3d->camera.y + MOVE_RATIO * sin(cub3d->camera.yaw * M_PI / 180));
	if (cub3d->level.map[(int)(cub3d->camera.y)][(int)x] == '.')
		cub3d->camera.x = x;
	if (cub3d->level.map[(int)y][(int)(cub3d->camera.x)] == '.')
		cub3d->camera.y = y;
}

static void	move_backwards(t_cub3d *cub3d)
{
	double	x;
	double	y;

	x = (cub3d->camera.x - MOVE_RATIO * cos(cub3d->camera.yaw * M_PI / 180));
	y = (cub3d->camera.y - MOVE_RATIO * sin(cub3d->camera.yaw * M_PI / 180));
	if (cub3d->level.map[(int)(cub3d->camera.y)][(int)x] == '.')
		cub3d->camera.x = x;
	if (cub3d->level.map[(int)y][(int)(cub3d->camera.x)] == '.')
		cub3d->camera.y = y;
}

static void	move_left(t_cub3d *cub3d)
{
	double	x;
	double	y;

	x = (cub3d->camera.x - MOVE_RATIO * -sin(cub3d->camera.yaw * M_PI / 180));
	y = (cub3d->camera.y - MOVE_RATIO * cos(cub3d->camera.yaw * M_PI / 180));
	if (cub3d->level.map[(int)(cub3d->camera.y)][(int)x] == '.')
		cub3d->camera.x = x;
	if (cub3d->level.map[(int)y][(int)(cub3d->camera.x)] == '.')
		cub3d->camera.y = y;
}

static void	move_right(t_cub3d *cub3d)
{
	double	x;
	double	y;

	x = (cub3d->camera.x + MOVE_RATIO * -sin(cub3d->camera.yaw * M_PI / 180));
	y = (cub3d->camera.y + MOVE_RATIO * cos(cub3d->camera.yaw * M_PI / 180));
	if (cub3d->level.map[(int)(cub3d->camera.y)][(int)x] == '.')
		cub3d->camera.x = x;
	if (cub3d->level.map[(int)y][(int)(cub3d->camera.x)] == '.')
		cub3d->camera.y = y;
}

void	move(t_cub3d *cub3d, char direction)
{
	if (direction == 'f')
		move_forwards(cub3d);
	if (direction == 'l')
		move_left(cub3d);
	if (direction == 'b')
		move_backwards(cub3d);
	if (direction == 'r')
		move_right(cub3d);
}
