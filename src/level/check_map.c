/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 03:38:41 by antheven          #+#    #+#             */
/*   Updated: 2023/12/20 08:40:59 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "level.h"
#include "libft.h"
#include <stdio.h>

int	check_map(t_lvl *level)
{
	int	y;

	y = 0;
	while (y < level->map_length)
	{
		if (ft_strchr(level->map[y], '*'))
		{
			printf("Map not enclosed at line %d\n", y);
			return (1);
		}
		y++;
	}
	return (0);
}
