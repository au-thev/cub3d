/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 08:19:10 by antheven          #+#    #+#             */
/*   Updated: 2023/12/20 08:44:25 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "level.h"
#include "display.h"
#include "mlx.h"

int	main(int argc, char **argv)
{
	t_display	display;

	if (argc != 2)
		return (1);
	display.ptr = mlx_init();
	if (feed_level(&display, argv[1]))
		unload_game(&display);
}
