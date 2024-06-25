/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: autheven <autheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 13:30:35 by autheven          #+#    #+#             */
/*   Updated: 2024/06/22 18:40:02 by pnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "color.h"
#include "cub3d.h"
#include "mlx.h"

#define MAX_PARAMS	6

static char	*goto_next_non_empty_line(int fd)
{
	char	*line;
	char	*new_line;

	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			return (NULL);
		if (*line != '\n')
			break ;
		free(line);
	}
	new_line = ft_strchr(line, '\n');
	if (new_line != NULL)
		*new_line = '\0';
	return (line);
}

static int	load_params(t_cub3d *cub3d, int fd)
{
	char	*line;
	int		i;

	i = 0;
	while (i < MAX_PARAMS)
	{
		line = goto_next_non_empty_line(fd);
		if (line == NULL)
			return (1);
		if (parse_params(cub3d, line))
		{
			free(line);
			return (1);
		}
		free(line);
		i++;
	}
	return (!(i == MAX_PARAMS));
}

static int	load_map(t_list **head, int fd)
{
	char	*line;
	char	*new_line;
	t_list	*node;

	line = goto_next_non_empty_line(fd);
	while (line != NULL)
	{
		node = ft_lstnew(line);
		if (node == NULL)
		{
			perror(RED "load_map:ft_lstnew" RESET);
			ft_lstclear(head, &free);
			free(line);
			return (1);
		}
		ft_lstadd_back(head, node);
		line = get_next_line(fd);
		new_line = ft_strchr(line, '\n');
		if (new_line != NULL)
			*new_line = '\0';
	}
	return (0);
}

int	load_level(t_cub3d *cub3d, char *path)
{
	t_list		*map;
	int			res;
	int const	fd = open(path, O_RDONLY);

	if (fd < 0)
		return (1);
	if (load_params(cub3d, fd))
	{
		close(fd);
		return (1);
	}
	map = NULL;
	res = load_map(&map, fd);
	close(fd);
	if (res)
		return (1);
	if (parse_map(cub3d, map))
	{
		ft_lstclear(&map, &free);
		return (1);
	}
	ft_lstclear(&map, &free);
	print_level(cub3d);
	return (flood_fill_start(cub3d, cub3d->camera.x, cub3d->camera.y));
}
