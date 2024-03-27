/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coltcivers <coltcivers@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 09:39:19 by antheven          #+#    #+#             */
/*   Updated: 2024/03/22 15:41:57 by coltcivers       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEVEL_H
# define LEVEL_H

# include "images.h"

typedef struct s_lvl		t_lvl;
typedef struct s_tex		t_tex;
typedef struct s_point		t_point;
typedef enum e_tex			t_tex_type;

enum e_tex
{
	NO,
	SO,
	WE,
	EA,
	F,
	C,
	TEX_NB
};

struct s_tex
{
	t_tex_type	facing;
	char		*prefix;
	char		*path;
	t_image		image;
};

struct s_point
{
	double	y;
	double	x;
};

struct s_lvl
{
	t_tex		textures[6];
	char		**map;
	int			map_length;
	int			map_width;
	t_point		player_start;
	int			fd;
	char		loaded;
	int			initial_direction;
};

int		load_level(t_lvl *level, char *level_file);
int		parse_map(t_lvl *level, char *line);
void	print_level(t_lvl *level);
int		map_add(t_lvl *level, int i, char *line);
void	fit_level(t_lvl *level);
int		check_map(t_lvl *level);

#endif