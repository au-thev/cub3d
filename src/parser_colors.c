/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_colors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnguyen- <pnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 14:53:29 by pnguyen-          #+#    #+#             */
/*   Updated: 2024/06/22 18:36:42 by pnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdio.h>
#include "libft.h"
#include "color.h"

#define NOT_LAST_COLOR	0
#define LAST_COLOR		1

#define COLOR_MAX		"255"
#define COLOR_MAX_LEN	3

static int	is_valid_color(char *s)
{
	size_t		len;
	int			status;

	len = 0;
	while (ft_isdigit(s[len]))
		len++;
	if (len == COLOR_MAX_LEN)
		status = ft_strncmp(s, COLOR_MAX, COLOR_MAX_LEN) <= 0;
	else
		status = len < COLOR_MAX_LEN;
	return (status);
}

static int	get_color(char *s, int is_last_color)
{
	char	*start;

	while (*s == ' ')
		s++;
	if (!ft_isdigit(*s))
		return (-1);
	start = s;
	while (ft_isdigit(*s))
		s++;
	while (*s == ' ')
		s++;
	if ((!is_last_color && *s != ',')
		|| (is_last_color && *s != '\0')
		|| !is_valid_color(start))
		return (-1);
	return (ft_atoi(start) & 0xFF);
}

int	decode_rgb_str(char *s)
{
	int	red;
	int	green;
	int	blue;

	red = get_color(s, NOT_LAST_COLOR);
	if (red == -1)
		return (-1);
	s = ft_strchr(s, ',') + 1;
	green = get_color(s, NOT_LAST_COLOR);
	if (green == -1)
		return (-1);
	s = ft_strchr(s, ',') + 1;
	blue = get_color(s, LAST_COLOR);
	if (blue == -1)
		return (-1);
	return (0 << 24 | red << 16 | green << 8 | blue);
}
