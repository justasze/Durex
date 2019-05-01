/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_r_strpre.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndombre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 17:30:52 by ndombre           #+#    #+#             */
/*   Updated: 2016/11/23 14:41:54 by ndombre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	ft_printf_strpre(char *str, t_printfpara *p)
{
	if (ft_strlen(str) > p->pre && p->type == 's')
		str[p->pre] = '\0';
}
