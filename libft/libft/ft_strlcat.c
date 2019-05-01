/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndombre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/12 11:15:22 by ndombre           #+#    #+#             */
/*   Updated: 2016/11/07 11:51:35 by ndombre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, char const *src, size_t size)
{
	size_t i;
	size_t j;
	size_t makelen;

	i = 0;
	j = 0;
	makelen = ft_strlen(dest) + ft_strlen(src);
	while (dest[i] != '\0' && i < size)
		i++;
	if (!(i < size))
		return (i + ft_strlen(src));
	while (src[j] != '\0')
	{
		if (i >= size - 1)
		{
			dest[i] = '\0';
			return (makelen);
		}
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (makelen);
}
