/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 09:47:19 by antheven          #+#    #+#             */
/*   Updated: 2023/12/14 10:43:10 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGES_H
# define IMAGES_H

typedef	struct s_image	t_image;
typedef	struct s_color	t_color;
typedef	enum e_img_type	t_img_type;

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


struct s_image
{
	t_img_type	type;
	char		color[4];
	void		*ptr;
	char		*data;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
};

#endif