/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndombre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 16:07:45 by ndombre           #+#    #+#             */
/*   Updated: 2017/02/23 11:47:55 by ndombre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_itoa_nb(int n)
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

static int		ft_itoa_r(char *tab, unsigned int nu)
{
	int				i;

	i = 0;
	if (nu >= 10)
		i = ft_itoa_r(tab, nu / 10);
	tab[i] = (nu % 10) + '0';
	return (i + 1);
}

char			*ft_itoa(int n)
{
	char			*ret;
	char			*cur;
	unsigned int	nu;

	nu = ft_itoa_nb(n);
	ret = ft_malloc(sizeof(char) * (nu));
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
	ft_itoa_r(cur, nu);
	return (ret);
}
