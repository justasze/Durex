/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndombre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/13 11:20:03 by ndombre           #+#    #+#             */
/*   Updated: 2016/11/10 10:25:14 by ndombre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char const *src)
{
	char	*ret;

	ret = (char*)ft_malloc(sizeof(*ret) * (ft_strlen(src) + 1));
	if (ret == NULL)
		return (NULL);
	ft_strcpy(ret, src);
	return (ret);
}
