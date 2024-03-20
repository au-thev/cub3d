/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coltcivers <coltcivers@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 08:46:36 by antheven          #+#    #+#             */
/*   Updated: 2024/03/20 00:57:45 by coltcivers       ###   ########.fr       */
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
