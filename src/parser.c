/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: autheven <autheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 08:38:01 by autheven          #+#    #+#             */
/*   Updated: 2024/06/22 18:56:11 by pnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "color.h"
#include "cub3d.h"
#include "mlx.h"

static int	load_texture(t_cub3d *cub3d, int type, char *path)
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

static int	load_color(t_cub3d *cub3d, char **tokens)
{
	int	color;

	color = decode_rgb_str(tokens[1]);
	if (color == -1)
		return (1);
	if (ft_strncmp("F", tokens[0], 2) == 0)
	{
		if (cub3d->level.color_load[0])
			return (1);
		cub3d->level.color_load[0] = 1;
		cub3d->level.color[0] = color;
	}
	if (ft_strncmp("C", tokens[0], 2) == 0)
	{
		if (cub3d->level.color_load[1])
			return (1);
		cub3d->level.color_load[1] = 1;
		cub3d->level.color[1] = color;
	}
	return (0);
}

static int	parse_params_line(t_cub3d *cub3d, char **tokens)
{
	if (ft_strncmp("NO", tokens[0], 3) == 0)
		return (load_texture(cub3d, NO, tokens[1]));
	if (ft_strncmp("SO", tokens[0], 3) == 0)
		return (load_texture(cub3d, SO, tokens[1]));
	if (ft_strncmp("EA", tokens[0], 3) == 0)
		return (load_texture(cub3d, EA, tokens[1]));
	if (ft_strncmp("WE", tokens[0], 3) == 0)
		return (load_texture(cub3d, WE, tokens[1]));
	if (ft_strncmp("F", tokens[0], 2) == 0
		|| ft_strncmp("C", tokens[0], 2) == 0)
		return (load_color(cub3d, tokens));
	dprintf(2, RED "Error\n"
		PURPLE "The line is not a valid parameter\n" RESET);
	return (2);
}

int	parse_params(t_cub3d *cub3d, char *line)
{
	int				res;
	char **const	tokens = ft_split(line, ' ');

	if (tokens == NULL)
	{
		perror(RED "parse_params:ft_split" RESET);
		return (1);
	}
	if (tokens[0] == NULL || tokens[1] == NULL || tokens[2] != NULL)
	{
		dprintf(2, RED "Error\n"
			PURPLE "The line is not a valid parameter\n" RESET);
		free(*tokens);
		free(tokens);
		return (1);
	}
	printf(GREEN "Loading " ORANGE "%s" RESET " from " ORANGE "%s\n" RESET,
		tokens[0], tokens[1]);
	res = parse_params_line(cub3d, tokens);
	if (res == 1)
		dprintf(2, RED "Error\n" PURPLE "Cannot load texture\n" RESET);
	free(*tokens);
	free(tokens);
	return (res);
}
