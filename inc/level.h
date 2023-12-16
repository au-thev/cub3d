/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 09:39:19 by antheven          #+#    #+#             */
/*   Updated: 2023/12/16 14:49:55 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEVEL_H
# define LEVEL_H

# include "images.h"

typedef	struct s_lvl	t_lvl;
typedef	struct s_tex	t_tex;
typedef	enum e_tex		t_tex_type;

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

struct s_lvl
{
	t_tex	textures[6];
	char	**map;
	int		fd;
};

int		load_level(t_lvl *level, char *level_file);
void	print_level(t_lvl *level);

#endif