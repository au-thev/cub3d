/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fit_level.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 10:35:57 by antheven          #+#    #+#             */
/*   Updated: 2023/12/19 22:53:37 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "level.h"
#include <stdio.h>

void	fit_level(t_lvl *level)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (i < level->map_length - 1)
	{
		if (ft_strlen(level->map[i]) != (size_t)level->map_width)
		{
			line = ft_calloc(level->map_width + 1, sizeof(char));
			ft_memmove(line, level->map[i], ft_strlen(level->map[i]));
			j = ft_strlen(level->map[i]) - 1;
			while (j < level->map_width - 1)
				line[j++] = 'X';
			line[j++] = 0;
			free(level->map[i]);
			level->map[i] = line;
		}
		i++;
	}
}
