/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: autheven <autheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 12:19:02 by autheven          #+#    #+#             */
/*   Updated: 2024/06/21 19:44:48 by pnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "mlx.h"

int	key_press(int keycode, void *param)
{
	t_cub3d	*cub3d;

	cub3d = param;
	cub3d->keyboard[keycode] = 1;
	return (0);
}

int	key_release(int keycode, void *param)
{
	t_cub3d	*cub3d;

	cub3d = param;
	cub3d->keyboard[keycode] = 0;
	return (0);
}

int	keys_check(t_cub3d *cub3d)
{
	if (cub3d->keyboard[119])
		move(cub3d, 'f');
	if (cub3d->keyboard[97])
		move(cub3d, 'l');
	if (cub3d->keyboard[115])
		move(cub3d, 'b');
	if (cub3d->keyboard[100])
		move(cub3d, 'r');
	if (cub3d->keyboard[65361])
	{
		cub3d->camera.yaw = cub3d->camera.yaw - 1;
		if (cub3d->camera.yaw < 0)
			cub3d->camera.yaw += 360;
	}
	if (cub3d->keyboard[65363])
		cub3d->camera.yaw = (cub3d->camera.yaw + 1) % 360;
	if (cub3d->keyboard[65307])
		mlx_loop_end(cub3d->mlx.ptr);
	return (0);
}
