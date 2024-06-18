/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:18:41 by antheven          #+#    #+#             */
/*   Updated: 2023/12/11 15:08:08 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*tmp;
	char	*new;

	while (*s1)
	{
		if (!ft_strchr(set, *s1))
			break ;
		s1++;
	}
	new = ft_strdup(s1);
	tmp = new;
	while (*tmp)
		tmp++;
	tmp--;
	while (ft_strchr(set, *tmp))
		*tmp-- = 0;
	return (new);
}
