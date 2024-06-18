/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: autheven <autheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 13:30:35 by autheven          #+#    #+#             */
/*   Updated: 2024/06/17 19:16:45 by autheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "cub3d.h"
#include "mlx.h"

static char	mapcol(char c)
{
	char	form[100];
	char	r;

	ft_bzero(form, 100);
	form['0'] = 32;
	form['1'] = 31;
	form['2'] = 0;
	form['3'] = 0;
	form['N'] = 33;
	form['S'] = 33;
	form['E'] = 33;
	form['W'] = 33;
	form[' '] = 33;
	form['.'] = 32;
	r = form[(int)c];
	if (r == 0)
		r = c;
	return (r);
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

void	print_level(t_cub3d *cub3d)
{
	char		**map;
	int			i;
	size_t		j;

	map = cub3d->level.map;
	i = 0;
	if (!map)
		return ;
	while (i < cub3d->level.map_height)
	{
		printf("[\033[0;32mMAP\033[0m] (line \033[0;33m%02d\033[0m) (\033[0;33m\
%03ld\033[0m), ", i, ft_strlen(map[i]));
		j = 0;
		while (j < ft_strlen(map[i]))
		{
			if (ft_isspace(map[i][j]))
				map[i][j] = '0';
			printf("\033[0;%dm%c", mapcol(map[i][j]), get_map_char(map[i][j]));
			j++;
		}
		printf("\n");
		i++;
	}
}

int	load_level(t_cub3d *cub3d, char *path)
{
	int		fd;
	char	*line;
	int		res;

	fd = open(path, O_RDONLY);
	if (fd <= 0)
		return (1);
	res = 0;
	line = ft_readline(fd);
	while (line)
	{
		if (ft_strlen(line) > 0)
		{
			if (ft_atoi(line) == 0)
				res += parse_params(cub3d, line);
			if (ft_atoi(line) != 0)
				res += parse_map(cub3d, line, fd);
		}
		free(line);
		line = ft_readline(fd);
	}
	free(line);
	print_level(cub3d);
	close(fd);
	return (res > 0);
}
