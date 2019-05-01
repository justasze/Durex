/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndombre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 10:29:47 by ndombre           #+#    #+#             */
/*   Updated: 2016/11/10 10:30:51 by ndombre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memdup(void const *src, size_t n)
{
	unsigned char *new;

	new = ft_malloc(sizeof(unsigned char) * n);
	if (new == NULL)
		return (NULL);
	ft_memcpy(new, src, n);
	return (new);
}
