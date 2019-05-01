/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndombre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/11 15:19:04 by ndombre           #+#    #+#             */
/*   Updated: 2016/11/08 13:45:46 by ndombre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char const *str, char const *to_find)
{
	int i;

	while (1)
	{
		if (*to_find == '\0')
			return ((char*)str);
		if (*str == '\0')
			return (NULL);
		i = 0;
		while (str[i] != '\0')
		{
			if (to_find[i] == '\0')
				return ((char*)str);
			if (str[i] != to_find[i])
				break ;
			i++;
			if (to_find[i] == '\0')
				return ((char*)str);
		}
		str++;
	}
}
