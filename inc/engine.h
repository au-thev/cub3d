#ifndef ENGINE_H
# define ENGINE_H

# include "level.h"
# include "images.h"
# include "game.h"

typedef struct s_point			t_point;
typedef struct s_dda	t_dda;

struct s_dda
{
	t_point		start;
	t_point		end;
	t_point		delta_dist;
	t_point		side_dist;
	t_point		step;
	double		distance;
	int			side;
};

int		operate_raycast(t_game *game);
t_dda	dda_ray(t_game *game, t_point plane, t_point dir_vector, int ray);
void	render_ray(t_game *game, t_dda *dda, int ray);

#endif