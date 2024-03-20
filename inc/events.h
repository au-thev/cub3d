/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coltcivers <coltcivers@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 07:18:07 by antheven          #+#    #+#             */
/*   Updated: 2024/03/20 01:00:03 by coltcivers       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

typedef enum e_event_type	t_evt_type;
typedef struct s_events		t_events;
typedef struct s_game		t_game;

enum e_event_type
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

struct s_events
{
	int		keys[65535];
	int		mouse_btn;
	t_point	click_pos;
	t_point	move_pos;
};

int	kb_init(t_game *game);
int	kb_down(int keycode, t_game *game);
int	kb_up(int keycode, t_game *game);
int	mouse_init(t_game *game);
int	mouse_down(int button, int x, int y, t_game *game);
int	mouse_up(int button, int x, int y, t_game *game);
int	mouse_move(int x, int y, t_game *game);
int	register_events(t_game *game);

#endif