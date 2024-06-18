/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: autheven <autheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 08:39:11 by autheven          #+#    #+#             */
/*   Updated: 2024/06/17 19:17:07 by autheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	map_add(t_cub3d *cub3d, int i, char *line, int j)
{
	char	**map_swap;

	j = 0;
	map_swap = cub3d->level.map;
	cub3d->level.map = ft_calloc(i + 1, sizeof(line));
	if (cub3d->level.map == NULL)
		return (1);
	ft_memmove(cub3d->level.map, map_swap, (i) * sizeof(line));
	if (line)
	{
		while (line[j])
		{
			if (ft_isspace(line[j]))
				line[j] = '0';
			j++;
		}
	}
	cub3d->level.map[i] = line;
	free(map_swap);
	if (ft_strlen(line) > (size_t)cub3d->level.map_width)
		cub3d->level.map_width = ft_strlen(line);
	check_for_player(cub3d, line, i);
	if (line == 0)
		return (1);
	return (0);
}

int	parse_map(t_cub3d *cub3d, char *line, int fd)
{
	char	*line_addr;
	int		i;

	cub3d->level.map_width = 0;
	cub3d->level.map_height = 0;
	line = ft_strdup(line);
	line_addr = line;
	if (ft_isspace(*line))
		while (ft_isspace(*line))
			*line++ = '0';
	if (!ft_isdigit(*line))
		return (1);
	i = 0;
	line = line_addr;
	cub3d->level.map = ft_calloc(i + 1, sizeof(line));
	if (cub3d->level.map == NULL)
		return (1);
	cub3d->level.map[i++] = line;
	while (!map_add(cub3d, i++, ft_readline(fd), 0))
		;
	map_add(cub3d, i, 0, 0);
	cub3d->level.map_height = i;
	return (flood_fill_start(cub3d, cub3d->camera.x, cub3d->camera.y));
}
