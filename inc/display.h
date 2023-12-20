/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 19:26:57 by antheven          #+#    #+#             */
/*   Updated: 2023/12/20 08:31:58 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_H
# define DISPLAY_H

# include "level.h"

typedef struct s_display	t_display;

struct s_display
{
	void	*ptr;
	void	*win_ptr;
	t_lvl	level;
};

int		feed_level(t_display *display, char *level_file);
int		load_textures(t_display *display);
void	unload_level(t_display *display);
void	unload_game(t_display *display);

#endif