#include "game.h"
#include "engine.h"
#include "mlx.h"

void render_ray(t_game *game, t_dda *dda, int ray)
{
	int lineHeight;
	int drawStart;
	int drawEnd;
	int	i;

	if (dda->side == 0)
		dda->distance = dda->side_dist.x - dda->delta_dist.x;
	else           
		dda->distance = dda->side_dist.y - dda->delta_dist.y;
	lineHeight = game->display.win.size[HEIGHT] / dda->distance;
	drawStart = -lineHeight / 2 + game->display.win.size[HEIGHT] / 2;
	if(drawStart < 0)
		drawStart = 0;
	drawEnd = lineHeight / 2 + game->display.win.size[HEIGHT] / 2;
	if(drawEnd >= game->display.win.size[HEIGHT])
		drawEnd = game->display.win.size[HEIGHT] - 1;
	i = 0;
	while (i < drawStart)
		pixel_put(&game->display.win.buffer, ray, i++, 0x0);
	// i = drawStart;
	while (i < drawEnd)
	{
		pixel_put(&game->display.win.buffer, ray, i, 0xFFFFFF);
		i++;
	}
	while (i < game->display.win.size[HEIGHT])
		pixel_put(&game->display.win.buffer, ray, i++, 0x0);
}