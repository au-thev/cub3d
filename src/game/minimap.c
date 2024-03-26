/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coltcivers <coltcivers@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 00:42:24 by antheven          #+#    #+#             */
/*   Updated: 2024/03/26 12:36:40 by coltcivers       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "game.h"
#include "images.h"
#include "utils.h"
#include "engine.h"
 
// void    draw_minimap(t_game *game)
// {
// 	int		x;
// 	int		y;
// 	int		i;
// 	int		ratio;

// 	ratio = 10;
// 	y = game->display.level.map_length;
// 	while (y-- > 0)
// 	{
// 		x = ft_strlen(game->display.level.map[y]);
// 		while (x-- > 0)
// 		{
// 			i = ratio;
// 			if (game->display.level.map[y])
// 			{
// 				while (i-->0)
// 					if (game->display.level.map[y][x] == '0')
// 						v_line(&game->display.win.buffer, x * ratio + i, (t_line) {y * ratio, y * ratio + ratio}, 0xffffff);
// 					else
// 						v_line(&game->display.win.buffer, x * ratio + i, (t_line) {y * ratio, y * ratio + ratio}, 0xff00ff);
// 			}
// 		}
// 	}
// 	draw_circle(&game->display.win.buffer, (t_point){game->player.location.y * ratio, game->player.location.x * ratio}, 5, 0xFF00FF);
// }

// void		draw_minimap(t_game *game)
// {
// 	t_entity	player;
// 	int		player_rot;
 
// 	player = game->player;
// 	player_rot = player.direction;
// 	t_point	step;
// 	t_point pstep;

// 	step.x = cos(degtorad(player_rot));
// 	step.y = sin(degtorad(player_rot));
// 	pstep.x = sin(degtorad(player_rot)) * (60 / 100);
// 	pstep.y = -cos(degtorad(player_rot)) * (60 / 100);
// 	t_dda dd;
// 	int		x = 0;
// 	while (x < game->display.win.size[WIDTH])
// 	{
// 		t_point	ray_dir;
// 		t_point	camera;

// 		camera.x = 2 * x / game->display.win.size.x - 1;
// 		ray_dir.x = step.x + pstep.x * camera.x;
// 		ray_dir.y = step.y + pstep.y * camera.x;
// 		dd = dda(game, game->world[(int)game->entity[0].world.id].grid, game->world[(int)game->entity[0].world.id].size, player.position, vec_mul(ray_dir, 1));
// 		for (int s = 0; s <= (int)(dd.distance * game->minimap.ratio); s++) // DESSINE LA DIRECTION DE LA CAMERA EN BLEU
// 			buffer_write(game, player.location.x*game->minimap.ratio + s * ray_dir.x, player.location.y*game->minimap.ratio + s * ray_dir.y, (dd.facing+1)*0x004400);
// 		//draw_line(game, vec_mul(dd.start, game->minimap.ratio), vec_add(vec_mul(dd.end, game->minimap.ratio), 1), (dd.side + 1) * 0x004400);
// 		x++;
// 	}
// 	for (int y = 0; y < player.world.obj->size.y; y++)
// 		for (int x = 0; x < player.world.obj->size.x; x++)
// 			for (int s = 0; s < game->minimap.ratio; s++)
// 				if (player.world.obj->grid[y][x] > 0)
// 					vert_line(game, x*game->minimap.ratio+s, y*game->minimap.ratio, y*game->minimap.ratio+game->minimap.ratio, player.world.obj->grid[y][x]*0x111111);
//	for (int s = 0; s < game->minimap.ratio * 2; s++) // DESSINE LA DIRECTION DE LA CAMERA EN BLEU
//		buffer_write(game, player.location.x*game->minimap.ratio + s * step.x, player.location.y*game->minimap.ratio + s * step.y, 0x0000FF);
//	for (int s = -game->minimap.ratio*player_rot.fov/100+1; s < game->minimap.ratio*player_rot.fov/100; s++) // DESSINE LA ZONE RENDUE DE L'ECRAN
//		buffer_write(game, player.location.x*game->minimap.ratio + game->minimap.ratio * player_rot.fov/100 * step.x + s * pstep.x, player.location.y*game->minimap.ratio + game->minimap.ratio * player_rot.fov/100 * step.y + s * pstep.y, 0xFF0000);
//	for (int s = -game->minimap.ratio; s <= game->minimap.ratio; s++) // DESSINE LE PLAN DE LA CAAMERA, EN VIOLET
//		buffer_write(game, player.location.x*game->minimap.ratio+ s * pstep.x, player.location.y*game->minimap.ratio + s * pstep.y, 0xEE00FF);
/*	for (double yaw = player_rot.yaw-player_rot.fov/2; yaw < player_rot.yaw+player_rot.fov/2; yaw+=0.1)
	{ // DESSINE LE CHAMP DE VISION `VIRTUEL` EN VERT
	step.x = cos(yaw * 0.017453);
	step.y = sin(yaw * 0.017453);
		dd = dda(game, game->world[game->entity[0].world.id].grid, game->world[game->entity[0].world.id].size, player_loc, step);
		for (int s = 0; s < dd.distance*game->minimap.ratio; s++)
			buffer_write(game, player_loc.x*game->minimap.ratio + s * step.x, player_loc.y*game->minimap.ratio + s * step.y, 0x004400*(1+dd.side));
		//draw_line(game, dd.start, dd.end, 0xFF0000);
	}*/
	//for (int s = -map_size/2; s <= map_size/2; s++)
	//	vert_line(game, player_loc.x*map_size+s, player_loc.y*map_size-map_size/2, player_loc.y*map_size+map_size/2, 0x00FFFF);
	//for (int s = 0; s < map_size/3; s++)
	//	vert_line(game, player_loc.x*map_size+s + player_loc.x*map_size/3, player_loc.y*map_size + player_loc.y*map_size/3, player_loc.y*map_size+map_size/3 + player_loc.y*map_size/3, 0x00FFFF);
//	draw_line(game, ray_start, ray_end, 0xABCDEF);
// 	return (1);
// }