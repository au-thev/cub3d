/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: autheven <autheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 07:01:37 by autheven          #+#    #+#             */
/*   Updated: 2024/06/22 16:50:22 by pnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "cub3d.h"
#include "libft.h"
#include "mlx.h"

static int	loop(void *param)
{
	t_cub3d	*cub3d;

	cub3d = param;
	keys_check(cub3d);
	do_raycast(cub3d);
	mlx_put_image_to_window(cub3d->mlx.ptr, cub3d->mlx.win,
		cub3d->mlx.buffer.ptr, 0, 0);
	return (0);
}

static int	mlx_produce(t_cub3d *cub3d)
{
	cub3d->mlx.ptr = mlx_init();
	if (!cub3d->mlx.ptr)
		return (1);
	cub3d->mlx.win = mlx_new_window(cub3d->mlx.ptr, 800, 600, "Cub3D");
	if (!cub3d->mlx.win)
	{
		mlx_destroy_display(cub3d->mlx.ptr);
		free(cub3d->mlx.ptr);
		return (1);
	}
	cub3d->mlx.buffer.ptr = mlx_new_image(cub3d->mlx.ptr, 800, 600);
	if (!cub3d->mlx.buffer.ptr)
	{
		mlx_destroy_window(cub3d->mlx.ptr, cub3d->mlx.win);
		mlx_destroy_display(cub3d->mlx.ptr);
		free(cub3d->mlx.ptr);
		return (1);
	}
	return (0);
}

static int	mlx_start(t_cub3d *cub3d)
{
	int	i;

	if (mlx_produce(cub3d))
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

static int	is_valid_filename(char const path[])
{
	char const	*extension = ft_strrchr(path, '.');

	if (extension == NULL)
		return (0);
	return (ft_strncmp(extension, ".cub", 5) == 0);
}

int	main(int argc, char **argv)
{
	t_cub3d	cub3d;
	int		i;

	if (argc != 2)
	{
		ft_putstr_fd("Usage : ./cub3d <filename>\n", STDERR_FILENO);
		return (1);
	}
	ft_bzero(&cub3d, sizeof(cub3d));
	if (mlx_start(&cub3d))
	{
		ft_putstr_fd("Failed to initialize mlx!\n", STDERR_FILENO);
		return (1);
	}
	i = 5;
	while (i-- > 0)
		cub3d.level.texture[i].loaded = 0;
	cub3d.level.map = 0;
	if (is_valid_filename(argv[1]) && !load_level(&cub3d, argv[1]))
		mlx_loop(cub3d.mlx.ptr);
	free_game(&cub3d);
}
