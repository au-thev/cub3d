/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antheven <antheven@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 15:41:18 by antheven          #+#    #+#             */
/*   Updated: 2023/12/10 15:48:08 by antheven         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	i;

	if (n < 0)
	{
		i = -n;
		ft_putchar_fd('-', fd);
	}
	else
		i = n;
	if (i / 10)
		ft_putnbr_fd(i / 10, fd);
	ft_putchar_fd(i + '0', fd);
}

void	ft_putnbr(int n)
{
	ft_putnbr_fd(n, 1);
}
