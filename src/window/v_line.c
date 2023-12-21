/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_line.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 08:52:28 by antheven          #+#    #+#             */
/*   Updated: 2023/12/21 09:10:35 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "images.h"

void	v_line(t_image *img, int x, t_line bounds, int color)
{
	while (bounds.end-- > bounds.start)
		pixel_put(img, x, bounds.end, color);
}
