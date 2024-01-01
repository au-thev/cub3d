#include "game.h"
#include "engine.h"
#include "math.h"
#include "libft.h"

t_dda	dda_ray(t_game *game, t_point plane, \
	t_point dir_vector, int ray)
{
	t_dda			*dda;
	t_point			ray_dir;
	int				camera;
	int				completion;
	int				max_iter;

	completion = 0;
	max_iter = 200; //TODO: find default value
	dda = ft_calloc(1, sizeof(*dda));
	camera = 2 * ray / game->display.win.size[WIDTH] - 1;
	ray_dir.x = dir_vector.x + plane.x * camera;
	ray_dir.y = dir_vector.y + plane.y * camera;
	dda->start = game->display.level.player_start;
	compute_delta_dist(dda, dir_vector);
	while (!completion) {
		if (dda->side_dist.x < dda->side_dist.y) {
			dda->side_dist.x += dda->delta_dist.x;
			dda->end.x += dda->step.x;
		} else {
			dda->side_dist.y += dda->delta_dist.y;
			dda->end.y += dda->step.y;
		}
		if (game->display.level.map
		[(int)dda->end.y%(int)game->display.level.map_width]
		[(int)dda->end.x%(int)game->display.level.map_length] || !max_iter)
			completion = 1;
		max_iter--;
	}
}

static compute_delta_dist(t_dda *dda, t_point dir)
{
	dda->delta_dist.x = sqrt(1 + (dir.y * dir.y) / (dir.x * dir.x));
	dda->delta_dist.y = sqrt(1 + (dir.x * dir.x) / (dir.y * dir.y));
	if (dir.x < 0)
	{
		dda->step.x = -1;
		dda->side_dist.x = (dda->start.x - dda->end.x) * dda->delta_dist.x;
	}
	else
	{
		dda->step.x = 1;
		dda->side_dist.x = (dda->end.x + 1.0 - dda->start.x) * 
		dda->delta_dist.x;
	}
	if (dir.y < 0)
	{
		dda->step.y = -1;
		dda->side_dist.y = (dda->start.y - dda->end.y) * dda->delta_dist.y;
	}
	else
	{
		dda->step.y = 1;
		dda->side_dist.y = (dda->end.y + 1.0 - dda->start.y) * dda->delta_dist.y;
	}
}