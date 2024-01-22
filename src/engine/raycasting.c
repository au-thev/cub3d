#include "game.h"
#include "engine.h"
#include <stdio.h> 
#include "mlx.h"
#include "utils.h"
#include <math.h>

//On-key triggered, operates (resolution_pixel_width) iterations
//rendering the latest plan view according to game state
int	operate_raycast(t_game *game)
{
	t_point	plane;
	// t_dda	dda;
	t_point	dir_vector; // TODO : add default player position, north ?
	int		curr_ray;

	curr_ray = 0;
	plane.x = -sin(deg_to_rad(game->player.direction));
	plane.y = cos(deg_to_rad(game->player.direction));//-game->display.fov / 100;
	// W = vector : -1 / 0  | plane : 0 / -0.66
	// E = vector : 1 / 0  | plane : 0 / 0.66
	// N = vector : 0 / -1  | plane : 0.66 / 0
	// S = vector : 0 / 1  | plane : -0.66 / 0
	// printf("Player Direction: %f\n", deg_to_rad(game->player.direction));
	dir_vector.x = cos(deg_to_rad(game->player.direction));
	dir_vector.y = sin(deg_to_rad(game->player.direction));
	while (curr_ray < game->display.win.size[WIDTH])
	{
		dda_ray(game, plane, dir_vector, curr_ray);
		//TODO: add rendering logic
		//render_ray(game, dda);
		curr_ray++;
	}
	return (0);
}
