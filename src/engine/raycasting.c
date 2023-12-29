#include "game.h"
#include "engine.h"

//On-key triggered, operates (resolution_pixel_width) iterations
//rendering the latest plan view according to game state
int	operate_raycast(t_game *game)
{
	t_point	plane;
	t_point	dir_vector; // TODO : add default player position, north ?
	int		curr_ray;

	curr_ray = 0;
	plane.x = 0;
	plane.y = game->display.fov / 100;
	dir_vector.x = 0;
	dir_vector.y = 1;
	while (curr_ray < game->display.win.size[WIDTH])
	{
		dda_ray(game, plane, dir_vector, curr_ray);
		//TODO: add rendering logic
	}
}
