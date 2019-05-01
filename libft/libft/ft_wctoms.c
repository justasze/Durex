/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wctoms.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndombre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 11:16:34 by ndombre           #+#    #+#             */
/*   Updated: 2016/11/23 15:07:11 by ndombre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_wctoms(wchar_t wc)
{
	unsigned char *tab;

	tab = ft_malloc(5);
	if (tab == NULL)
		return (NULL);
	tab[ft_wtoc(tab, wc)] = '\0';
	return ((char*)tab);
}

char	*ft_wcntoms(wchar_t wc, size_t pre)
{
	char *ret;

	ret = ft_wctoms(wc);
	if (ret == NULL)
		return (NULL);
	if (ft_strlen(ret) > pre)
	{
		ft_free(ret);
		return (ft_strdup(""));
	}
	return (ret);
}
