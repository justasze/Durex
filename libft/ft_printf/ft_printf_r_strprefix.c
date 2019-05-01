/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_r_strprefix.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndombre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 16:59:49 by ndombre           #+#    #+#             */
/*   Updated: 2016/11/22 15:28:38 by ndombre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

char		*ft_printf_strprefix(char *str, t_printfpara *p)
{
	int d;

	d = 1;
	if (ft_strcmp(str, "0") == 0 || *str == '\0')
	{
		if (p->pre == 0 && p->type == 'd')
		{
			*str = '\0';
		}
		d = 0;
	}
	if (d && p->hachtag && (p->conv == 'x'))
		return (ft_strjoinnf("0x", str));
	if (p->conv == 'p')
		return (ft_strjoinnf("0x", str));
	if (d && p->hachtag && (p->conv == 'X'))
		return (ft_strjoinnf("0X", str));
	if (p->hachtag && (p->conv == 'o' || p->conv == 'O'))
		return (ft_strjoinnf("0", str));
	return (str);
}
