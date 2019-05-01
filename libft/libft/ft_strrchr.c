/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndombre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/20 21:33:36 by ndombre           #+#    #+#             */
/*   Updated: 2016/11/04 15:29:41 by ndombre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(char const *str, int c)
{
	char *ret;

	ret = NULL;
	while (1)
	{
		if (*str == c)
			ret = (char*)str;
		if (*str == '\0')
			break ;
		str++;
	}
	return (ret);
}
