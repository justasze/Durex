/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndombre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/13 11:20:03 by ndombre           #+#    #+#             */
/*   Updated: 2016/11/10 12:37:35 by ndombre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dest, void const *src, size_t n)
{
	if (dest < src)
	{
		ft_memcpy(dest, src, n);
		return (dest);
	}
	while (n-- > 0)
		((unsigned char*)dest)[n] = ((unsigned char*)src)[n];
	return (dest);
}
