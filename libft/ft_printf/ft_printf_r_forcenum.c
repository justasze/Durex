/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_r_forcenum.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndombre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 17:03:00 by ndombre           #+#    #+#             */
/*   Updated: 2016/11/23 13:25:48 by ndombre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

char		*ft_printf_numsigne(char *str, t_printfpara *p)
{
	if (p->type == 's' || p->conv == 'u' || p->conv == 'U' ||
			p->conv == 'o' || p->conv == 'O' ||
			p->conv == 'x' || p->conv == 'X' ||
			p->conv == 'b' || p->conv == 'B' || p->conv == 'p')
		return (str);
	if (p->forcedispsigne)
	{
		if (*str != '-')
			if ((str = ft_strjoinnf("+", str)) == NULL)
				return (NULL);
	}
	else if (p->forcespaceorsigne)
	{
		if (*str != '-')
			if ((str = ft_strjoinnf(" ", str)) == NULL)
				return (NULL);
	}
	return (str);
}
