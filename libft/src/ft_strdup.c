/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 02:54:06 by antheven          #+#    #+#             */
/*   Updated: 2023/12/07 13:53:14 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*copy;
	size_t	s_len;

	if (!s)
		return (0);
	s_len = ft_strlen(s);
	copy = malloc(s_len + 1);
	if (!copy)
		return (0);
	ft_memmove(copy, s, s_len);
	*(copy + s_len) = 0;
	return (copy);
}
