/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coltcivers <coltcivers@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 23:32:23 by coltcivers        #+#    #+#             */
/*   Updated: 2024/03/26 12:43:44 by coltcivers       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "engine.h"
#include "mlx.h"
#include <math.h>

static unsigned int	get_pixel_color(t_image image, int x, int y)
{
	int		color;
	// int		temp_a;

	color = 0xFFFFFF;
	color = *(unsigned int *)(image.data + (y % image.size[HEIGHT]
				* image.size_line + x % image.size[WIDTH]
				* (image.bits_per_pixel / 8))
			% (image.size[WIDTH] * image.size[HEIGHT]
				* image.bits_per_pixel));
	return (color);
}

static int	render_ray_helper_2(t_game *game,
	t_render renderer, double wall_x, int i)
{
	double			tex_pos;

	tex_pos
		= (renderer.draw_start - game->display.win.size[HEIGHT]
			/ 2 + renderer.line_height / 2)
		* 1.0 * game->display.level.textures[0].image.size[HEIGHT]
		/ renderer.line_height;
	while (i < renderer.draw_end)
	{
		tex_pos += 1.0 * game->display.level.textures[0].image.size[HEIGHT]
			/ renderer.line_height;
		pixel_put(&game->display.win.buffer, renderer.ray, i,
			get_pixel_color(game->display.level.textures[0].image,
				(int)(wall_x * (double)(game->display.level.textures[0]
						.image.size[WIDTH])),
				(int)tex_pos & ((int)game->display.level.textures[0]
					.image.size[HEIGHT] - 1)));
		i++;
	}
	return (i);
}

static void	render_ray_helper(t_game *game, t_dda *dda,
	t_render renderer, t_point ray_dir)
{
	double			wall_x;
	// double			tex_pos;
	double			i;
	int				color_floor;
	int				color_ceiling;
	
	i = 0;
	color_floor = ((game->display.level.textures[F].image.color[1] & 0xff) << 16) 
		+ ((game->display.level.textures[F].image.color[2] & 0xff) << 8)
		 + (game->display.level.textures[F].image.color[3] & 0xff);
	color_ceiling = ((game->display.level.textures[C].image.color[1] & 0xff) << 16) 
		+ ((game->display.level.textures[C].image.color[2] & 0xff) << 8)
		 + (game->display.level.textures[C].image.color[3] & 0xff);
	while (i < renderer.draw_start)
		pixel_put(&game->display.win.buffer, renderer.ray, i++, color_floor);
	if (dda->side == 0)
		wall_x = dda->start.y + dda->distance * ray_dir.y;
	else
		wall_x = dda->start.x + dda->distance * ray_dir.x;
	wall_x -= floor((wall_x));
	i = render_ray_helper_2(game, renderer, wall_x, i);
	while (i < game->display.win.size[HEIGHT])
		pixel_put(&game->display.win.buffer, renderer.ray, i++, color_ceiling);
}

void	render_ray(t_game *game, t_dda *dda, int ray, t_point ray_dir)
{
	t_render		renderer;

	renderer.draw_end = 0;
	renderer.draw_start = 0;
	renderer.line_height = 0;
	renderer.ray = ray;
	if (dda->side == 0)
		dda->distance = dda->side_dist.x - dda->delta_dist.x;
	else
		dda->distance = dda->side_dist.y - dda->delta_dist.y;
	renderer.line_height = game->display.win.size[HEIGHT] / dda->distance;
	renderer.draw_start = -(renderer.line_height)
		/ 2 + game->display.win.size[HEIGHT] / 2;
	if (renderer.draw_start < 0)
		renderer.draw_start = 0;
	renderer.draw_end = renderer.line_height
		/ 2 + game->display.win.size[HEIGHT] / 2;
	if (renderer.draw_end >= game->display.win.size[HEIGHT])
		renderer.draw_end = game->display.win.size[HEIGHT] - 1;
	render_ray_helper(game, dda, renderer, ray_dir);
}
