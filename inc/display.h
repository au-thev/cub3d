/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coltcivers <coltcivers@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 19:26:57 by antheven          #+#    #+#             */
/*   Updated: 2024/03/20 00:58:11 by coltcivers       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H

# include "level.h"
# include "images.h"

typedef struct s_display	t_display;
typedef struct s_win		t_win;

struct s_win
{
	void		*ptr;
	double		size[2];
	t_image		buffer;

};

struct s_display
{
	void	*ptr;
	t_win	win;
	t_lvl	level;
	double	fov;
};

int		feed_level(t_display *display, char *level_file);
int		load_textures(t_display *display);
void	unload_level(t_display *display);
void	unload_game(t_display *display);
int		new_window(t_display *display);

#endif