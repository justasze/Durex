/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conversion.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndombre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 18:13:44 by ndombre           #+#    #+#             */
/*   Updated: 2016/11/23 11:03:23 by ndombre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_conversion(char **tab, t_printfpara *p)
{
	if ((**tab == 'S' || **tab == 's' || **tab == 'p' || **tab == 'd' ||
				**tab == 'D' || **tab == 'i' || **tab == 'o' || **tab == 'O' ||
				**tab == 'u' || **tab == 'U' || **tab == 'x' || **tab == 'X' ||
				**tab == 'c' || **tab == 'C' || **tab == '%' || **tab == 'b' ||
				**tab == 'B' || **tab == 'r' || **tab == 'k'))
	{
		p->conv = **tab;
		(*tab)++;
	}
	p->type = 'd';
	if (p->conv == '%' || p->conv == 'C' || p->conv == 'c' ||
			p->conv == 's' || p->conv == 'S' ||
			p->conv == 'r' || p->conv == 'R' || p->conv == 'k')
		p->type = 's';
}
