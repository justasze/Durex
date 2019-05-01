/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_time.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndombre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 14:33:26 by ndombre           #+#    #+#             */
/*   Updated: 2016/11/22 18:33:06 by ndombre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static char		*ft_printf_time_joursemaine(t_htime t)
{
	if (t.dayname == 0)
		return ("Mon");
	if (t.dayname == 1)
		return ("Tue");
	if (t.dayname == 2)
		return ("Wed");
	if (t.dayname == 3)
		return ("Thu");
	if (t.dayname == 4)
		return ("Fri");
	if (t.dayname == 5)
		return ("Sat");
	if (t.dayname == 6)
		return ("Sun");
	return ("Err");
}

int				ft_print_time(t_htime t)
{
	return (ft_printf("%s %04d-%02d-%02d %02d:%02d:%02d %+02d",
				ft_printf_time_joursemaine(t),
				t.year, t.moth, t.day,
				t.hour, t.min, t.sec,
				t.zone));
}
