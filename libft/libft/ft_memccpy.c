/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndombre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/11 14:14:43 by ndombre           #+#    #+#             */
/*   Updated: 2017/07/29 22:22:56 by ndombre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, void const *src, int c, size_t n)
{
	unsigned int i;

	i = 0;
	while (((unsigned char*)src)[i] != (unsigned char)c)
	{
		if (i >= n)
			return (NULL);
		((unsigned char*)dest)[i] = ((unsigned char*)src)[i];
		i++;
	}
	((unsigned char*)dest)[i] = ((unsigned char*)src)[i];
	return ((void*)((unsigned char*)dest + i + 1));
}
