/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mutoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndombre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 16:07:45 by ndombre           #+#    #+#             */
/*   Updated: 2016/11/17 15:38:00 by ndombre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_mutoa_nb(uintmax_t n)
{
	size_t i;

	i = 1;
	if (n == 0)
		return (2);
	while (n != 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

static int		ft_mutoa_r(char *tab, uintmax_t nu)
{
	int				i;

	i = 0;
	if (nu >= 10)
		i = ft_mutoa_r(tab, nu / 10);
	tab[i] = (nu % 10) + '0';
	return (i + 1);
}

char			*ft_mutoa(uintmax_t n)
{
	char			*ret;
	unsigned int	nu;

	nu = ft_mutoa_nb(n);
	ret = ft_malloc(sizeof(char) * (nu));
	if (ret == NULL)
		return (NULL);
	ret[nu - 1] = '\0';
	ft_mutoa_r(ret, n);
	return (ret);
}
