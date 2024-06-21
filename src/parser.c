/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: autheven <autheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 08:38:01 by autheven          #+#    #+#             */
/*   Updated: 2024/06/20 14:59:00 by pnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "color.h"
#include "cub3d.h"
#include "mlx.h"

static int	load_texture(t_cub3d *cub3d, char type, char *path)
{
	if (cub3d->level.texture[type].loaded)
		return (1);
	cub3d->level.texture[type].ptr = mlx_xpm_file_to_image(cub3d->mlx.ptr,
			path, &(cub3d->level.texture[type].size[0]),
			&(cub3d->level.texture[type].size[1]));
	if (!cub3d->level.texture[type].ptr)
		return (1);
	cub3d->level.texture[type].data = mlx_get_data_addr(
			cub3d->level.texture[type].ptr, &cub3d->level.texture[type].bpp,
			&cub3d->level.texture[type].sl,
			&cub3d->level.texture[type].endian);
	if (!cub3d->level.texture[type].data)
		mlx_destroy_image(cub3d->mlx.ptr, cub3d->level.texture[type].ptr);
	if (!cub3d->level.texture[type].data)
		return (1);
	cub3d->level.texture[type].loaded = 1;
	return (0);
}

static int	load_color(t_cub3d *cub3d, char *line)
{
	int	color;

	color = decode_rgb_str(line + 2);
	if (color == -1)
		return (1);
	if (ft_strncmp("F ", line, 2) == 0)
	{
		cub3d->level.color_load[0] = 1;
		cub3d->level.color[0] = color;
	}
	if (ft_strncmp("C ", line, 2) == 0)
	{
		cub3d->level.color_load[1] = 1;
		cub3d->level.color[1] = color;
	}
	return (0);
}

int	parse_params(t_cub3d *cub3d, char *line)
{
	int		res;

	res = 0;
	printf(GREEN "Loading parameter : " ORANGE "%s\n" RESET, line);
	if (ft_strncmp("NO ", line, 3) == 0)
		res += load_texture(cub3d, NO, line + 3);
	else if (ft_strncmp("SO ", line, 3) == 0)
		res += load_texture(cub3d, SO, line + 3);
	else if (ft_strncmp("EA ", line, 3) == 0)
		res += load_texture(cub3d, EA, line + 3);
	else if (ft_strncmp("WE ", line, 3) == 0)
		res += load_texture(cub3d, WE, line + 3);
	else if (ft_strncmp("F ", line, 2) == 0
		|| ft_strncmp("C ", line, 2) == 0)
		res += load_color(cub3d, line);
	else
	{
		dprintf(2, RED "Error\n"
			ORANGE "The line is not a valid parameter\n" RESET);
		return (1);
	}
	if (res)
		dprintf(2, RED "Error\n" ORANGE "Cannot load texture\n" RESET);
	return (res);
}
