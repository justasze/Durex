/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndombre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 11:42:06 by ndombre           #+#    #+#             */
/*   Updated: 2016/11/07 12:02:22 by ndombre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbr_fd(int nb, int fd)
{
	unsigned int nbu;

	if (nb < 0)
	{
		nbu = -nb;
		ft_putchar_fd('-', fd);
	}
	else
		nbu = nb;
	if (nbu == 0)
	{
		ft_putchar_fd('0', fd);
		return ;
	}
	if (nbu / 10 > 0)
		ft_putnbr_fd(nbu / 10, fd);
	ft_putchar_fd('0' + (nbu % 10), fd);
}
