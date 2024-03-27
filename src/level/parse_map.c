/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 21:39:59 by antheven          #+#    #+#             */
/*   Updated: 2024/03/21 15:14:27 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "level.h"
#include "libft.h"

// static void remap(t_lvl *level)
// {
// 	int	i;
// 	cha

// 	i = level->map_length;

// }

int	parse_map(t_lvl *level, char *line)
{
	char	*line_addr;
	int		i;

	line_addr = line;
	if (ft_isspace(*line))
		while (ft_isspace(*line))
			*line++ = 'X';
	if (!ft_isdigit(*line))
		return (1);
	i = 0;
	line = line_addr;
	level->map = ft_calloc(i + 1, sizeof(line));
	level->map[i++] = line;
	while (!map_add(level, i++, ft_readline(level->fd)))
		;
	map_add(level, i, 0);
	level->map_length = i;
	// remap(level);
	return (2);
}
