/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: autheven <autheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 08:39:11 by autheven          #+#    #+#             */
/*   Updated: 2024/06/22 18:37:16 by pnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "color.h"
#include "cub3d.h"

#define MAP_CHARS	"01NSEW "

static char	*sanitize_map_line(char const line[], size_t width)
{
	size_t		i;
	char *const	new_str = malloc((width + 1) * sizeof(*new_str));

	if (new_str == NULL)
	{
		perror(RED "sanitize_map_line:malloc" RESET);
		return (NULL);
	}
	i = 0;
	while (line[i] != '\0')
	{
		new_str[i] = line[i];
		i++;
	}
	while (i < width)
	{
		new_str[i] = ' ';
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

static void	my_freeall(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static int	store_map(t_cub3d *cub3d, t_list *map_line)
{
	size_t	i;

	cub3d->level.map = ft_calloc((cub3d->level.map_height + 1), sizeof(char *));
	if (cub3d->level.map == NULL)
	{
		perror(RED "store_map:malloc" RESET);
		return (1);
	}
	i = 0;
	while (map_line != NULL)
	{
		cub3d->level.map[i] = sanitize_map_line(map_line->content,
				cub3d->level.map_width);
		i++;
		map_line = map_line->next;
	}
	if (search_player(cub3d) || cub3d->camera.x == 0)
	{
		dprintf(2, RED "Error\n"
			PURPLE "The map should have one player\n" RESET);
		my_freeall(cub3d->level.map);
		cub3d->level.map = NULL;
		return (1);
	}
	return (0);
}

static int	is_valid_line(char line[])
{
	if (*line == '\0')
		return (0);
	while (*line != '\0' && ft_strchr(MAP_CHARS, *line) != NULL)
		line++;
	return (*line == '\0');
}

int	parse_map(t_cub3d *cub3d, t_list *map_line)
{
	t_list	*node;
	size_t	line_length;

	node = map_line;
	while (node != NULL)
	{
		if (!is_valid_line(node->content))
		{
			dprintf(2, RED "Error\n"
				PURPLE "Map has illegal character(s)\n" RESET);
			return (1);
		}
		cub3d->level.map_height++;
		line_length = ft_strlen(node->content);
		if (line_length > (size_t)cub3d->level.map_width)
			cub3d->level.map_width = line_length;
		node = node->next;
	}
	return (store_map(cub3d, map_line));
}
