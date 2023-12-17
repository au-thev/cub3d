/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_level.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 14:14:47 by antheven          #+#    #+#             */
/*   Updated: 2023/12/17 09:54:00 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "level.h"
#include <stdio.h>

static char	get_map_char(char c)
{
	char	form[100];

	form['0'] = ' ';
	form['1'] = '#';
	form['2'] = '2';
	form['3'] = '3';
	form['N'] = '^';
	form['S'] = 'v';
	form['E'] = '>';
	form['W'] = '<';
	form[' '] = ' ';
	return (form[(int)c]);
}

void	print_level(t_lvl *level)
{
	char	**map;
	int		i;
	int		j;

	map = level->map;
	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		printf("[MAP] (line %02d) (%03ld), ", i, ft_strlen(map[i]));
		j = 0;
		while (map[i][j])
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
