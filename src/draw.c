/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: autheven <autheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 17:07:18 by autheven          #+#    #+#             */
/*   Updated: 2024/06/22 18:29:54 by pnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

void	put_pixel(t_cub3d *cub3d, int x, int y, int color)
{
	char	*dst;

	dst = cub3d->mlx.buffer.data + (y * cub3d->mlx.buffer.sl + x
			* (cub3d->mlx.buffer.bpp / 8));
	if (x >= 0 && x < 800 && y >= 0 && y < 600)
		*(unsigned int *)dst = color;
}

unsigned int	get_pixel(t_cub3d *cub3d, int x, int y, char facing)
{
	char	*dst;

	dst = cub3d->level.texture[(int)facing].data
		+ (y * cub3d->level.texture[(int)facing].sl + x
			* (cub3d->level.texture[(int)facing].bpp / 8));
	return (*(unsigned int *)dst);
}

void	vert_line(t_cub3d *cub3d, int x, int start_end[2], int color)
{
	while (start_end[1]-- > start_end[0])
		put_pixel(cub3d, x, start_end[1], color);
}
