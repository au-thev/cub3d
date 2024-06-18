/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: autheven <autheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 08:41:25 by autheven          #+#    #+#             */
/*   Updated: 2024/06/17 18:47:35 by autheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "cub3d.h"

static void	check_for_player_ew(t_cub3d *cub3d, char *line, int i)
{
	if (ft_strchr(line, 'E'))
	{
		cub3d->camera.x = ft_strchr(line, 'E') - line - 1;
		cub3d->camera.y = i;
		cub3d->camera.yaw = EA * 90;
		*ft_strchr(line, 'E') = '0';
	}
	if (ft_strchr(line, 'W'))
	{
		cub3d->camera.x = ft_strchr(line, 'W') - line - 1;
		cub3d->camera.y = i;
		cub3d->camera.yaw = WE * 90;
		*ft_strchr(line, 'W') = '0';
	}
}

void	check_for_player(t_cub3d *cub3d, char *line, int i)
{
	if (ft_strchr(line, 'N'))
	{
		cub3d->camera.x = ft_strchr(line, 'N') - line - 1;
		cub3d->camera.y = i;
		cub3d->camera.yaw = NO * 90;
		*ft_strchr(line, 'N') = '0';
	}
	if (ft_strchr(line, 'S'))
	{
		cub3d->camera.x = ft_strchr(line, 'S') - line - 1;
		cub3d->camera.y = i;
		cub3d->camera.yaw = SO * 90;
		*ft_strchr(line, 'S') = '0';
	}
	check_for_player_ew(cub3d, line, i);
}

static int	is_player(char c)
{
	if (c == 'N')
		return (1);
	if (c == 'S')
		return (1);
	if (c == 'E')
		return (1);
	if (c == 'W')
		return (1);
	if (c == '^')
		return (1);
	if (c == 'v')
		return (1);
	if (c == '>')
		return (1);
	if (c == '<')
		return (1);
	return (0);
}

int	flood_fill(t_cub3d *cub3d, int x, int y, int width)
{
	char	**map;
	int		res;

	map = cub3d->level.map;
	width = ft_strlen(map[y]);
	res = 0;
	if (!*map)
		return (0);
	if (map[y][x] == '1' || map[y][x] == '.')
		return (0);
	if (x <= 0 || x >= width - 2 || y <= 0 || y >= cub3d->level.map_height - 2)
		if (map[y][x] == '0')
			return (1);
	if (map[y][x - 1] == 'X' || map[y][x + 1] == 'X' ||
		map[y - 1][x] == 'X' || map[y + 1][x] == 'X')
		if (map[y][x] != '1')
			map[y][x] = '*';
	if (map[y][x] != '0' || is_player(map[y][x]))
		return (0);
	map[y][x] = '.';
	res += flood_fill(cub3d, x, y + 1, 0);
	res += flood_fill(cub3d, x, y - 1, 0);
	res += flood_fill(cub3d, x + 1, y, 0);
	res += flood_fill(cub3d, x - 1, y, 0);
	return (res > 0);
}

int	flood_fill_start(t_cub3d *cub3d, int x, int y)
{
	printf("Starting flood fill at Y=%d X=%d\n", y, x);
	printf("Map Max Width: %d\n", cub3d->level.map_width);
	printf("Map Max Height: %d\n", cub3d->level.map_height);
	if (!cub3d->level.map)
		return (1);
	if (flood_fill(cub3d, x, y, ft_strlen(cub3d->level.map[y])))
	{
		dprintf(2, "\033[0;31mError\n\033[0;35mMap not enclosed\n\033[0m");
		return (1);
	}
	return (0);
}
