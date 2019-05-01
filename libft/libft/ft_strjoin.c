/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndombre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/11 23:24:32 by ndombre           #+#    #+#             */
/*   Updated: 2016/11/10 10:25:30 by ndombre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *a, char const *b)
{
	char *ret;

	ret = ft_malloc(ft_strlen(a) + ft_strlen(b) + 1);
	if (ret == NULL)
		return (NULL);
	ft_strcpy(ret, a);
	return (ft_strcat(ret, b));
}
