/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 19:12:29 by antheven          #+#    #+#             */
/*   Updated: 2023/12/17 10:49:44 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include "level.h"
#include "images.h"
#include "mlx.h"
#include <stdio.h>

int	load_textures(t_display *display)
{
	t_tex_type	tex;
	t_lvl		*level;

	tex = TEX_NB;
	level = &(display)->level;
	while (tex-- > 0)
	{
		if (level->textures[tex].image.type == IMAGE)
		{
			printf("Loading texture [%s] '%s'\n", level->textures[tex].prefix,
				level->textures[tex].path);
			level->textures[tex].image.ptr = mlx_xpm_file_to_image(
					display->ptr,
					level->textures[tex].path,
					&level->textures[tex].image.size[WIDTH],
					&level->textures[tex].image.size[HEIGHT]);
			if (!level->textures[tex].image.ptr)
				perror("load_textures()");
			if (!level->textures[tex].image.ptr)
				return (1);
			level->textures[tex].image.data = mlx_get_data_addr(
					level->textures[tex].image.ptr,
					&level->textures[tex].image.bits_per_pixel,
					&level->textures[tex].image.size_line,
					&level->textures[tex].image.endian);
		}
	}
	return (0);
}
