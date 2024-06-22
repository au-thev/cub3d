/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: autheven <autheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 08:41:25 by autheven          #+#    #+#             */
/*   Updated: 2024/06/22 18:37:00 by pnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "color.h"
#include "cub3d.h"

static int	check_for_player_ew(t_cub3d *cub3d, char *line, int i)
{
	if (ft_strchr(line, 'E'))
	{
		if (cub3d->camera.x != 0)
			return (1);
		cub3d->camera.x = ft_strchr(line, 'E') - line;
		cub3d->camera.y = i;
		cub3d->camera.yaw = EA * 90;
		*ft_strchr(line, 'E') = '0';
	}
	if (ft_strchr(line, 'W'))
	{
		if (cub3d->camera.x != 0)
			return (1);
		cub3d->camera.x = ft_strchr(line, 'W') - line;
		cub3d->camera.y = i;
		cub3d->camera.yaw = WE * 90;
		*ft_strchr(line, 'W') = '0';
	}
	return (0);
}

static int	check_for_player(t_cub3d *cub3d, char *line, int i)
{
	if (ft_strchr(line, 'N'))
	{
		if (cub3d->camera.x != 0)
			return (1);
		cub3d->camera.x = ft_strchr(line, 'N') - line;
		cub3d->camera.y = i;
		cub3d->camera.yaw = NO * 90;
		*ft_strchr(line, 'N') = '0';
	}
	if (ft_strchr(line, 'S'))
	{
		if (cub3d->camera.x != 0)
			return (1);
		cub3d->camera.x = ft_strchr(line, 'S') - line;
		cub3d->camera.y = i;
		cub3d->camera.yaw = SO * 90;
		*ft_strchr(line, 'S') = '0';
	}
	return (check_for_player_ew(cub3d, line, i));
}

int	search_player(t_cub3d *cub3d)
{
	size_t	i;

	i = 0;
	while (cub3d->level.map[i] != NULL)
	{
		if (check_for_player(cub3d, cub3d->level.map[i], i))
			return (1);
		i++;
	}
	return (0);
}

int	flood_fill(t_cub3d *cub3d, int x, int y, int width)
{
	char **const	map = cub3d->level.map;
	int				res;

	width = ft_strlen(map[y]);
	if (map[y][x] == '1' || map[y][x] == '.')
		return (0);
	if (map[y][x] == ' ')
		return (2);
	if (x <= 0 || x >= width - 1 || y <= 0 || y >= cub3d->level.map_height - 1)
		if (map[y][x] == '0')
			return (1);
	map[y][x] = '.';
	res = flood_fill(cub3d, x, y + 1, 0);
	if (res)
		return (res);
	res = flood_fill(cub3d, x, y - 1, 0);
	if (res)
		return (res);
	res = flood_fill(cub3d, x + 1, y, 0);
	if (res)
		return (res);
	res = flood_fill(cub3d, x - 1, y, 0);
	return (res);
}

int	flood_fill_start(t_cub3d *cub3d, int x, int y)
{
	int	res;

	printf("Starting flood fill at Y=%d X=%d\n", y, x);
	printf("Map Max Width: %d\n", cub3d->level.map_width);
	printf("Map Max Height: %d\n", cub3d->level.map_height);
	if (!cub3d->level.map)
		return (1);
	res = flood_fill(cub3d, x, y, 0);
	if (res == 1)
		dprintf(2, "\033[0;31mError\n\033[0;35mMap not enclosed\n\033[0m");
	else if (res == 2)
		dprintf(2, RED "Error\n" PURPLE "Map has gap(s)\n" RESET);
	return (res > 0);
}
