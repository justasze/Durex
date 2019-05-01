/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_incompatible_flag.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndombre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 11:24:00 by ndombre           #+#    #+#             */
/*   Updated: 2016/11/21 15:01:54 by ndombre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_incompatible_flag(t_printfpara *p)
{
	if (p->pre != 4294967295 && p->filw0 && p->conv != 'S' && p->conv != 's' &&
			p->conv != 'c' && p->conv != 'C' && p->conv != '%')
		p->filw0 = 0;
	if ((p->conv == 'o' || p->conv == 'O') &&
			p->hachtag && p->pre != 4294967295)
		p->pre++;
}
