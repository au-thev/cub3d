/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: autheven <autheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 11:54:46 by autheven          #+#    #+#             */
/*   Updated: 2024/06/22 18:42:52 by pnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

int	preload_dda_vars(t_cub3d *cub3d)
{
	cub3d->dda.dir[X] = cos(cub3d->dda.rot_rad);
	cub3d->dda.dir[Y] = sin(cub3d->dda.rot_rad);
	cub3d->dda.plane[X] = -sin(cub3d->dda.rot_rad);
	cub3d->dda.plane[Y] = cos(cub3d->dda.rot_rad);
	cub3d->dda.camera_x = 2 * cub3d->dda.current_x / (double)(800) - 1;
	cub3d->dda.ray_dir[X] = cub3d->dda.dir[X] + cub3d->dda.plane[X]
		* cub3d->dda.camera_x;
	cub3d->dda.ray_dir[Y] = cub3d->dda.dir[Y] + cub3d->dda.plane[Y]
		* cub3d->dda.camera_x;
	if (cub3d->dda.ray_dir[X] == 0)
		cub3d->dda.delta_dist[X] = 1e30;
	else
		cub3d->dda.delta_dist[X] = fabs(1 / cub3d->dda.ray_dir[X]);
	if (cub3d->dda.ray_dir[Y] == 0)
		cub3d->dda.delta_dist[Y] = 1e30;
	else
		cub3d->dda.delta_dist[Y] = fabs(1 / cub3d->dda.ray_dir[Y]);
	cub3d->dda.curr_pos[X] = (int)cub3d->camera.x;
	cub3d->dda.curr_pos[Y] = (int)cub3d->camera.y;
	return (0);
}

int	get_side_distance(t_cub3d *cub3d)
{
	if (cub3d->dda.ray_dir[X] < 0)
		cub3d->dda.step[X] = -1;
	if (cub3d->dda.ray_dir[X] < 0)
		cub3d->dda.side_dist[X] = (cub3d->camera.x - (int)cub3d->camera.x)
			* cub3d->dda.delta_dist[X];
	if (cub3d->dda.ray_dir[X] >= 0)
		cub3d->dda.step[X] = 1;
	if (cub3d->dda.ray_dir[X] >= 0)
		cub3d->dda.side_dist[X]
			= ((int)cub3d->camera.x + 1.0 - cub3d->camera.x)
			* cub3d->dda.delta_dist[X];
	if (cub3d->dda.ray_dir[Y] < 0)
		cub3d->dda.step[Y] = -1;
	if (cub3d->dda.ray_dir[Y] < 0)
		cub3d->dda.side_dist[Y] = (cub3d->camera.y - (int)cub3d->camera.y)
			* cub3d->dda.delta_dist[Y];
	if (cub3d->dda.ray_dir[Y] >= 0)
		cub3d->dda.step[Y] = 1;
	if (cub3d->dda.ray_dir[Y] >= 0)
		cub3d->dda.side_dist[Y]
			= ((int)cub3d->camera.y + 1.0 - cub3d->camera.y)
			* cub3d->dda.delta_dist[Y];
	return (0);
}

int	perform_dda(t_cub3d *cub3d)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (cub3d->dda.side_dist[X] < cub3d->dda.side_dist[Y])
		{
			cub3d->dda.side_dist[X] += cub3d->dda.delta_dist[X];
			cub3d->dda.curr_pos[X] += cub3d->dda.step[X];
			cub3d->dda.side = 0;
		}
		else
		{
			cub3d->dda.side_dist[Y] += cub3d->dda.delta_dist[Y];
			cub3d->dda.curr_pos[Y] += cub3d->dda.step[Y];
			cub3d->dda.side = 1;
		}
		if (cub3d->level.map[(int)cub3d->dda.curr_pos[Y]
				% cub3d->level.map_height]
			[(int)cub3d->dda.curr_pos[X] % ft_strlen(
					cub3d->level.map[(int)cub3d->dda.curr_pos[Y]
						% cub3d->level.map_height])] == '1')
			hit = 1;
	}
	return (0);
}

int	get_distance(t_cub3d *cub3d)
{
	get_side_distance(cub3d);
	perform_dda(cub3d);
	if (cub3d->dda.side == 0)
		cub3d->dda.wall_dist
			= (cub3d->dda.side_dist[X] - cub3d->dda.delta_dist[X]);
	else
		cub3d->dda.wall_dist
			= (cub3d->dda.side_dist[Y] - cub3d->dda.delta_dist[Y]);
	if (cub3d->dda.wall_dist == 0)
		cub3d->dda.wall_dist = .1;
	return (0);
}
