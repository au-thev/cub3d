#include "game.h"
#include "engine.h"
#include "mlx.h"
#include <math.h>

static unsigned int	get_pixel_color(t_image image, int x, int y)
{
	int		color;

	color = *(unsigned int*)(image.data + (y%image.size[HEIGHT] * 
	image.size_line + x%image.size[WIDTH] * (image.bits_per_pixel / 8)) % 
	(image.size[WIDTH]*image.size[HEIGHT]*image.bits_per_pixel));
	return (color);
}

void render_ray(t_game *game, t_dda *dda, int ray, t_point ray_dir)
{
	double 			lineHeight;
	double 			drawStart;
	double 			drawEnd;
	double			i;
	int 			texID;
	double			wallX;
	int 			texX;
	double 			texStep;
	double 			texPos;
	unsigned int 	color;
	int 			texY;

	// printf("======================= \n");
	// printf("distance avant modif : %d \n", dda->distance);
	if (dda->side == 0)
		dda->distance = dda->side_dist.x - dda->delta_dist.x;
	else           
		dda->distance = dda->side_dist.y - dda->delta_dist.y;
	// printf("distance apres modif : %d \n", dda->distance);
	lineHeight = game->display.win.size[HEIGHT] / dda->distance;
	// printf("lineHeight : %d \n", lineHeight);
	drawStart = -lineHeight / 2 + game->display.win.size[HEIGHT] / 2;
	if(drawStart < 0)
		drawStart = 0;
	drawEnd = lineHeight / 2 + game->display.win.size[HEIGHT] / 2;
	if(drawEnd >= game->display.win.size[HEIGHT])
		drawEnd = game->display.win.size[HEIGHT] - 1;
	i = 0;
	// printf("drawStart : %d \n", drawStart);
	// printf("drawEnd : %d \n", drawEnd);
	while (i < drawStart)
		pixel_put(&game->display.win.buffer, ray, i++, 0x0a75ad);
	// while (i < drawEnd)
	// {
		//////////////////////////////////////////////////////
	texID = 0;
	if (dda->side == 0) 
		wallX = dda->start.y + dda->distance * ray_dir.y;
	else           
		wallX = dda->start.x + dda->distance * ray_dir.x;
	wallX -= floor((wallX));
	texX = (int)(wallX * (double)(game->display.level.textures[texID].image.size[WIDTH]));
	texStep = 1.0 * game->display.level.textures[texID].image.size[HEIGHT] / lineHeight;
	texPos = (drawStart  - game->display.win.size[HEIGHT] / 2 + lineHeight / 2) * texStep;

	// pixel_put(&game->display.win.buffer, ray, i, 0xFFFFFF);
	color = 0xFFFFFF;
	while (i < drawEnd)
	{
		texY = (int)texPos & ((int)game->display.level.textures[texID].image.size[HEIGHT] - 1);
		texPos += texStep;
		color = get_pixel_color(game->display.level.textures[texID].image, texX, texY);
		pixel_put(&game->display.win.buffer, ray, i, color);

		//0x00008B
		i++;
	}
		//////////////////////////////////////////////////////
	while (i < game->display.win.size[HEIGHT])
		//0x00ffff
		pixel_put(&game->display.win.buffer, ray, i++, 0x794044);
		// mlx_pixel_put(game->display.ptr, game->display.win.ptr, ray, i++, 0x0);
	// i = drawStart;
	// while (i < drawEnd)
	// {
	// 	mlx_pixel_put(game->display.ptr, game->display.win.ptr, ray, i, 0xFFFFFF);
	// 	i++;
	// }
}