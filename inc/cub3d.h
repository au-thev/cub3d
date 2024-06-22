/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: autheven <autheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 19:57:07 by autheven          #+#    #+#             */
/*   Updated: 2024/06/22 18:54:20 by pnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "libft.h"

# define MOVE_RATIO	0.1

typedef struct s_cub3d	t_cub3d;
typedef struct s_draw	t_draw;

enum e_texture
{
	NO,
	SO,
	EA,
	WE
};

enum e_xy
{
	X,
	Y
};

struct s_cub3d
{
	struct s_mlx
	{
		void		*ptr;
		void		*win;
		struct s_buffer
		{
			void	*ptr;
			char	*data;
			int		bpp;
			int		sl;
			int		endian;
		}			buffer;
	}				mlx;
	char			keyboard[65535];
	struct s_camera
	{
		double		x;
		double		y;
		int			yaw;
	}				camera;
	struct s_level
	{
		struct s_textures
		{
			void	*ptr;
			char	*data;
			int		bpp;
			int		sl;
			int		endian;
			int		size[2];
			int		loaded;
		}			texture[4];
		int			color[2];
		int			color_load[2];
		char		**map;
		int			map_width;
		int			map_height;
	}				level;
	struct s_dda
	{
		int			current_x;
		double		camera_x;
		double		rot_rad;
		double		ray_dir[2];
		double		dir[2];
		double		plane[2];
		double		side_dist[2];
		double		delta_dist[2];
		double		step[2];
		double		curr_pos[2];
		int			side;
		double		wall_dist;
	}				dda;
};

struct s_draw
{
	int				start;
	int				end;
	int				tex_side;
	int				tex[2];
	double			tex_pos;
	int				color;
	double			step;
	double			wall_x;
	int				line_height;
};

void			put_pixel(t_cub3d *cub3d, int x, int y, int color);
unsigned int	get_pixel(t_cub3d *cub3d, int x, int y, char facing);
void			vert_line(t_cub3d *cub3d, int x, int start_end[2], int color);

int				key_press(int keycode, void *param);
int				key_release(int keycode, void *param);
int				keys_check(t_cub3d *cub3d);
void			move(t_cub3d *cub3d, char direction);

int				do_raycast(t_cub3d *cub3d);

int				load_level(t_cub3d *cub3d, char *path);
int				flood_fill_start(t_cub3d *cub3d, int x, int y);
int				parse_map(t_cub3d *cub3d, t_list *map_line);
int				decode_rgb_str(char *s);
int				parse_params(t_cub3d *cub3d, char *line);
int				search_player(t_cub3d *cub3d);
int				preload_dda_vars(t_cub3d *cub3d);
int				get_distance(t_cub3d *cub3d);

void			print_level(t_cub3d *cub3d);

void			free_game(t_cub3d *cub3d);

#endif
