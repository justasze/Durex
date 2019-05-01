/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_minlen.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndombre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 17:26:26 by ndombre           #+#    #+#             */
/*   Updated: 2016/11/23 12:56:56 by ndombre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void		ft_printf_minlen(char **tab, t_printfpara *p, va_list args)
{
	int t;

	if (**tab == '*')
	{
		t = va_arg(args, int);
		if (t < 0)
		{
			t *= -1;
			p->ljustifi = 1;
		}
		p->len = t;
		(*tab)++;
		return ;
	}
	if (**tab == '+')
		(*tab)++;
	while (**tab >= '0' && **tab <= '9' && **tab != '\0')
	{
		p->len = p->len * 10 + **tab - '0';
		(*tab)++;
	}
}
