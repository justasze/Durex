/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcstostr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndombre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 14:29:12 by ndombre           #+#    #+#             */
/*   Updated: 2016/11/23 14:53:44 by ndombre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_wcstostr(wchar_t const *n)
{
	char	*ret;
	size_t	size;
	size_t	i;

	i = 0;
	size = 0;
	while (n[i] != '\0')
		size += ft_wtoclen(n[i++]);
	ret = ft_malloc(size + 1);
	if (ret == NULL)
		return (NULL);
	ft_wcstombs(ret, n, size + 1);
	return (ret);
}

char		*ft_wcsntostr(wchar_t const *n, size_t max)
{
	char	*ret;
	size_t	size;
	size_t	i;

	i = 0;
	size = 0;
	while (n[i] != '\0')
		size += ft_wtoclen(n[i++]);
	ret = ft_malloc(size + 1);
	if (ret == NULL)
		return (NULL);
	ft_wcstombs(ret, n, max);
	return (ret);
}
