/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndombre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/11 15:19:04 by ndombre           #+#    #+#             */
/*   Updated: 2016/11/08 13:46:05 by ndombre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char const *str, char const *to_find, size_t n)
{
	size_t i;

	while (1)
	{
		if (*to_find == '\0')
			return ((char*)str);
		if (*str == '\0' || n == 0)
			return (NULL);
		i = 0;
		while (str[i] != '\0')
		{
			if (to_find[i] == '\0')
				return ((char*)str);
			if (i >= n)
				return (NULL);
			if (str[i] != to_find[i])
				break ;
			i++;
			if (to_find[i] == '\0')
				return ((char*)str);
		}
		str++;
		n--;
	}
}
