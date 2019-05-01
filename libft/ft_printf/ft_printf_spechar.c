/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_spechar.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndombre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 16:08:53 by ndombre           #+#    #+#             */
/*   Updated: 2016/11/22 16:13:24 by ndombre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

char	*ft_printf_spechar(char *src)
{
	char	*ret;
	int		i;

	ret = ft_strdup(src);
	if (ret == NULL)
		return (NULL);
	i = 0;
	while (ret[i] != '\0')
	{
		if (ret[i] > '~' || ret[i] < ' ')
			ret[i] = '.';
		i++;
	}
	return (ret);
}
