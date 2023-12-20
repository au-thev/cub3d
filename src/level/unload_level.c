/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unload_level.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 15:31:31 by antheven          #+#    #+#             */
/*   Updated: 2023/12/19 21:29:56 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include "mlx.h"
#include <stdlib.h>
#include <stdio.h>

void	unload_level(t_display *display)
{
	int	i;

	i = TEX_NB;
	while (i-- > 0)
	{
		printf("Unloading %s\n", display->level.textures[i].prefix);
		if (display->level.textures[i].image.type == IMAGE)
			mlx_destroy_image(display->ptr,
				display->level.textures[i].image.ptr);
		free(display->level.textures[i].prefix);
	}
	i = display->level.map_length;
	while (i-- > 0)
	{
		free(display->level.map[i]);
	}
	free(display->level.map);
}
