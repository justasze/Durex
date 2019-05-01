/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_litoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndombre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 16:07:45 by ndombre           #+#    #+#             */
/*   Updated: 2016/11/16 20:14:05 by ndombre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_litoa_nb(long int n)
{
	size_t i;

	i = 1;
	if (n < 0)
		i++;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

static int		ft_litoa_r(char *tab, long unsigned int nu)
{
	int				i;

	i = 0;
	if (nu >= 10)
		i = ft_litoa_r(tab, nu / 10);
	tab[i] = (nu % 10) + '0';
	return (i + 1);
}

char			*ft_litoa(long int n)
{
	char				*ret;
	char				*cur;
	unsigned long int	nu;

	nu = ft_litoa_nb(n);
	ret = ft_malloc(sizeof(char) * (nu + 1));
	if (ret == NULL)
		return (NULL);
	cur = ret;
	ret[nu] = '\0';
	if (n < 0)
	{
		*cur++ = '-';
		nu = -n;
	}
	else
		nu = n;
	ft_litoa_r(cur, nu);
	return (ret);
}
