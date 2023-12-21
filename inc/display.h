/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 19:26:57 by antheven          #+#    #+#             */
/*   Updated: 2023/12/21 09:17:01 by antheven         ###   ########.fr       */
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
	void	*ptr;
	int		size[2];
	t_image	buffer;
};

struct s_display
{
	void	*ptr;
	t_win	win;
	t_lvl	level;
};

int		feed_level(t_display *display, char *level_file);
int		load_textures(t_display *display);
void	unload_level(t_display *display);
void	unload_game(t_display *display);
int		new_window(t_display *display);

#endif