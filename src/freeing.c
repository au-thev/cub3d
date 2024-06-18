/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: autheven <autheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 17:33:34 by autheven          #+#    #+#             */
/*   Updated: 2024/06/17 19:03:14 by autheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "cub3d.h"
#include "mlx.h"

int	free_game(t_cub3d *cub3d)
{
	int		i;
	char	**ptr;

	printf("\033[0;35mFreeing game vars\033[0m\n");
	mlx_destroy_image(cub3d->mlx.ptr, cub3d->mlx.buffer.ptr);
	mlx_destroy_window(cub3d->mlx.ptr, cub3d->mlx.win);
	i = 5;
	while (i-- > 0)
	{
		if (cub3d->level.texture[i].loaded)
			mlx_destroy_image(cub3d->mlx.ptr, cub3d->level.texture[i].ptr);
	}
	mlx_destroy_display(cub3d->mlx.ptr);
	free(cub3d->mlx.ptr);
	ptr = cub3d->level.map;
	if (ptr)
		while (*ptr)
			free(*ptr++);
	free(cub3d->level.map);
}
