/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 08:37:11 by antheven          #+#    #+#             */
/*   Updated: 2023/12/21 09:20:45 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include "mlx.h"

int	new_window(t_display *display)
{
	int	x;

	display->win.size[WIDTH] = 800;
	display->win.size[HEIGHT] = 600;
	x = display->win.size[WIDTH];
	display->win.ptr = mlx_new_window(display->ptr,
			display->win.size[WIDTH],
			display->win.size[HEIGHT],
			"cub3d");
	display->win.buffer.type = IMAGE;
	display->win.buffer.ptr = mlx_new_image(display->ptr,
			display->win.size[WIDTH],
			display->win.size[HEIGHT]);
	display->win.buffer.data = mlx_get_data_addr(display->win.buffer.ptr,
			&display->win.buffer.bits_per_pixel,
			&display->win.buffer.size_line,
			&display->win.buffer.endian);
	while (x-- > 0)
		v_line(&display->win.buffer, x,
			(t_line){0, display->win.size[HEIGHT]}, 0xFFFFFF);
	mlx_put_image_to_window(display->ptr, display->win.ptr,
		display->win.buffer.ptr, 0, 0);
	return (0);
}
