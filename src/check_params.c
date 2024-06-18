/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: autheven <autheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:37:08 by autheven          #+#    #+#             */
/*   Updated: 2024/06/17 19:02:13 by autheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

int	check_params(t_cub3d *cub3d)
{
	int	i;
	int	res;

	i = 4;
	res = 0;
	while (i-- > 0)
		if (!cub3d->level.texture[i].loaded)
			res = 1;
	if (cub3d->level.color_load[0] != 1)
		res = 1;
	if (cub3d->level.color_load[1] != 1)
		res = 1;
	if (res)
		dprintf(2, "\033[0;31mError\n\033[0;35mMissing params\n\033[0m");
	return (res);
}
