/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 09:47:19 by antheven          #+#    #+#             */
/*   Updated: 2023/12/19 21:46:01 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGES_H
# define IMAGES_H

typedef struct s_image	t_image;
typedef enum e_color	t_color;
typedef enum e_img_type	t_img_type;
typedef enum e_size		t_size;

enum e_img_type
{
	IMAGE,
	COLOR
};

enum e_color
{
	A,
	R,
	G,
	B
};

enum e_size
{
	WIDTH,
	HEIGHT
};

struct s_image
{
	t_img_type	type;
	int			color[4];
	int			size[2];
	void		*ptr;
	char		*data;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
};

#endif