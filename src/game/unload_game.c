/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unload_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 19:29:38 by antheven          #+#    #+#             */
/*   Updated: 2023/12/20 08:36:14 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"
#include "mlx.h"
#include <stdlib.h>

void	unload_game(t_display *display)
{
	if (display->level.loaded)
		unload_level(display);
	mlx_destroy_display(display->ptr);
	free(display->ptr);
}
