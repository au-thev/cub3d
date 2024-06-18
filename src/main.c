/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: autheven <autheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 07:01:37 by autheven          #+#    #+#             */
/*   Updated: 2024/06/17 17:58:28 by autheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>
#include "cub3d.h"
#include "mlx.h"

int	loop(void *param)
{
	t_cub3d	*cub3d;
	int		x;
	int		ray;

	x = 800;
	cub3d = param;
	keys_check(cub3d);
	do_raycast(cub3d);
	mlx_put_image_to_window(cub3d->mlx.ptr, cub3d->mlx.win,
		cub3d->mlx.buffer.ptr, 0, 0);
	return (0);
}

int	mlx_start(t_cub3d *cub3d)
{
	int	i;

	cub3d->mlx.ptr = mlx_init();
	if (!cub3d->mlx.ptr)
		return (1);
	cub3d->mlx.win = mlx_new_window(cub3d->mlx.ptr, 800, 600, "Cub3D");
	if (!cub3d->mlx.win)
		return (1);
	cub3d->mlx.buffer.ptr = mlx_new_image(cub3d->mlx.ptr, 800, 600);
	if (!cub3d->mlx.buffer.ptr)
		return (1);
	cub3d->mlx.buffer.data = mlx_get_data_addr(cub3d->mlx.buffer.ptr,
			&cub3d->mlx.buffer.bpp, &cub3d->mlx.buffer.sl,
			&cub3d->mlx.buffer.endian);
	mlx_hook(cub3d->mlx.win, 2, (1L << 0), key_press, cub3d);
	mlx_hook(cub3d->mlx.win, 3, (1L << 1), key_release, cub3d);
	mlx_hook(cub3d->mlx.win, 17, 1L << 0, mlx_loop_end, cub3d->mlx.ptr);
	mlx_loop_hook(cub3d->mlx.ptr, loop, cub3d);
	i = 65535;
	while (i-- > 0)
		cub3d->keyboard[i] = 0;
	cub3d->camera.x = 0;
	cub3d->camera.y = 0;
	cub3d->camera.yaw = 0;
	return (0);
}

int	main(int argc, char **argv)
{
	t_cub3d	cub3d;
	int		i;

	if (argc != 2)
		return (1);
	if (mlx_start(&cub3d))
		return (1);
	i = 5;
	while (i-- > 0)
		cub3d.level.texture[i].loaded = 0;
	cub3d.level.map = 0;
	if (!load_level(&cub3d, argv[1]))
		if (!check_params(&cub3d))
			mlx_loop(cub3d.mlx.ptr);
	free_game(&cub3d);
}
