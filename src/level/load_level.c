/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_level.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 08:53:54 by antheven          #+#    #+#             */
/*   Updated: 2023/12/15 16:23:44 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "level.h"
#include <fcntl.h>
#include <stdio.h>

static int	parse_map(t_lvl *level, char *line)
{
	char	*line_addr;
	char	**map_swap;
	int		i;

	line_addr = line;
	if (ft_isspace(*line))
		while (ft_isspace(*line++))
			;
	if (!ft_isdigit(*line))
		return (1);
	i = 0;
	line = line_addr;
	level->map = ft_calloc(++i + 1, sizeof(line));
	level->map[i - 1] = line;
	while (line)
	{
		map_swap = level->map;
		level->map = ft_calloc(i + 1, sizeof(line));
		ft_memmove(level->map, map_swap, i);
		free(map_swap);
	printf("[parse_map()] [line no: %d] %s\n", i-1, line);
		level->map[i - 1] = ft_readline(level->fd);
		line = level->map[i++ - 1];
	}
	level->map[i] = 0;
	printf("[parse_map()] [line no max: %d]\n", i);
	while (i > 0)
	{
		printf("%s\n", level->map[--i]);
	}
	return (1);
}

static int	check_lvl_arg(t_lvl *level, char *line)
{
	char		**args;
	t_tex_type	tex_type;

	if (ft_strlen(line))
		args = ft_split(line, ' ');
	tex_type = TEX_NB;
	if (ft_strncmp(args[0], "NO", 2) == 0)
		tex_type = NO;
	if (ft_strncmp(args[0], "SO", 2) == 0)
		tex_type = SO;
	if (ft_strncmp(args[0], "WE", 2) == 0)
		tex_type = WE;
	if (ft_strncmp(args[0], "EA", 2) == 0)
		tex_type = EA;
	if (ft_strncmp(args[0], "F", 1) == 0)
		tex_type = F;
	if (ft_strncmp(args[0], "C", 1) == 0)
		tex_type = C;
	//if (tex_type != TEX_NB)
	if (tex_type == TEX_NB)
		if (parse_map(level, line))
			return (1);
	printf("[%s, %d] %s\n", args[0], tex_type, args[1]);
	level->textures[tex_type].prefix = args[0];
	level->textures[tex_type].path = args[1];
	free(args);
	level->textures[tex_type].image.type = IMAGE;
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
		//check_lvl_arg(level, line);
		if (check_lvl_arg(level, line))
			return (1);
	}
	return (0);
}
