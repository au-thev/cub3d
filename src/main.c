/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 08:19:10 by antheven          #+#    #+#             */
/*   Updated: 2023/12/17 10:39:23 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "level.h"
#include "display.h"
#include "mlx.h"

int	main(int argc, char **argv)
{
	t_display	display;
	if (argc == 1)
		return (1);
	display.ptr = mlx_init();
	load_level(&display.level, argv[1]);
	print_level(&display.level);
	load_textures(&display);
	// parser chaque ligne du fichier
	// pour la map, verifier son contour (=1)
}