/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 08:46:36 by antheven          #+#    #+#             */
/*   Updated: 2024/01/01 08:51:23 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITY_H
# define ENTITY_H

# include "level.h"

typedef struct s_entity	t_player;
typedef struct s_entity	t_entity;

struct s_entity
{
	t_point	location;
	double	direction;
};


#endif
