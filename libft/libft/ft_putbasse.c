/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbasse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndombre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 18:25:21 by ndombre           #+#    #+#             */
/*   Updated: 2016/11/12 18:30:40 by ndombre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_putbasse_p(unsigned int s, char *t, size_t n)
{
	if (s >= n)
		ft_putbasse_p(s / n, t, n);
	ft_putchar(t[s % n]);
}

int				ft_putbasse(unsigned int s, char *t)
{
	size_t n;

	n = ft_strlen(t);
	if (n < 2)
		return (0);
	ft_putbasse_p(s, t, n);
	return (1);
}
