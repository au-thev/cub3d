/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 08:50:50 by antheven          #+#    #+#             */
/*   Updated: 2023/12/21 09:22:20 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "images.h"

void	pixel_put(t_image *data, int x, int y, int color)
{
	char	*dst;

	dst = data->data + (y * data->size_line + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
