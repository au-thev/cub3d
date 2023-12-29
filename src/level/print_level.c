/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_level.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 14:14:47 by antheven          #+#    #+#             */
/*   Updated: 2023/12/19 21:38:39 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "level.h"
#include <stdio.h>

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

int	flood_fill(t_lvl *level, int x, int y, int width)
{
	char	**map;

	map = level->map;
	if (x <= 0 || x >= width - 2 || y <= 0 || y >= level->map_length - 2)
	{
		if (level->map[y][x] != '1')
			level->map[y][x] = '*';
		return (1);
	}
	if (map[y][x - 1] == 'X' || map[y][x + 1] == 'X' ||
		map[y - 1][x] == 'X' || map[y + 1][x] == 'X')
		if (map[y][x] != '1')
			map[y][x] = '*';
	if (is_player(level->map[y][x]))
		return (0);
	if (level->map[y][x] != '0')
		if (is_player(level->map[y][x]) == 0)
			return (0);
	level->map[y][x] = '.';
	flood_fill(level, x, y + 1, ft_strlen(level->map[y + 1]));
	flood_fill(level, x, y - 1, ft_strlen(level->map[y - 1]));
	flood_fill(level, x + 1, y, ft_strlen(level->map[y]));
	flood_fill(level, x - 1, y, ft_strlen(level->map[y]));
	return (0);
}

void	flood_fill_start(t_lvl *level, int x, int y)
{
	printf("Starting flood fill at Y=%d X=%d\n", y, x);
	printf("Map Max Width: %d\n", level->map_width);
	printf("Map Max Height: %d\n", level->map_length);
	if (!level->map)
		return ;
	if (flood_fill(level, x, y, ft_strlen(level->map[y])))
		printf("no walls\n");
}

static char	get_map_char(char c)
{
	char	form[100];
	char	r;

	ft_bzero(form, 100);
	form['0'] = ' ';
	form['1'] = '#';
	form['2'] = '2';
	form['3'] = '3';
	form['N'] = '^';
	form['S'] = 'v';
	form['E'] = '>';
	form['W'] = '<';
	form[' '] = ' ';
	form['.'] = '~';
	r = form[(int)c];
	if (r == 0)
		r = c;
	return (r);
}

void	print_level(t_lvl *level)
{
	char		**map;
	int			i;
	size_t		j;

	map = level->map;
	i = 0;
	if (!map)
		return ;
	flood_fill_start(level, level->player_start.x, level->player_start.y);
	while (i < level->map_length)
	{
		printf("[MAP] (line %02d) (%03ld), ", i, ft_strlen(map[i]));
		j = 0;
		while (j < ft_strlen(map[i]))
		{
			if (ft_isspace(map[i][j]))
				map[i][j] = '0';
			printf("%c", get_map_char(map[i][j]));
			j++;
		}
		printf("\n");
		i++;
	}
}
