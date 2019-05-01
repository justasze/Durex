/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_modlen.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndombre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 17:58:30 by ndombre           #+#    #+#             */
/*   Updated: 2016/11/17 11:06:59 by ndombre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printf_modlen_h(char **tab, t_printfpara *p)
{
	if (**tab == 'h')
	{
		(*tab)++;
		p->h = 'h';
		if (**tab == 'h')
		{
			p->h = 's';
			(*tab)++;
		}
		return (1);
	}
	return (0);
}

void		ft_printf_modlen(char **tab, t_printfpara *p)
{
	if (ft_printf_modlen_h(tab, p))
		;
	else if (**tab == 'l')
	{
		(*tab)++;
		p->h = 'l';
		if (**tab == 'l')
		{
			p->h = 'e';
			(*tab)++;
		}
	}
	else if (**tab == 'j')
	{
		p->h = 'j';
		(*tab)++;
	}
	else if (**tab == 'z')
	{
		p->h = 'z';
		(*tab)++;
	}
}
