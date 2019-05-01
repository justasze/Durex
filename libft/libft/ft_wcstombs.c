/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcstombs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndombre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 18:12:46 by ndombre           #+#    #+#             */
/*   Updated: 2016/11/23 14:42:06 by ndombre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_wcstombs(char *dst, const wchar_t *src, size_t len)
{
	unsigned char	reeltab[4];
	size_t			i;
	int				nbcopy;

	i = 0;
	while (*src)
	{
		nbcopy = ft_wtoc(reeltab, *src);
		if (nbcopy + i > len)
			return (i);
		ft_memcpy(dst + i, reeltab, nbcopy);
		i += nbcopy;
		src++;
	}
	dst[i] = '\0';
	return (i);
}
