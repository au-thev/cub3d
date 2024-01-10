/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_level.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 08:53:54 by antheven          #+#    #+#             */
/*   Updated: 2024/01/03 20:50:05 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "level.h"
#include <fcntl.h>
#include <stdio.h>

void	check_for_player(t_lvl *level, char *line, int i)
{
	if (ft_strchr(line, 'N'))
	{
		level->player_start.y = i;
		level->player_start.x = ft_strchr(line, 'N') - line - 1;
	}
	if (ft_strchr(line, 'S'))
	{
		level->player_start.y = i;
		level->player_start.x = ft_strchr(line, 'S') - line - 1;
	}
	if (ft_strchr(line, 'E'))
	{
		level->player_start.y = i;
		level->player_start.x = ft_strchr(line, 'E') - line - 1;
	}
	if (ft_strchr(line, 'W'))
	{
		level->player_start.y = i;
		level->player_start.x = ft_strchr(line, 'W') - line - 1;
	}
	printf("Player Y=%f, X=%f\n", level->player_start.y, level->player_start.x);
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
	free(line);
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
	level->map_width = 0;
	if (level->fd < 0)
	{
		perror("open()");
		return (1);
	}
	line = (char *)1;
	while (line)
	{
		line = ft_readline(level->fd);
		if (!line)
			break ;
		if (check_lvl_arg(level, line))
			if (parse_map(level, line))
				break ;
	}
	fit_level(level);
	return (0);
}
