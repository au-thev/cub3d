/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_circle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 15:21:10 by antheven          #+#    #+#             */
/*   Updated: 2024/03/21 18:57:03 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "utils.h"
#include <math.h>

void	draw_circle(t_image *image, t_point pos, int r, int color)
{
	int	degree;

	degree = 360;
	while (degree-- > 0)
	pixel_put(image, pos.x + cos(deg_to_rad(degree)) * r, pos.y + sin(deg_to_rad(degree)) * r, color);
}