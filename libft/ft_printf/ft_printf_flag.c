/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndombre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 17:24:46 by ndombre           #+#    #+#             */
/*   Updated: 2016/11/20 14:52:26 by ndombre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_printf_flag(char **tab, t_printfpara *p)
{
	while (**tab != '\0')
	{
		if (**tab == '+')
			p->forcedispsigne = 1;
		else if (**tab == '-')
			p->ljustifi = 1;
		else if (**tab == '0')
			p->filw0 = 1;
		else if (**tab == ' ')
			p->forcespaceorsigne = 1;
		else if (**tab == '#')
			p->hachtag = 1;
		else
			break ;
		(*tab)++;
	}
}
