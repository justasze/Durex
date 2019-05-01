/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndombre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/20 21:33:36 by ndombre           #+#    #+#             */
/*   Updated: 2016/11/10 10:27:20 by ndombre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *str)
{
	char	*ret;
	size_t	i;

	while (ft_isspace(*str))
		str++;
	ret = ft_strdup(str);
	if (ret == NULL)
		return (NULL);
	i = ft_strlen(ret) - 1;
	while (ft_isspace(ret[i]))
	{
		ret[i] = '\0';
		if (i == 0)
			break ;
		i--;
	}
	return (ret);
}
