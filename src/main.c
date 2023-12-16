/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 08:19:10 by antheven          #+#    #+#             */
/*   Updated: 2023/12/14 14:30:52 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "level.h"

int	main(int argc, char **argv)
{
	t_lvl	level;
	// verif si fichier .cub donné
	if (argc == 1)
		return (1);

	load_level(&level, argv[1]);
	// parser chaque ligne du fichier
	// pour la map, verifier son contour (=1)
}