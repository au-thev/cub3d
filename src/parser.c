/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: autheven <autheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 08:38:01 by autheven          #+#    #+#             */
/*   Updated: 2024/06/17 19:15:14 by autheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "cub3d.h"
#include "mlx.h"

int	load_texture(t_cub3d *cub3d, char type, char *path)
{
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

int	decode_rgb_str(char *s)
{
	int		irgb;
	int		r;
	int		g;
	int		b;

	s = ft_strchr(s, ' ') + 1;
	r = ft_atoi(s);
	s = ft_strchr(s, ',') + 1;
	g = ft_atoi(s);
	s = ft_strchr(s, ',') + 1;
	b = ft_atoi(s);
	irgb = (0 << 24 | r << 16 | g << 8 | b);
	return (irgb);
}

int	load_color(t_cub3d *cub3d, char *token, char *s)
{
	if (ft_strncmp("F", token, 2) == 0)
		cub3d->level.color_load[0] = 1;
	if (ft_strncmp("C", token, 2) == 0)
		cub3d->level.color_load[1] = 1;
	return (decode_rgb_str(s));
}

int	parse_params(t_cub3d *cub3d, char *line)
{
	char	**tokens;
	int		res;

	tokens = ft_split(line, ' ');
	res = 0;
	if (ft_strncmp("NO", tokens[0], 3) == 0)
		res = load_texture(cub3d, NO, tokens[1]);
	if (ft_strncmp("SO", tokens[0], 3) == 0)
		res = load_texture(cub3d, SO, tokens[1]);
	if (ft_strncmp("EA", tokens[0], 3) == 0)
		res = load_texture(cub3d, EA, tokens[1]);
	if (ft_strncmp("WE", tokens[0], 3) == 0)
		res = load_texture(cub3d, WE, tokens[1]);
	if (ft_strncmp("F", tokens[0], 2) == 0)
		cub3d->level.color[0] = load_color(cub3d, tokens[0], line);
	if (ft_strncmp("C", tokens[0], 2) == 0)
		cub3d->level.color[1] = load_color(cub3d, tokens[0], line);
	printf("\033[0;32mLoading \033[0;33m%s\033[0m from \033[0;33m%s\033[0m\n",
		tokens[0], tokens[1]);
	if (res)
		dprintf(2, "\033[0;31mError\n\033[0;35mCannot load texture\n\033[0m");
	free(*tokens);
	free(tokens);
	return (res);
}
