/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coltcivers <coltcivers@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 00:58:21 by coltcivers        #+#    #+#             */
/*   Updated: 2024/03/20 00:58:37 by coltcivers       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H

# include "level.h"
# include "images.h"
# include "game.h"

typedef struct s_point	t_point;
typedef struct s_dda	t_dda;
typedef struct s_render	t_render;

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

struct s_render
{
	double		draw_start;
	double		draw_end;
	double		line_height;
	int			ray;
	int			i;
};

int		operate_raycast(t_game *game);
t_dda	dda_ray(t_game *game, t_point plane, t_point dir_vector, int ray);
void	render_ray(t_game *game, t_dda *dda, int ray, t_point ray_dir);

#endif