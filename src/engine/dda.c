/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 23:32:07 by coltcivers        #+#    #+#             */
/*   Updated: 2024/03/21 15:19:23 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "engine.h"
#include "math.h"
#include "libft.h"
#include <stdio.h>
#include "mlx.h"

static void	compute_delta_dist(t_dda *dda, t_point dir)
{
	dda->delta_dist.x = fabs(1 / dir.x);
	dda->delta_dist.y = fabs(1 / dir.y);
	if (dir.x < 0)
	{
		dda->step.x = -1;
		dda->side_dist.x = (dda->start.x - dda->end.x) * dda->delta_dist.x;
	}
	else
	{
		dda->step.x = 1;
		dda->side_dist.x = (dda->end.x + 1.0 - dda->start.x)
			* dda->delta_dist.x;
	}
	if (dir.y < 0)
	{
		dda->step.y = -1;
		dda->side_dist.y = (dda->start.y - dda->end.y) * dda->delta_dist.y;
	}
	else
	{
		dda->step.y = 1;
		dda->side_dist.y = (dda->end.y + 1.0 - dda->start.y)
			* dda->delta_dist.y;
	}
}

static void	dda_loop(t_game *game, t_dda *dda, int completion,
	int max_iter)
{
	while (!completion)
	{
		if (dda->side_dist.x < dda->side_dist.y)
		{
			dda->side_dist.x += dda->delta_dist.x;
			dda->end.x += dda->step.x;
			dda->side = 0;
		}
		else
		{
			dda->side_dist.y += dda->delta_dist.y;
			dda->end.y += dda->step.y;
			dda->side = 1;
		}
		if (game->display.level.map[(int)dda->end.y]
			[(int)dda->end.x] == '1' || !max_iter)
			completion = 1;
		max_iter--;
	}
}

t_dda	dda_ray(t_game *game, t_point plane, \
	t_point dir_vector, int ray)
{
	t_dda			*dda;
	t_point			ray_dir;
	double			camera;
	int				completion;
	int				max_iter;

	completion = 0;
	max_iter = 200;
	dda = ft_calloc(1, sizeof(*dda));
	camera = 2 * ray / game->display.win.size[WIDTH] - 1;
	ray_dir.x = dir_vector.x + plane.x * camera;
	ray_dir.y = dir_vector.y + plane.y * camera;
	dda->start = game->player.location;
	dda->end = game->player.location;
	compute_delta_dist(dda, ray_dir);
	dda_loop(game, dda, completion, max_iter);
	render_ray(game, dda, ray, ray_dir);
	return (*dda);
}
