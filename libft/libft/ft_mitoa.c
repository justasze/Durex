/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndombre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 16:07:45 by ndombre           #+#    #+#             */
/*   Updated: 2016/11/17 18:06:01 by ndombre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_mitoa_nb(intmax_t n)
{
	size_t i;

	i = 1;
	if (n < 0)
		i++;
	if (n == 0)
		return (2);
	while (n != 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

static int		ft_mitoa_r(char *tab, uintmax_t nu)
{
	int				i;

	i = 0;
	if (nu >= 10)
		i = ft_mitoa_r(tab, nu / 10);
	tab[i] = (nu % 10) + '0';
	return (i + 1);
}

char			*ft_mitoa(intmax_t n)
{
	char			*ret;
	char			*cur;
	uintmax_t		nu;

	nu = ft_mitoa_nb(n);
	ret = ft_malloc(sizeof(char) * nu);
	if (ret == NULL)
		return (NULL);
	cur = ret;
	ret[nu - 1] = '\0';
	if (n < 0)
	{
		*cur++ = '-';
		nu = -n;
	}
	else
		nu = n;
	ft_mitoa_r(cur, nu);
	return (ret);
}
