/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: autheven <autheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:56:32 by autheven          #+#    #+#             */
/*   Updated: 2024/06/18 20:48:41 by pnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>
#include <limits.h>
#include "cub3d.h"

int	draw_raycast(t_cub3d *cub3d, t_draw *draw)
{
	int		y;

	y = draw->start;
	while (y < draw->end)
	{
		draw->tex[Y] = (int)draw->tex_pos
			& (cub3d->level.texture[draw->tex_side].size[1] - 1);
		draw->tex_pos += draw->step;
		draw->color = get_pixel(cub3d, draw->tex[X], draw->tex[Y],
				draw->tex_side);
		if (cub3d->dda.side == 1)
			draw->color = (draw->color >> 1) & 8355711;
		put_pixel(cub3d, cub3d->dda.current_x, y, draw->color);
		y++;
	}
	vert_line(cub3d, cub3d->dda.current_x % 800, (int [2]){0, draw->start},
		cub3d->level.color[1]);
	vert_line(cub3d, cub3d->dda.current_x % 800, (int [2]){draw->end, 600},
		cub3d->level.color[0]);
	return (0);
}

int	get_tex_side(t_cub3d *cub3d, t_draw *draw)
{
	if (cub3d->dda.side == 0)
	{
		if (cub3d->dda.step[X] < 0)
			draw->tex_side = WE;
		else
			draw->tex_side = EA;
	}
	else
	{
		if (cub3d->dda.step[Y] > 0)
			draw->tex_side = SO;
		else
			draw->tex_side = NO;
	}
	return (0);
}

int	get_tex_alignement(t_cub3d *cub3d, t_draw *draw)
{
	draw->wall_x = 0;
	if (cub3d->dda.side == 0)
		draw->wall_x = cub3d->camera.y
			+ cub3d->dda.wall_dist * cub3d->dda.ray_dir[Y];
	else
		draw->wall_x = cub3d->camera.x
			+ cub3d->dda.wall_dist * cub3d->dda.ray_dir[X];
	draw->wall_x -= floor((draw->wall_x));
	draw->tex[X] = (int)(draw->wall_x
			* (double)(cub3d->level.texture[draw->tex_side].size[0]));
	if (cub3d->dda.side == 0 && cub3d->dda.ray_dir[X] > 0)
		draw->tex[X] = cub3d->level.texture[draw->tex_side].size[0]
			- draw->tex[X] - 1;
	if (cub3d->dda.side == 1 && cub3d->dda.ray_dir[Y] < 0)
		draw->tex[X] = cub3d->level.texture[draw->tex_side].size[0]
			- draw->tex[X] - 1;
	draw->step = 1.0 * cub3d->level.texture[draw->tex_side].size[1]
		/ draw->line_height;
	draw->tex_pos = (draw->start - 600 / 2 + draw->line_height / 2)
		* draw->step;
	return (0);
}

int	do_raycast(t_cub3d *cub3d)
{
	t_draw	draw;
	int		x;

	x = 800;
	while (x-- > 0)
	{
		cub3d->dda.current_x = x;
		cub3d->dda.rot_rad = cub3d->camera.yaw * M_PI / 180;
		preload_dda_vars(cub3d);
		get_distance(cub3d);
		if (cub3d->dda.wall_dist == 0)
			cub3d->dda.wall_dist = .1;
		draw.line_height = (int)(400 / cub3d->dda.wall_dist);
		if (draw.line_height < 0)
			draw.line_height = INT_MAX;
		draw.start = -draw.line_height / 2 + 600 / 2;
		if (draw.start < 0)
			draw.start = 0;
		draw.end = draw.line_height / 2 + 600 / 2;
		if (draw.end >= 600)
			draw.end = 600 - 1;
		get_tex_side(cub3d, &draw);
		get_tex_alignement(cub3d, &draw);
		draw_raycast(cub3d, &draw);
	}
	return (0);
}
