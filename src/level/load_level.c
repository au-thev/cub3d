/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_level.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 08:53:54 by antheven          #+#    #+#             */
/*   Updated: 2023/12/17 10:29:51 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "level.h"
#include <fcntl.h>
#include <stdio.h>

static int	map_add(t_lvl *level, int i, char *line)
{
	char	**map_swap;

	map_swap = level->map;
	level->map = ft_calloc(i + 1, sizeof(line));
	ft_memmove(level->map, map_swap, (i) * sizeof(line));
	level->map[i] = line;
	free(map_swap);
	if (line == 0)
		return (1);
	return (0);
}

static int	parse_map(t_lvl *level, char *line)
{
	char	*line_addr;
	int		i;

	line_addr = line;
	if (ft_isspace(*line))
		while (ft_isspace(*line++))
			;
	if (!ft_isdigit(*line))
		return (1);
	i = 0;
	line = line_addr;
	level->map = ft_calloc(i + 1, sizeof(line));
	level->map[i++] = line;
	while (!map_add(level, i++, ft_readline(level->fd)))
		;
	return (2);
}

static t_tex_type	get_token_type(char *s)
{
	t_tex_type	tex_type;

	tex_type = TEX_NB;
	if (ft_strncmp(s, "NO", 2) == 0)
		tex_type = NO;
	if (ft_strncmp(s, "SO", 2) == 0)
		tex_type = SO;
	if (ft_strncmp(s, "WE", 2) == 0)
		tex_type = WE;
	if (ft_strncmp(s, "EA", 2) == 0)
		tex_type = EA;
	if (ft_strncmp(s, "F", 1) == 0)
		tex_type = F;
	if (ft_strncmp(s, "C", 1) == 0)
		tex_type = C;
	return (tex_type);
}

static int	check_lvl_arg(t_lvl *level, char *line)
{
	char		**args;
	t_tex_type	tex_type;

	if (!(ft_strlen(line) && ft_strchr(line, ' ') && *line != ' '))
		return (1);
	args = ft_split(line, ' ');
	tex_type = get_token_type(args[0]);
	if (tex_type == TEX_NB)
		return (1);
	printf("[%s, %d] %s\n", args[0], tex_type, args[1]);
	level->textures[tex_type].prefix = args[0];
	level->textures[tex_type].path = args[1];
	free(args);
	level->textures[tex_type].image.type = IMAGE;
	if (tex_type == F || tex_type == C)
		level->textures[tex_type].image.type = COLOR;
	return (0);
}

int	load_level(t_lvl *level, char *level_file)
{
	char	*line;

	level->fd = open(level_file, O_RDONLY);
	if (level->fd < 0)
	{
		perror("open()");
		return (1);
	}
	line = ft_calloc(1, 1);
	*line = 1;
	while (line)
	{
		line = ft_readline(level->fd);
		if (!line)
			break ;
		if (check_lvl_arg(level, line))
			if (parse_map(level, line))
				break ;
	}
	return (0);
}
