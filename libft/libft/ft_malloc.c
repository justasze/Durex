/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmenzagh <hmenzagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 10:09:18 by ndombre           #+#    #+#             */
/*   Updated: 2019/02/27 23:25:39 by ndombre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void		*ft_malloc(size_t s)
{
	void	*ptr;

	ptr = malloc(s);
	if (ptr != NULL)
		ft_memset(ptr, '~', s);
	return (ptr);
}
