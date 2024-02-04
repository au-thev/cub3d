#include "game.h"
#include "engine.h"
#include "math.h"
#include "libft.h"
#include <stdio.h>
#include "mlx.h"

static void	print_level_custom(t_lvl level, t_point end)
{
	char		**map;
	int			i;
	int			j;

	map = level.map;
	i = 0;
	if (!map)
		return ;
	printf("end : %f / %f\n", end.x, end.y);
	while (i < level.map_length)
	{
		printf("[MAP] (line %02d) (%03ld), ", i, ft_strlen(map[i]));
		j = 0;
		while ((size_t)j < ft_strlen(map[i]))
		{
			if (ft_isspace(map[i][j]))
				map[i][j] = '0';
			// if (i == (int)end.y % (int)level.map_width 
			// && j == (int)end.x % (int)level.map_length)clear
			if (i == end.y && j == end.x)
			{	
				// printf("i : %d\n", i);
				// printf("j : %d\n", j);
				printf("\033[31m");
			}
			printf("%c", map[i][j]);
			printf("\033[0m");
			j++;
		}
		printf("\n");
		i++;
	}
}


static void compute_delta_dist(t_dda *dda, t_point dir)
{
	// dda->delta_dist.x = sqrt(1 + (dir.y * dir.y) / (dir.x * dir.x));
	// dda->delta_dist.y = sqrt(1 + (dir.x * dir.x) / (dir.y * dir.y));
	dda->delta_dist.x = fabs(1 / dir.x);
	dda->delta_dist.y = fabs(1 / dir.y);
	// dda->delta_dist.x = (dir.y == 0) ? 0 : ((dir.x == 0) ? 1 : fabs(1 / dir.x));
	// dda->delta_dist.y = (dir.x == 0) ? 0 : ((dir.y == 0) ? 1 : fabs(1 / dir.y));
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


t_dda	dda_ray(t_game *game, t_point plane, \
	t_point dir_vector, int ray)
{
	t_dda			*dda;
	t_point			ray_dir;
	double			camera;
	int				completion;
	int				max_iter;

	completion = 0;
	max_iter = 200; //TODO: find default value
	dda = ft_calloc(1, sizeof(*dda));
	camera = 2 * ray / game->display.win.size[WIDTH] - 1;
	ray_dir.x = dir_vector.x + plane.x * camera;
	ray_dir.y = dir_vector.y + plane.y * camera;
	dda->start = game->display.level.player_start;
	dda->end = game->display.level.player_start;
	// printf("///////////////////\n");
	// printf("camera : %f \n", camera);
	// printf("ray_dir.x : %f \n", ray_dir.x);
	// printf("ray_dir.y : %f \n", ray_dir.y);
	// printf("dir_vector.x : %f \n", dir_vector.x);
	// printf("dir_vector.y : %f \n", dir_vector.y);
	// printf("plane.x : %f \n", plane.x);
	// printf("plane.y : %f \n", plane.y);
	compute_delta_dist(dda, ray_dir);
	while (!completion) {
		if (dda->side_dist.x < dda->side_dist.y) {
			dda->side_dist.x += dda->delta_dist.x;
			dda->end.x += dda->step.x;
			dda->side = 0;
		} else {
			dda->side_dist.y += dda->delta_dist.y;
			dda->end.y += dda->step.y;
			dda->side = 1;
		}
		if (game->display.level.map[(int)dda->end.y]
		[(int)dda->end.x] == '1' || !max_iter)
			completion = 1;
		max_iter--;
	}
	// print_level_custom(game->display.level, dda->end);
	mlx_string_put(game->display.ptr, game->display.win.ptr, 500, 500, 0xFFFFFF, 
	"Current coords x / y : ");
	// printf("player_start.x : %f \n", game->display.level.player_start.x);
	// printf("player_start.y : %f \n", game->display.level.player_start.y);
	mlx_string_put(game->display.ptr, game->display.win.ptr, 500, 520, 0xFFFFFF, 
	ft_itoa((int)game->display.level.player_start.x));
	mlx_string_put(game->display.ptr, game->display.win.ptr, 530, 520, 0xFFFFFF, 
	ft_itoa((int)game->display.level.player_start.y));
	// game->display.level.player_start.x = floor(game->display.level.player_start.x);
	// game->display.level.player_start.y = floor(game->display.level.player_start.y);
	render_ray(game, dda, ray, ray_dir);
	return (*dda);
}


	// print_level_custom(game->display.level, dda->end);
	// printf("end.x : %f \n", dda->end.x);
	// printf("end.y : %f \n", dda->end.y);
	// printf("final x/y: %c \n", game->display.level.map
	// 	[(int)dda->end.y % (int)game->display.level.map_width]
	// 	[(int)dda->end.x % (int)game->display.level.map_length]);
	// printf("completed raycast for ray : %d, obtaining max iter : %d\n", ray, max_iter);