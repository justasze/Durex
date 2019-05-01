/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wtoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndombre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 18:22:52 by ndombre           #+#    #+#             */
/*   Updated: 2016/11/20 14:43:51 by ndombre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_wtoc(unsigned char reeltab[4], const wchar_t c)
{
	if (c < 128)
	{
		reeltab[0] = c;
		return (1);
	}
	if (c < 2048)
	{
		reeltab[0] = (c >> 6) + 192;
		reeltab[1] = (63 & c) + 128;
		return (2);
	}
	if (c < 65536)
	{
		reeltab[0] = (15 & c >> 12) + 224;
		reeltab[1] = (63 & (c >> 6)) + 128;
		reeltab[2] = (63 & c) + 128;
		return (3);
	}
	if (c >= 2097152)
		return (-1);
	reeltab[0] = (7 & (c >> 18)) + 240;
	reeltab[1] = (63 & (c >> 12)) + 128;
	reeltab[2] = (63 & (c >> 6)) + 128;
	reeltab[3] = (63 & c) + 128;
	return (4);
}
