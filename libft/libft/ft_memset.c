/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndombre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/11 23:24:32 by ndombre           #+#    #+#             */
/*   Updated: 2016/07/11 23:33:34 by ndombre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memset(void *ptr, int value, size_t num)
{
	void *ptrret;

	ptrret = ptr;
	while (num > 0)
	{
		*((unsigned char*)ptr) = (unsigned char)value;
		++ptr;
		--num;
	}
	return (ptrret);
}
