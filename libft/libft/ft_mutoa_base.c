/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mutoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndombre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 12:08:57 by ndombre           #+#    #+#             */
/*   Updated: 2016/11/17 17:49:30 by ndombre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_mutoa_basse_p(char *ret, uintmax_t value, unsigned int base)
{
	char	*t;
	int		i;

	t = "0123456789abcdef";
	i = 0;
	if (value >= base)
		i = ft_mutoa_basse_p(ret, value / base, base);
	ret[i] = t[value % base];
	return (i + 1);
}

char			*ft_mutoa_base(uintmax_t value, int base)
{
	int		i;
	char	*ret;

	i = 0;
	if (base < 2)
		return (NULL);
	if (base > 16)
		return (NULL);
	ret = ft_malloc(100);
	while (i < 100)
		ret[i++] = 0;
	ft_mutoa_basse_p(ret, value, (unsigned int)base);
	return (ret);
}
