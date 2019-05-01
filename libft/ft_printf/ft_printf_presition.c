/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_presition.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndombre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 17:53:51 by ndombre           #+#    #+#             */
/*   Updated: 2017/07/29 14:46:27 by ndombre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_printf_presition(char **tab, t_printfpara *p, va_list args)
{
	int t;

	if (**tab != '.')
		return ;
	(*tab)++;
	if (**tab == '*')
	{
		t = va_arg(args, int);
		if (t < 0)
			t = -1;
		p->pre = t;
		(*tab)++;
		return ;
	}
	p->pre = 0;
	while (**tab >= '0' && **tab <= '9' && **tab != '\0')
	{
		p->pre = p->pre * 10 + **tab - '0';
		(*tab)++;
	}
}
