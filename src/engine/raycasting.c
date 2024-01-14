#include "game.h"
#include "engine.h"
#include <stdio.h> 
#include "mlx.h"

//On-key triggered, operates (resolution_pixel_width) iterations
//rendering the latest plan view according to game state
int	operate_raycast(t_game *game)
{
	t_point	plane;
	// t_dda	dda;
	t_point	dir_vector; // TODO : add default player position, north ?
	int		curr_ray;

	curr_ray = 0;
	plane.x = 0;
	plane.y = -game->display.fov / 100;
	// W = vector : -1 / 0  | plane : 0 / -0.66
	// E = vector : 1 / 0  | plane : 0 / 0.66
	// N = vector : 0 / -1  | plane : 0.66 / 0
	// S = vector : 0 / 1  | plane : -0.66 / 0
	dir_vector.x = -1;
	dir_vector.y = 0;
	while (curr_ray < game->display.win.size[WIDTH])
	{
		dda_ray(game, plane, dir_vector, curr_ray);
		//TODO: add rendering logic
		//render_ray(game, dda);
		curr_ray++;
	}
	mlx_put_image_to_window(game->display.ptr, game->display.win.ptr, game->display.win.buffer.ptr, 0, 0);
	return (0);
}
